#include "RenderWidget.h"

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

void RenderWidget::show()
{
    
}


} // namespace myGUI