#ifndef CORE_H
#define CORE_H

#include "../utils/utils.h"
#include "../utils/message.h"
#include "typesprivate.h"
#include "AbstractController.h"
#include <queue>

class RenderEngine;

namespace PhysEngine{class PhysEngine;}
namespace myGUI{class RenderWidget;}

namespace Core
{
    


class Core
    : public AbstractController
{
    friend class myGUI::RenderWidget;
    bool m_isRunning;
    
    RenderEngine* m_pRenderEngine;
    PhysEngine::PhysEngine* m_pPhysEngine;
    myGUI::RenderWidget* m_pRenderWidget;
    
 
    
    Core();
    void doWork(std::shared_ptr<AbstractController::Message>)override;
public:
  int exec();
  myGUI::RenderWidget* RenderWidget();
SINGLETON(Core)
//NONCOPYABLE(Core)  
};

class UpdateMessage:public AbstractController::Message
{
    MESSAGE(ControllerMessageType::Update)
public:
    UpdateMessage(uint64_t time_, uint64_t dt_)
        : AbstractController::Message(messageType())
        , time(time_)
        , dt(dt_)
    {}
public:
    uint64_t time,dt;
};

class RenderWidgetWasInitializedMessage: public AbstractController::Message
{
    MESSAGE(ControllerMessageType::RenderWidgetWasInitialized)
public:
    RenderWidgetWasInitializedMessage()
        : AbstractController::Message(messageType())
    {}
private:
};

class RenderWidgetWasUpdatedMessage:public AbstractController::Message
{
    MESSAGE(ControllerMessageType::RenderWidgetWasUpdated)
public:
    RenderWidgetWasUpdatedMessage(uint64_t time_, uint64_t dt_)
        : AbstractController::Message(messageType())
	, time(time_)
	, dt(dt_)
    {}
public:
    uint64_t time, dt;

};

class RenderWidgetWasClosedMessage: public AbstractController::Message
{
    MESSAGE(ControllerMessageType::RenderWidgetWasClosed)
public:
    RenderWidgetWasClosedMessage()
        : AbstractController::Message(messageType())
    {}
private:
};




} // namespace Core
#endif // CORE_H
