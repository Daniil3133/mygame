#ifndef RENDER_WIDGET_H
#define RENDER_WIDGET_H

#include <SFML/Graphics.hpp>
//namespace sf{ class RenderWindow;}
#include "../debug.h"

namespace myGUI
{
class RenderWidget
{
    sf::RenderWindow* m_pRenderWindow;
    sf::Text* TextDebug;
    //static sf::Font font;
public:
    RenderWidget();
    void init();
    void show();
private:
    bool m_isVisible;
    
};
} // namespace myGUI
#endif // RENDER_WIDGET_H