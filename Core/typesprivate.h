#ifndef TYPESPRIVATE_H
#define TYPESPRIVATE_H

#include "../utils/enumclass.h"
#include <inttypes.h>

namespace Core
{

ENUMCLASS(ControllerMessageType,uint32_t
         ,RenderWidgetWasInitialized
         ,RenderWidgetWasUpdated
         ,RenderWidgetWasClosed
         ,Update)

} // namespace Core
#endif // TYPESPRIVATE_H