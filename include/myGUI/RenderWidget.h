#ifndef RENDER_WIDGET_H
#define RENDER_WIDGET_H


#include <SFML/Graphics.hpp>
//namespace sf{ class RenderWindow;}
#include <Core/AbstractController.h>
#include <cstdint>
#include <utils/message.h>
#include <Core/debug.h>

namespace Core{
	class Core;
}
namespace myGUI
{
class RenderWidget
{
    friend class Core::Core;
    sf::RenderWindow* m_pRenderWindow;
    sf::Text* TextDebug;
    //static sf::Font font;
public:
    RenderWidget();
    void init();
    void setTitle(const char*);
    void setSize(uint w, uint h);
    void show();
private:
    void m_update(uint64_t time, uint64_t dt);
    bool m_isVisible;
    
};




} // namespace myGUI
#endif // RENDER_WIDGET_H
