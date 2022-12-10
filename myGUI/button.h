#ifndef BUTTON_H
#define BUTTON_H

#include "widget.h"


namespace myGUI
{


typedef void(*EventFunc)(void);

class button
    : public widget
{
    char m_text[40];
    EventFunc m_onClick = nullptr;
    EventFunc m_onBtnDown = nullptr;
    EventFunc m_onBtnUp = nullptr;
public:
    button(widget* parent = nullptr);
    void setText(const char*);
    const char* text()const;
    void setonClick(EventFunc);
    void setonBtnDown(EventFunc);
    void setonBtnUp(EventFunc);
};



} // namespace myGUI

#endif // BUTTON_H