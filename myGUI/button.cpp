#include <myGUI/button.h>
#include <cstring>

#define defaultButtonText ("Button")

namespace myGUI
{

button::button(widget* parent)
    : widget(parent)
    , m_text(defaultButtonText)
{
}

void button::setText(const char* str)
{
    strncpy(m_text,str,40);
}
const char* button::text()const
{
    return m_text;
}

void button::setonClick(EventFunc f)
{
    m_onClick = f;
}
void button::setonBtnDown(EventFunc f)
{
    m_onBtnDown = f;
}
void button::setonBtnUp(EventFunc f)
{
    m_onBtnUp = f;
}

} // namespace myGUI
