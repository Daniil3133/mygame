#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <SFML/Graphics.hpp>
#include  "../vec2.h"


namespace myGUI
{
    
class object
{
public:
    virtual void update()=0;
    virtual void draw(sf::RenderTarget& t)=0;
};


class widget
    : public object
{
    sf::RectangleShape m_rectsh;
    vec2 m_pos;
    vec2 m_size;
    std::vector<widget*> m_childWidgets;
    widget* m_parent;
    bool m_isVisible;
public:
    void setPos(const vec2&);
    const vec2& pos()const;
    vec2 pos();
    void setSize(const vec2&);
    const vec2& size()const;
    vec2 size();
    widget(widget* parent = nullptr);
    void setParent(widget*);
    void update();
    void draw(sf::RenderTarget& t);
    virtual void show();
};

} // namespace myGUI

#endif // WIDGET_H