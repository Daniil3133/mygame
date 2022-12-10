#include "AbstractController.h"


namespace Core
{

void AbstractController::sendMessage(std::shared_ptr<Message> msg)
{
    m_messages.push(msg);
}
void AbstractController::process()
{
    while(!m_messages.empty())
    {
        auto msg = m_messages.front();
        m_messages.pop();
        doWork(msg);
    }
}


void AbstractController::doWork(std::shared_ptr<Message> msg)
{}

AbstractController::Message::Message(ControllerMessageType type)
    :m_type(type)
{}
ControllerMessageType AbstractController::Message::type()const
{
    return m_type;
}

} // namespace Core