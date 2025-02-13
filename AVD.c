#include <stdint.h>
#include <UserCAPI.h>
#include <UserCEvents.h>

#include "mcm.h"
#include "init.h"
#include "mask.h"
#include "cycle.h"
#include "vartab.h"
#include "objtab.h"
#include "keyboard.h"

int8_t mcmValue = 0;
int8_t mcmState = 0;
int8_t pressedButton = 0;
int32_t controlCycleCounter = 0;

int UserCInit(uint32_t initFlags) {
  MaskPresset();
  MaskConnection();
 
  mcmValue = ControlCInit(mcmValue);
  return 0;
}

void UserCCycle(uint32_t evtc, tUserCEvt * evtv) {
  ClickProcessing();
  controlCycleCounter = ControlCCycle(mcmValue, controlCycleCounter);
}

void UserCTimer(void) {
  
}
