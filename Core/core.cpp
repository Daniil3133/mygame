#include <Core/Core.h>

#include <memory>
#include <myGUI/RenderWidget.h>



namespace Core
{

Core::Core()
	: m_pRenderWidget(new myGUI::RenderWidget)
{}

void Core::doWork(std::shared_ptr<AbstractController::Message> msg)
{
    switch(msg->type())
    {
        case ControllerMessageType::Update:
	{
	    uint64_t time,dt;
	    auto msg = std::make_shared<RenderWidgetWasUpdatedMessage>(time, dt);
	    sendMessage(*(std::shared_ptr<Message>*)&msg);
	    process();
            break;
	}
        case ControllerMessageType::RenderWidgetWasInitialized:
	{
	    
            break;
	}
        case ControllerMessageType::RenderWidgetWasUpdated:
	{
	    auto updmsg = msg_cast<RenderWidgetWasUpdatedMessage>(msg);
	    uint64_t time = updmsg->time;
            uint64_t dt = updmsg->dt;
	    m_pRenderWidget->m_update(time, dt);
            break;
	}
        case ControllerMessageType::RenderWidgetWasClosed:
            break;
    }
}

int Core::exec()
{
    m_isRunning=true;

	while(m_isRunning)
	{
	    uint64_t time,dt;
	    auto msg = std::make_shared<UpdateMessage>(time,dt);
	    sendMessage(*(std::shared_ptr<Message>*)&msg);
	    process();
	    
	}
	return 0;
}

myGUI::RenderWidget* Core::RenderWidget()
{
    return m_pRenderWidget;
}

} // namespace Core
