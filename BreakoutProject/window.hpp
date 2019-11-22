#pragma once

#include <string.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Class for handling the window used for the game
class Window {
public:

	enum WindowBound { LEFT, TOP, RIGHT, BOTTOM};

	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();
	void BeginDraw(); // Clear the window.
	void EndDraw(); // Display the changes.
	void Update();  // Handle Window Events
	bool IsDone() const;  // return m_isDone
	bool IsFullscreen(); // return m_isFullScreen
	bool IsPendingDraw() const;
	bool WithinWindow(const sf::Vector2f&) const;
	sf::Vector2u GetWindowSize();
	//float GetWindowBound(WindowBound) const;
	void ToggleFullscreen(); // Boolean flips m_isFullScreen and recreates window based on resulting boolean value
	void Draw(sf::Drawable& l_drawable); // simple sf::RenderWindow::draw wrapper
	//void ToggleKeepMouseInWindow(bool _flag) { m_keepMouseInWindow = _flag; }

	void			   setMousePosition(const sf::Vector2i& _position) { sf::Mouse::setPosition(_position, m_window); }
	const sf::Vector2f getMousePosition() const { return m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)); }
	const sf::Vector2f windowSizeInPixel() const { return sf::Vector2f(m_window.getSize()); }

private: // Private Methods
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy(); // Closes window
	void Create(); // creates instance of sf::RenderWindow based on m_isFullscreen value


private: // Private Data
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
	bool m_pendingDraw;
	//bool m_keepMouseInWindow;
};
