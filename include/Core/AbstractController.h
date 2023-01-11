#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include <inttypes.h>
#include <memory>
#include <queue>

namespace Core
{

enum class ControllerMessageType: uint32_t;

class AbstractController
{
public:
    class Message;
    void sendMessage(std::shared_ptr<Message>);
    void process();
protected:
    virtual ~AbstractController()=default;
    virtual void doWork(std::shared_ptr<Message>);
private:
    std::queue<std::shared_ptr<Message>> m_messages;
};

class AbstractController::Message
{
    ControllerMessageType m_type;
public:
    Message(ControllerMessageType);
    ControllerMessageType type()const;
};

template <class T>
inline std::shared_ptr<T> msg_cast(std::shared_ptr<AbstractController::Message> msg) {
    return (msg->type() == T::messageType()) ? std::static_pointer_cast<T>(msg) : nullptr;
}

} // namespace Core
#endif // ABSTRACTCONTROLLER_H