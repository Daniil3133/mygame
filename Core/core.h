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
    bool m_isRunning;
    
    RenderEngine* m_pRenderEngine;
    PhysEngine::PhysEngine* m_pPhysEngine;
    myGUI::RenderWidget* m_pRenderWidget;
    
 
    
    Core()=default;
    void doWork(std::shared_ptr<AbstractController::Message>)override;
public:
  int exec();
  myGUI::RenderWidget* RenderWidget();
SINGLETON(Core)
//NONCOPYABLE(Core)  
};

class UpdateMessage: AbstractController::Message
{
    MESSAGE(ControllerMessageType::Update)
public:
    UpdateMessage(uint64_t time_, uint64_t dt_)
        : AbstractController::Message(messageType())
        , time(time_)
        , dt(dt_)
    {}
private:
    uint64_t time,dt;
};

} // namespace Core
#endif // CORE_H