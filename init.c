#include <stdint.h>
#include <UserCAPI.h>
#include <UserCEvents.h>

#include "mcm.h"
#include "vartab.h"
#include "objtab.h"

int32_t ControlCInit(int32_t mcmValue) {
  mcmValue = MCM_InitDevice(MCMTYPE_MCM200, 0, 0, 230, 231);
  MCM_SetPolling(mcmValue, 500);
  return mcmValue;
}
