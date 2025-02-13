#include <stdint.h>
#include <UserCAPI.h>
#include <UserCEvents.h>

#include "vartab.h"
#include "objtab.h"

void CheckAndAdjustValue(void) {
  // Минимальные и максимальные значения для case 2 (Engine)
  const uint16_t minValuesEngine[] = {600, 1500, 5, 50, 50};
  const uint16_t maxValuesEngine[] = {1200, 2000, 20, 90, 90};
  const uint8_t engineCellsCount = sizeof(minValuesEngine) / sizeof(minValuesEngine[0]);

  // Минимальные и максимальные значения для case 3 (Pump)
  const uint16_t minValuesPump[] = {100, 1000, 1, 5, 0, 40, 90, 2, 6};
  const uint16_t maxValuesPump[] = {1000, 2900, 2, 10, 5, 50, 110, 4, 12};
  const uint8_t pumpCellsCount = sizeof(minValuesPump) / sizeof(minValuesPump[0]);

  // Минимальные и максимальные значения для case 10 (Technical)
  const uint16_t minValuesTecnical[] = {50, 50};
  const uint16_t maxValuesTecnical[] = {100, 100};
  const uint8_t tecnicalCellsCount = sizeof(minValuesTecnical) / sizeof(minValuesTecnical[0]);

  // Проверка и корректировка значений для Engine (case 2)
  for (uint8_t i = 0; i < engineCellsCount; i++) {
    uint16_t currentValue = GetVar(HDL_MASK_ENGINE_VALUE_1 + i);
    if (currentValue < minValuesEngine[i] || currentValue > maxValuesEngine[i]) {
      SetVar(HDL_MASK_ENGINE_VALUE_1 + i, minValuesEngine[i]);
    }
  }

  // Проверка и корректировка значений для Pump (case 3)
  for (uint8_t i = 0; i < pumpCellsCount; i++) {
    uint16_t currentValue = GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + i);
    if (currentValue < minValuesPump[i] || currentValue > maxValuesPump[i]) {
      SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + i, minValuesPump[i]);
    }
  }

  // Проверка и корректировка значений для Tecnical (case 10)
  for (uint8_t i = 0; i < tecnicalCellsCount; i++) {
    uint16_t currentValue = GetVar(HDL_MASK_TECHNICAL_VALUE_0 + i);
    if (currentValue < minValuesTecnical[i] || currentValue > maxValuesTecnical[i]) {
      SetVar(HDL_MASK_TECHNICAL_VALUE_0 + i, minValuesTecnical[i]);
    }
  }
}

void MaskConnection(void) {
  for(uint8_t i = 10; i == 0; i--){
    MaskOn(i);
  } PrioMaskOn(6);
}

void MaskPresset(void) {
  // Task
  SetVar(HDL_MASK_TASK_TURNOVER_TEXT, 0x0001002C);
  SetVar(HDL_MASK_TASK_PRESSURE_TEXT, 0x00010028);
  
  SetVar(HDL_MASK_TASK_PRESSURE_TEXT_CENTER, 0x00000000);
  SetVar(HDL_MASK_TASK_TURNOVER_TEXT_CENTER, 0x00000028);
  
  // Engine
  SetVar(HDL_MASK_ENGINE_SELECTED_OBJECT_1, 0x0000000A);
  for(uint8_t i = 1; i < 6; i++) {
    SetVar(HDL_MASK_ENGINE_SELECTED_OBJECT_1 + i, 0x00000000);
  }
  
  SetVar(HDL_MASK_ENGINE_VALUE_1, GetVar(HDL_MASK_ENGINE_VALUE_1));
  SetVar(HDL_MASK_ENGINE_VALUE_2, GetVar(HDL_MASK_ENGINE_VALUE_2));
  SetVar(HDL_MASK_ENGINE_VALUE_3, GetVar(HDL_MASK_ENGINE_VALUE_3));
  SetVar(HDL_MASK_ENGINE_VALUE_4, GetVar(HDL_MASK_ENGINE_VALUE_4));
  SetVar(HDL_MASK_ENGINE_VALUE_5, GetVar(HDL_MASK_ENGINE_VALUE_5));

  SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MIN, GetVar(HDL_MASK_ENGINE_VALUE_1));
  SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MAX, GetVar(HDL_MASK_ENGINE_VALUE_2));
  
  // Pump
  SetVar(HDL_MASK_PUMP_SELECTED_OBJECT_1, 0x0000000A);
  for(uint8_t i = 1; i < 8; i++) {
    SetVar(HDL_MASK_PUMP_SELECTED_OBJECT_1 + i, 0x00000000);
  }
  
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 0, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 0));
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 1, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 1));
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 2, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 2));
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 3, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 3));
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 4, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 4));
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 5, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 5));
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 6, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 6));
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 7, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 7));
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 8, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 8));
  
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 0, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 0));
  SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 1, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + 1));
  
  for(uint8_t i = 0; i < 9; i++) {
    SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + i, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + i));
  }
  
  // Technical
  SetVar(HDL_MASK_TECHNICAL_GRAY_0 + 0, 0x0000000A);
  SetVar(HDL_MASK_TECHNICAL_GRAY_0 + 1, 0x00000000);
  
  // Предустановки
  CheckAndAdjustValue();
}

