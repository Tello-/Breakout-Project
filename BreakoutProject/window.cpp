#include "window.hpp"

Window::Window() { Setup("Window", sf::Vector2u(1600, 900)); }
Window::Window(const std::string& l_title,
	const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
	//m_window.setFramerateLimit(60); // take out after debug
	
}
Window::~Window() { Destroy(); }

void Window::Setup(const std::string& l_title,
	const sf::Vector2u& l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	m_pendingDraw = false;
	Create();
}

void Window::Create() {
	auto style = (m_isFullscreen ? sf::Style::Fullscreen
		: sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 },
		m_windowTitle, style);

	m_window.setMouseCursorVisible(false);
}
void Window::Destroy() {
	m_window.close();
}

void Window::Update() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_isDone = true;
		}
		else if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}

void Window::ToggleFullscreen() {
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
void Window::EndDraw() 
{ 
	m_window.display(); 
	m_pendingDraw = false; }

bool Window::IsDone() const { return m_isDone; }
bool Window::IsFullscreen() { return m_isFullscreen; }
bool Window::IsPendingDraw() const
{
	return m_pendingDraw;
}
bool Window::WithinWindow(const sf::Vector2f& _position) const
{

	bool isWithinWindow = false;

	if (_position.x >= 0.f &&
		(_position.x <= windowSizeInPixel().x) &&
		(_position.y >= 0.f) &&
		(_position.y < windowSizeInPixel().y))
	{
		isWithinWindow = true;
	}
	else
	{
		isWithinWindow = false;
	}


	return isWithinWindow;
}
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }


void Window::Draw(sf::Drawable& l_drawable) {
	m_window.draw(l_drawable);
	m_pendingDraw = true;
}