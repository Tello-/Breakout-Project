#include "BreakoutEngine.hpp"

BreakoutEngine::BreakoutEngine()
	: m_window{ "Breakout", DEFAULT_WINDOW_DIMENSIONS },
	m_gameClock{ 60.f },
	m_textureManager{ TEXTURE_BATCH },
	m_paddle{ m_textureManager.retrieveTexture(textures::TextureID::PADDLE), DEFAULT_PADDLE_POSITION },
	m_background{ m_textureManager.retrieveTexture(textures::TextureID::BACKGROUND) },
	m_ball{ m_textureManager.retrieveTexture(textures::TextureID::BALL) }
{
	m_window.setMousePosition(sf::Vector2i{ DEFAULT_PADDLE_POSITION });
	m_ball.setVelocity(DEFAULT_BALL_VELOCITY);

}

void BreakoutEngine::run()
{
	while (!m_isGameOver && !m_window.IsDone())
	{
		m_window.Update(); // Update window events.
		m_gameClock.restartClock();
		m_elapsedTime = m_gameClock.getElapsed();

		handleInput();
		if (m_gameClock.readyForTick()) // readyForTick is true when elapsed time exceeds frametime
		{
			m_gameClock.tick();
			onTick();
		
		}

		
		render();
	}
	std::cout << "Score: " << m_score << std::endl;
}

void BreakoutEngine::handleInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (m_paddle.isSticky())
			m_paddle.setSticky(false);
	}

}

void BreakoutEngine::onTick()
{
	
	if (m_paddle.isSticky())
	{
		pAttachBallToPaddle();
	}
	else
	{
		m_ball.onTick(m_elapsedTime);
	}
	m_paddle.onTick(sf::Vector2f{ m_window.getMousePosition().x, DEFAULT_PADDLE_POSITION.y });
	pHandleCollisions();

#ifdef DEBUG_ONLY_CODE
	/*system("cls");
	std::cout << "Paddle Position: " << m_paddle.getPosition().x << ", " << m_paddle.getPosition().y
		<< "\t\tBall Position: " << m_ball.getPosition().x << ", " << m_ball.getPosition().y << std::endl;*/
#endif // DEBUG_ONLY_CODE

}

void BreakoutEngine::render() {
	m_window.BeginDraw(); // Clear.

	m_window.Draw(m_background);
	m_window.Draw(m_paddle);
	m_window.Draw(m_ball);
	m_window.EndDraw(); // Display.
}

void BreakoutEngine::pAttachBallToPaddle()
{
	sf::Vector2f ballPosition;
	ballPosition.x = m_paddle.getPosition().x;
	ballPosition.y = m_paddle.getPosition().y - (m_paddle.getDimensions().y / 2.f) - (m_ball.getDimensions().y / 2.f);
	m_ball.setPosition(ballPosition);
}

void BreakoutEngine::pHandleCollisions()
{
	pKeepPaddleWithinWindow();
	if (!m_paddle.isSticky())
	{
		pKeepBallWithinWindow();
		if (m_paddle.getCollisionBox() == m_ball.getCollisionBox()) // note:  currently only handles ball hitting paddle on top
		{
			
			// This Section of If/Else blocks determines which direction to reflect the ball off of the paddle
			//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
			if (m_ball.getPosition().x < m_paddle.getPosition().x)
			{
				if(m_ball.getVelocity().x > 0)
				m_ball.setVelocity(sf::Vector2f{ m_ball.getVelocity().x * -1.f, m_ball.getVelocity().y * -1.f });
				else
					m_ball.setVelocity(sf::Vector2f{ m_ball.getVelocity().x, m_ball.getVelocity().y * -1.f });
			}
			else if (m_ball.getPosition().x > m_paddle.getPosition().x)
			{
				if (m_ball.getVelocity().x < 0)
					m_ball.setVelocity(sf::Vector2f{ m_ball.getVelocity().x * -1.f, m_ball.getVelocity().y * -1.f });
				else
					m_ball.setVelocity(sf::Vector2f{ m_ball.getVelocity().x, m_ball.getVelocity().y * -1.f });
			}
			//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		}

		
	}
}

void BreakoutEngine::pKeepPaddleWithinWindow()
{
	if (m_paddle.getHandlePosition(IEntity::Handle::MID_LEFT).x <= 0.f)
	{
		
		m_paddle.setPosition(sf::Vector2f{ 0.f + m_paddle.getHalfDimensions().x, m_paddle.getPosition().y });
	}
	if (m_paddle.getPosition().x + m_paddle.getHalfDimensions().x >= m_window.windowSizeInPixel().x)
	{
		m_paddle.setPosition(sf::Vector2f{ m_window.windowSizeInPixel().x - m_paddle.getHalfDimensions().x, m_paddle.getPosition().y });
	}


}
				
void BreakoutEngine::pKeepBallWithinWindow()
{
	if ((m_ball.getHandlePosition(IEntity::Handle::MID_LEFT).x < 0.f) ||
		(m_ball.getHandlePosition(IEntity::Handle::MID_RIGHT).x >= m_window.windowSizeInPixel().x))
	{
		m_ball.setVelocity(sf::Vector2f{ m_ball.getVelocity().x * -1, m_ball.getVelocity().y });
	}
	if (m_ball.getHandlePosition(IEntity::Handle::TOP_CENTER).y < 0.f)
	{
		m_ball.setVelocity(sf::Vector2f{ m_ball.getVelocity().x,  m_ball.getVelocity().y * -1 });
	}
	if(m_ball.getHandlePosition(IEntity::Handle::BOTTOM_CENTER).y >= m_window.windowSizeInPixel().y)
	{
		pSignalGameOver();
	}
}


