#include <stdint.h>
#include <UserCAPI.h>
#include <UserCEvents.h>

#include "mcm.h"
#include "vartab.h"
#include "objtab.h"

uint32_t ControlCCycle(uint32_t mcmValue, uint32_t controlCycleCounter) {
  int32_t mcmState = MCM_GetActiveStatus(mcmValue);
  
  if(controlCycleCounter < 500) {
    // SetVar(HDL_MASK_START_MCM_INDICATOR_RED, 0x0000000A);
    // SetVar(HDL_MASK_START_MCM_INDICATOR_GREEN, 0x00000000);
  }
  else if(mcmState && controlCycleCounter > 600){
    // SetVar(HDL_MASK_START_MCM_DETECT_TEXT, 0x00000028);
    // SetVar(HDL_MASK_START_MCM_INDICATOR_RED, 0x00000000);
    // SetVar(HDL_MASK_START_MCM_INDICATOR_GREEN, 0x00000008);
  }
  else {
    // SetVar(HDL_MASK_START_MCM_INDICATOR_RED, 0x0000000A);
    // SetVar(HDL_MASK_START_MCM_INDICATOR_GREEN, 0x00000000);
  } 
  
  // SetVar(HDL_MASK_START_CONTROL_CYCLE_COUNTER, controlCycleCounter++);
  return controlCycleCounter;
}
