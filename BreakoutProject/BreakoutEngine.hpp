#pragma once

#include <vector>
#include <set>
#include "window.hpp"
#include "gameclock.hpp"
#include "texturemanager.hpp"
#include "paddle.hpp"
#include "background.hpp"
#include "ball.hpp"
#include "brick.hpp"
//#include "collisionhandler.hpp"
//#include "brickblock.hpp"

#define DEBUG_ONLY_CODE

typedef std::pair<std::string, textures::TextureID> TEXTURE_PAIR;
const std::vector < TEXTURE_PAIR > TEXTURE_BATCH
{
	TEXTURE_PAIR{"Res/Sprites/paddleTexture.png", textures::TextureID::PADDLE},
	TEXTURE_PAIR{"Res/Sprites/mountainTexture.png", textures::TextureID::BACKGROUND},
	TEXTURE_PAIR{"Res/Sprites/ballTexture.png", textures::TextureID::BALL},
	TEXTURE_PAIR{"Res/Sprites/brickTexture.png", textures::TextureID::BRICK}
};


class BreakoutEngine
{
public:
	BreakoutEngine();
	~BreakoutEngine() {}

	void							run();
	

private:
	
	void							handleInput();
	void							onTick();
	void							render();
	const Window& getWindow() const { return m_window; }


	bool							m_isGameOver{ false };
	unsigned int					m_score{ 0 };

	const sf::Vector2f				DEFAULT_PADDLE_POSITION{ sf::Vector2f{200.f, 250.f} };
	const sf::Vector2f				DEFAULT_BALL_POSITION{ sf::Vector2f{0.f, 0.f} };
	const sf::Vector2f				DEFAULT_BALL_VELOCITY{ sf::Vector2f{75.f, -75.f} };
	const sf::Vector2u				DEFAULT_WINDOW_DIMENSIONS{ sf::Vector2u{400, 300} };
	static const int				DEFAULT_COL_COUNT{ 10};
	static const int 				DEFAULT_ROW_COUNT{ 5 };


	Window							m_window;
	GameClock						m_gameClock;
	sf::Time						m_elapsedTime;
	textures::TextureManager		m_textureManager;
	Background						m_background;
	Paddle							m_paddle;
	Ball							m_ball;

	void							pAttachBallToPaddle();
	
	void							pHandleCollisions();
	void							pKeepPaddleWithinWindow();
	void							pKeepBallWithinWindow();
	void							pSignalGameOver() { m_isGameOver = true; }
	   	 
};


/* TODO: Figure out how to detect which side of a brick the ball is colliding with. This is important to know because it will help determine which direction to reflect the ball.


*) If ball and brick are colliding
		

*/