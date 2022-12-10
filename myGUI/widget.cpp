#include "widget.h"


namespace myGUI
{

widget::widget(widget* parent)
    : m_pos({0,0})
     ,m_size({100,100})
{
    m_parent = parent;
}

void widget::setParent(widget* parent)
{
    if(parent)
    {
        parent->m_childWidgets.push_back(this);
        m_parent = parent;
    }
}

void widget::setPos(const vec2& v){ m_pos = v; }
const vec2& widget::pos()const{ return m_pos; }
vec2 widget::pos(){ return m_pos; }
void widget::setSize(const vec2& v){ m_size = v; }
const vec2& widget::size()const{ return m_size; }
vec2 widget::size(){ return m_size; }
void widget::update()
{
    vec2 ppos;
    if(m_parent)
    {
        ppos = m_parent->pos();
    }
    m_rectsh.setPosition(ppos.vecsf() + m_pos.vecsf());
    m_rectsh.setSize(m_size.vecsf());
}
void widget::draw(sf::RenderTarget& t)
{
    if(m_isVisible)
        t.draw(m_rectsh);
}
void widget::show(){ m_isVisible = true; }

} // namespace myGUI