#include "core.h"

#include "myGUI/RenderWidget.h"



namespace Core
{

void Core::doWork(std::shared_ptr<AbstractController::Message> msg)
{
    switch(msg->type())
    {
        case ControllerMessageType::Update:
            break;
        case ControllerMessageType::RenderWidgetWasInitialized:
            break;
        case ControllerMessageType::RenderWidgetWasUpdated:
            break;
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
	    //auto msg = std::make_shared<UpdateMessage>(time,dt);
	    //sendMessage(*(std::shared_ptr<Message>*)&msg);
	    //process();
	    
	}
	return 0;
}

myGUI::RenderWidget* Core::RenderWidget()
{
    return m_pRenderWidget;
}

} // namespace Core