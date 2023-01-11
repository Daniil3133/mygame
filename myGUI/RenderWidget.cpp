#include <myGUI/RenderWidget.h>

#include <SFML/Graphics.hpp>



namespace myGUI
{

//sf::Font RenderWidget::font;

RenderWidget::RenderWidget()
    : m_pRenderWindow(new sf::RenderWindow(sf::VideoMode(1080,2160),""))
    ,TextDebug(new sf::Text)
{
    m_isVisible=(false);
}

void RenderWidget::init()
{
	//font.loadFromFile("/system/fonts/DroidSansMono.ttf");
	//TextDebug.setFont(font);
	//TextDebug->setPosition({300,100});
	//TextDebug.setCharacterSize(30);
	//TextDebug.setFillColor(sf::Color::Red);
	debug().setText(TextDebug);
	// TODO; настройка дебага
}

void RenderWidget::setTitle(const char* title)
{
	m_pRenderWindow->setTitle(title);
}

void RenderWidget::setSize(uint w, uint h)
{
	m_pRenderWindow->setSize({w,h});
}

void RenderWidget::show()
{
    
}

void RenderWidget::m_update(uint64_t time, uint64_t dt)
{
	sf::Event e;
	while(m_pRenderWindow->pollEvent(e))
	{
		
		if(e.type == sf::Event::Closed)
			m_pRenderWindow->close();
	}
	m_pRenderWindow->display();
}

} // namespace myGUI
