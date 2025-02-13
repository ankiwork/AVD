#include <stdint.h>
#include <UserCAPI.h>
#include <UserCEvents.h>

#include "vartab.h"
#include "objtab.h"

#define PASSWORD_LENGTH 4
#define INITIAL_PASSWORD 0000
#define INITIAL_PASSWORD_SETTINGS 0000

uint8_t stepValue = 0;

uint16_t originalValue = 0;
uint8_t selectedFlag = 0;
uint8_t selectedObjectFlag = 0;
uint8_t selectedObjectValue = 0;

uint16_t originalValueEngine = 0;
uint8_t selectedFlagEngine = 0;
uint8_t selectedObjectFlagEngine = 0;
uint8_t selectedObjectValueEngine = 0;

uint16_t originalValueTechnical = 0;
uint8_t selectedFlagTechnical = 0;
uint8_t selectedObjectFlagTechnical = 0;
uint8_t selectedObjectValueTechnical = 0;

static uint8_t taskValue = 0;
static uint8_t passwordPage = 0;

static uint8_t passwordNumber = 0;
static int passwordStorage[PASSWORD_LENGTH] = {0};
static const int initialPassword = INITIAL_PASSWORD;

static uint8_t passwordNumberSettings = 0;
static int passwordStorageSettings[PASSWORD_LENGTH] = {0};
static const int initialPasswordSettings = INITIAL_PASSWORD_SETTINGS;

void ClickProcessing(void) {
  switch(GetCurrentMaskShown()){
    // Workspace
    case 0: {
      if(IsKeyPressedNew(1)) {       // F1
        PrioMaskOn(7);
        if(GetVar(HDL_PRESSURE_OR_TURNOVER) == 0) {
          SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MIN, GetVar(HDL_MASK_ENGINE_VALUE_1));
          SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MAX, GetVar(HDL_MASK_ENGINE_VALUE_2));
          if(GetVar(HDL_MASK_TASK_VALUES) < GetVar(HDL_MASK_ENGINE_VALUE_1) || GetVar(HDL_MASK_TASK_VALUES) > GetVar(HDL_MASK_ENGINE_VALUE_2)) {
            SetVar(HDL_MASK_TASK_VALUES, GetVar(HDL_MASK_ENGINE_VALUE_1));
          }
        } else if(GetVar(HDL_PRESSURE_OR_TURNOVER) == 1) {
          SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MIN, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN));
          SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MAX, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MAX));
          if(GetVar(HDL_MASK_TASK_VALUES) < GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN) || GetVar(HDL_MASK_TASK_VALUES) > GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MAX)) {
            SetVar(HDL_MASK_TASK_VALUES, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN));
          }
        }
      }
      
      else if(IsKeyPressedNew(2)) {  // F2

      }
      
      else if(IsKeyPressedNew(3)) {  // F3
      
      }
      
      else if(IsKeyPressedNew(4)) {  // F4
        PrioMaskOn(8);
      }
      
      else if(IsKeyPressedNew(5)) {  // <-
        
      }
      
      else if(IsKeyPressedNew(6)) {  // ->
        
      }
      
      else if(IsKeyPressedNew(7)) {  // OK
       
      }
      
      else if(IsKeyPressedNew(8)) {  // ESC
      
      }
    } break;
    
    // Password
    case 1: {
      if (passwordNumber < 4) {
        if(IsKeyPressedNew(1)) {       // F1
          PrioMaskOn(7);
        }
        
        else if(IsKeyPressedNew(2)) {  // F2

        }
        
        else if(IsKeyPressedNew(3)) {  // F3
          
        }
        
        else if(IsKeyPressedNew(4)) {  // F4

        }
        
        else if(IsKeyPressedNew(5)) {  // <-
          if (passwordPage == 0) {
            passwordStorage[passwordNumber] = (passwordStorage[passwordNumber] + 9) % 10;
            SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + passwordNumber, passwordStorage[passwordNumber]);
          } else if (passwordPage == 1) {
            passwordStorageSettings[passwordNumberSettings] = (passwordStorageSettings[passwordNumberSettings] + 9) % 10;
            SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + passwordNumberSettings, passwordStorageSettings[passwordNumberSettings]);
          }
        }
        
        else if(IsKeyPressedNew(6)) {  // ->
          if (passwordPage == 0) {
            passwordStorage[passwordNumber] = (passwordStorage[passwordNumber] + 1) % 10;
            SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + passwordNumber, passwordStorage[passwordNumber]);
          } else if (passwordPage == 1) {
            passwordStorageSettings[passwordNumberSettings] = (passwordStorageSettings[passwordNumberSettings] + 1) % 10;
            SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + passwordNumberSettings, passwordStorageSettings[passwordNumberSettings]);
          }
        }
        
        else if(IsKeyPressedNew(7)) {  // OK
          if (passwordPage == 0) {
            passwordStorage[passwordNumber] = (passwordStorage[passwordNumber]) % 10;
            SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + passwordNumber, passwordStorage[passwordNumber]);
            passwordNumber++;

            if (passwordNumber >= PASSWORD_LENGTH) {
              int enteredPassword = passwordStorage[0] * 1000 + passwordStorage[1] * 100 + passwordStorage[2] * 10 + passwordStorage[3];

              if (enteredPassword == initialPassword) {
                passwordPage = 1;
                PrioMaskOn(9);
              }
              
              for (int i = 0; i < PASSWORD_LENGTH; i++) {
                passwordStorage[i] = 0;
                SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + i, 0); 
              }
              passwordNumber = 0;
            }
          } else if (passwordPage == 1) {
            passwordStorageSettings[passwordNumberSettings] = (passwordStorageSettings[passwordNumberSettings]) % 10;
            SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + passwordNumberSettings, passwordStorageSettings[passwordNumberSettings]);
            passwordNumberSettings++;

            if (passwordNumberSettings >= PASSWORD_LENGTH) {
              int enteredPasswordSettings = passwordStorageSettings[0] * 1000 + passwordStorageSettings[1] * 100 + passwordStorageSettings[2] * 10 + passwordStorageSettings[3];

              if (enteredPasswordSettings == initialPasswordSettings) {
                PrioMaskOn(3);
              }
              
              for (int i = 0; i < PASSWORD_LENGTH; i++) {
                passwordStorageSettings[i] = 0;
                SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + i, 0); 
              }
              passwordNumberSettings = 0;
            }
          }
        }
        
        else if(IsKeyPressedNew(8)) {  // ESC
          if (passwordPage == 0) {
            PrioMaskOn(8);
          
            passwordNumber = 0;
            for (int i = 0; i < PASSWORD_LENGTH; i++) {
              passwordStorage[i] = 0;
              SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + i, 0); 
            }
          } else if (passwordPage == 1) {
            PrioMaskOn(9);
          
            passwordNumberSettings = 0;
            for (int i = 0; i < PASSWORD_LENGTH; i++) {
              passwordStorageSettings[i] = 0;
              SetVar(HDL_MASK_PASSWORD_NUMBER_ENTRY_1 + i, 0); 
            }
          }
        }
      }
    } break;
    
    // Engine
    case 2: {
      if (IsKeyPressedNew(3)) { // F3
        if (selectedFlagEngine == 0) {
          PrioMaskOn(3);
        }
      }

      if (IsKeyPressedNew(5)) {  // <-
        if (selectedFlagEngine == 0) {
          // Режим выделения ячейки
          if (selectedObjectValueEngine > 0) {
            selectedObjectValueEngine--;
            SetVar(HDL_MASK_ENGINE_SELECTED_OBJECT_1 + selectedObjectValueEngine, 0x0000000A);
            SetVar(HDL_MASK_ENGINE_SELECTED_OBJECT_1 + selectedObjectValueEngine + 1, 0x00000000);
          }
        } else if (selectedFlagEngine == 1) {
          // Режим редактирования значения
          uint16_t tempValueEngine = GetVar(HDL_MASK_ENGINE_VALUE_1 + selectedObjectValueEngine);

          // Минимальные значения для каждого объекта
          const uint16_t minValuesEngine[] = {600, 1500, 5, 50, 50};
          const uint16_t decrementValuesEngine[] = {100, 100, 1, 1, 1};

          if (selectedObjectValueEngine <= 4) {
            if (tempValueEngine - decrementValuesEngine[selectedObjectValueEngine] >= minValuesEngine[selectedObjectValueEngine]) {
              SetVar(HDL_MASK_ENGINE_VALUE_1 + selectedObjectValueEngine, tempValueEngine - decrementValuesEngine[selectedObjectValueEngine]);
            } 
          }
        }
      } else if (IsKeyPressedNew(6)) {  // ->
        if (selectedFlagEngine == 0) {
          // Режим выделения ячейки
          if (selectedObjectValueEngine < 4) {
            selectedObjectValueEngine++;
            SetVar(HDL_MASK_ENGINE_SELECTED_OBJECT_1 + selectedObjectValueEngine, 0x0000000A);
            SetVar(HDL_MASK_ENGINE_SELECTED_OBJECT_1 + selectedObjectValueEngine - 1, 0x00000000);
          }
        } else if (selectedFlagEngine == 1) {
          // Режим редактирования значения
          uint16_t tempValueEngine = GetVar(HDL_MASK_ENGINE_VALUE_1 + selectedObjectValueEngine);

          // Максимальные значения для каждого объекта
          const uint16_t maxValuesEngine[] = {1200, 2000, 20, 90, 90};
          const uint16_t incrementValuesEngine[] = {100, 100, 1, 1, 1};

          if (selectedObjectValueEngine <= 4) {
            if (tempValueEngine + incrementValuesEngine[selectedObjectValueEngine] <= maxValuesEngine[selectedObjectValueEngine]) {
              SetVar(HDL_MASK_ENGINE_VALUE_1 + selectedObjectValueEngine, tempValueEngine + incrementValuesEngine[selectedObjectValueEngine]);
            }
          }
        }
      } else if (IsKeyPressedNew(7)) {  // OK
        if (selectedFlagEngine == 0) {
          // Вход в режим редактирования ячейки
          selectedFlagEngine = 1;
          SetVar(HDL_MASK_ENGINE_GREEN_1 + selectedObjectValueEngine, 0x00000008);
          SetVar(HDL_MASK_ENGINE_SELECTED_OBJECT_1 + selectedObjectValueEngine, 0x00000000);

          // Проверка и корректировка значения, если оно выходит за пределы диапазона
          const uint16_t minValuesEngine[] = {600, 1500, 5, 50, 50};
          const uint16_t maxValuesEngine[] = {1200, 2000, 20, 90, 90};

          uint16_t tempValueEngine = GetVar(HDL_MASK_ENGINE_VALUE_1 + selectedObjectValueEngine);

          if (tempValueEngine < minValuesEngine[selectedObjectValueEngine] || tempValueEngine > maxValuesEngine[selectedObjectValueEngine]) {
            SetVar(HDL_MASK_ENGINE_VALUE_1 + selectedObjectValueEngine, minValuesEngine[selectedObjectValueEngine]);
          }

          // Сохраняем текущее значение для возможного сброса
          originalValueEngine = GetVar(HDL_MASK_ENGINE_VALUE_1 + selectedObjectValueEngine);
        } else if (selectedFlagEngine == 1) {
          // Выход из режима редактирования с сохранением значения
          selectedFlagEngine = 0;
          SetVar(HDL_MASK_ENGINE_GREEN_1 + selectedObjectValueEngine, 0x00000000);
          SetVar(HDL_MASK_ENGINE_SELECTED_OBJECT_1 + selectedObjectValueEngine, 0x0000000A);
        }
      } else if (IsKeyPressedNew(8)) {  // ESC
        if (selectedFlagEngine == 0) {
          // Выход из режима выбора ячеек
          PrioMaskOn(9);
          passwordPage = 1;
        } else if (selectedFlagEngine == 1) {
          // Выход из режима редактирования с сбросом значения
          selectedFlagEngine = 0;
          SetVar(HDL_MASK_ENGINE_GREEN_1 + selectedObjectValueEngine, 0x00000000);
          SetVar(HDL_MASK_ENGINE_SELECTED_OBJECT_1 + selectedObjectValueEngine, 0x0000000A);
          // Сброс значения на исходное
          SetVar(HDL_MASK_ENGINE_VALUE_1 + selectedObjectValueEngine, originalValueEngine);
        }
      }
    } break;
    
    // Pump
    case 3: {
      if (IsKeyPressedNew(3)) { // F3
        if (selectedFlag == 0) {
          PrioMaskOn(2);
        }
      }

      if (IsKeyPressedNew(5)) {  // <-
        if (selectedFlag == 0) {
          // Режим выделения ячейки
          if (selectedObjectValue > 0) {
            selectedObjectValue--;
            SetVar(HDL_MASK_PUMP_SELECTED_OBJECT_1 + selectedObjectValue, 0x0000000A);
            SetVar(HDL_MASK_PUMP_SELECTED_OBJECT_1 + selectedObjectValue + 1, 0x00000000);
          }
        } else if (selectedFlag == 1) {
          // Режим редактирования значения
          const uint16_t minValues[] = {100, 1000, 1, 5, 0, 40, 90, 2, 6};
          const uint16_t stepValues[] = {100, 100, 1, 1, 1, 1, 1, 1, 1};

          uint16_t tempValue = GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue);
          float tempValueFloat = GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue);

          if (selectedObjectValue <= 1) { // Целочисленные значения
            if (tempValue - stepValues[selectedObjectValue] >= minValues[selectedObjectValue]) {
              SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue, tempValue - stepValues[selectedObjectValue]);
            }
          } else { // Значения с плавающей точкой
            if (tempValueFloat - stepValues[selectedObjectValue] >= minValues[selectedObjectValue]) {
              SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue, tempValueFloat - stepValues[selectedObjectValue]);
            }
          }
        }
      } else if (IsKeyPressedNew(6)) {  // ->
        if (selectedFlag == 0) {
          // Режим выделения ячейки
          if (selectedObjectValue < 8) {
            selectedObjectValue++;
            SetVar(HDL_MASK_PUMP_SELECTED_OBJECT_1 + selectedObjectValue, 0x0000000A);
            SetVar(HDL_MASK_PUMP_SELECTED_OBJECT_1 + selectedObjectValue - 1, 0x00000000);
          }
        } else if (selectedFlag == 1) {
          // Режим редактирования значения
          const uint16_t maxValues[] = {1000, 2900, 2, 10, 5, 50, 110, 4, 12};
          const uint16_t stepValues[] = {100, 100, 1, 1, 1, 1, 1, 1, 1};

          uint16_t tempValue = GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue);
          float tempValueFloat = GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue);

          if (selectedObjectValue <= 1) { // Целочисленные значения
            if (tempValue + stepValues[selectedObjectValue] <= maxValues[selectedObjectValue]) {
              SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue, tempValue + stepValues[selectedObjectValue]);
            }
          } else { // Значения с плавающей точкой
            if (tempValueFloat + stepValues[selectedObjectValue] <= maxValues[selectedObjectValue]) {
              SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue, tempValueFloat + stepValues[selectedObjectValue]);
            }
          }
        }
      } else if (IsKeyPressedNew(7)) {  // OK
        if (selectedFlag == 0) {
          // Вход в режим редактирования ячейки
          selectedFlag = 1;
          SetVar(HDL_MASK_PUMP_SELECTED_1 + selectedObjectValue, 0x00000008);
          SetVar(HDL_MASK_PUMP_SELECTED_OBJECT_1 + selectedObjectValue, 0x00000000);

          // Проверка и корректировка значения, если оно выходит за пределы диапазона
          const uint16_t minValues[] = {100, 1000, 1, 5, 0, 40, 90, 2, 6};
          const uint16_t maxValues[] = {1000, 2900, 2, 10, 5, 50, 110, 4, 12};

          uint16_t tempValue = GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue);
          float tempValueFloat = GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue);

          if (selectedObjectValue <= 1) { // Целочисленные значения
            if (tempValue < minValues[selectedObjectValue] || tempValue > maxValues[selectedObjectValue]) {
              SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue, minValues[selectedObjectValue]);
            }
          } else { // Значения с плавающей точкой
            if (tempValueFloat < minValues[selectedObjectValue] || tempValueFloat > maxValues[selectedObjectValue]) {
              SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue, minValues[selectedObjectValue]);
            }
          }

          // Сохраняем текущее значение для возможного сброса
          originalValue = GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue);
        } else if (selectedFlag == 1) {
          // Выход из режима редактирования с сохранением значения
          selectedFlag = 0;
          SetVar(HDL_MASK_PUMP_SELECTED_1 + selectedObjectValue, 0x00000000);
          SetVar(HDL_MASK_PUMP_SELECTED_OBJECT_1 + selectedObjectValue, 0x0000000A);
        }
      } else if (IsKeyPressedNew(8)) {  // ESC
        if (selectedFlag == 0) {
          // Выход из режима выбора ячеек
          PrioMaskOn(9);
          passwordPage = 1;
        } else if (selectedFlag == 1) {
          // Выход из режима редактирования с сбросом значения
          selectedFlag = 0;
          SetVar(HDL_MASK_PUMP_SELECTED_1 + selectedObjectValue, 0x00000000);
          SetVar(HDL_MASK_PUMP_SELECTED_OBJECT_1 + selectedObjectValue, 0x0000000A);
          // Сброс значения на исходное
          SetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN + selectedObjectValue, originalValue);
        }
      }
    } break;

    // Errors
    case 4: {
      if(IsKeyPressedNew(1)) {       // F1
        
      }
      
      else if(IsKeyPressedNew(2)) {  // F2

      }
      
      else if(IsKeyPressedNew(3)) {  // F3
        
      }
      
      else if(IsKeyPressedNew(4)) {  // F4

      }
      
      else if(IsKeyPressedNew(5)) {  // <-
        
      }
      
      else if(IsKeyPressedNew(6)) {  // ->
        
      }
      
      else if(IsKeyPressedNew(7)) {  // OK
      
      }
      
      else if(IsKeyPressedNew(8)) {  // ESC
        PrioMaskOn(0);
      }
    } break;
    
    // Parameters
    case 5: {
      if(IsKeyPressedNew(1)) {       // F1
        
      }
      
      else if(IsKeyPressedNew(2)) {  // F2

      }
      
      else if(IsKeyPressedNew(3)) {  // F3
        
      }
      
      else if(IsKeyPressedNew(4)) {  // F4

      }
      
      else if(IsKeyPressedNew(5)) {  // <-
        
      }
      
      else if(IsKeyPressedNew(6)) {  // ->
        
      }
      
      else if(IsKeyPressedNew(7)) {  // OK
      
      }
      
      else if(IsKeyPressedNew(8)) {  // ESC
        PrioMaskOn(8);
      }
    } break;
    
    // Start
    case 6: {
      if(IsKeyPressedNew(1)) {       // F1
        
      }
      
      else if(IsKeyPressedNew(2)) {  // F2

      }
      
      else if(IsKeyPressedNew(3)) {  // F3
        
      }
      
      else if(IsKeyPressedNew(4)) {  // F4

      }
      
      else if(IsKeyPressedNew(5)) {  // <-
        SetVar(HDL_SYS_LANGUAGE, 0);
      }
      
      else if(IsKeyPressedNew(6)) {  // ->
        SetVar(HDL_SYS_LANGUAGE, 1);
      }
      
      else if(IsKeyPressedNew(7)) {  // OK
        PrioMaskOn(0);
      }
      
      else if(IsKeyPressedNew(8)) {  // ESC

      }
    } break;
    
    // Task
    case 7: {
      if(IsKeyPressedNew(1)) {       // F1
        SetVar(HDL_MASK_TASK_PRESSURE_TEXT, 0x00010028);
        SetVar(HDL_MASK_TASK_TURNOVER_TEXT, 0x0001002C);
        
        SetVar(HDL_MASK_TASK_PRESSURE_TEXT_CENTER, 0x00000000);
        SetVar(HDL_MASK_TASK_TURNOVER_TEXT_CENTER, 0x00000028);
        
        SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MIN, GetVar(HDL_MASK_ENGINE_VALUE_1));
        SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MAX, GetVar(HDL_MASK_ENGINE_VALUE_2));
        
        SetVar(HDL_PRESSURE_OR_TURNOVER, 0);
        
        if(GetVar(HDL_MASK_TASK_VALUES) < GetVar(HDL_MASK_ENGINE_VALUE_1) || GetVar(HDL_MASK_TASK_VALUES) > GetVar(HDL_MASK_ENGINE_VALUE_2)) {
          SetVar(HDL_MASK_TASK_VALUES, GetVar(HDL_MASK_ENGINE_VALUE_1));
        }
        
        taskValue = 1;
      }
      
      else if(IsKeyPressedNew(2)) {  // F2
        
      }
      
      else if(IsKeyPressedNew(3)) {  // F3
        
      }
      
      else if(IsKeyPressedNew(4)) {  // F4
        SetVar(HDL_MASK_TASK_TURNOVER_TEXT, 0x00010028);
        SetVar(HDL_MASK_TASK_PRESSURE_TEXT, 0x0001002C);
        
        SetVar(HDL_MASK_TASK_PRESSURE_TEXT_CENTER, 0x00000028);
        SetVar(HDL_MASK_TASK_TURNOVER_TEXT_CENTER, 0x00000000);
  
        SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MIN, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN));
        SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MAX, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MAX));
  
        SetVar(HDL_PRESSURE_OR_TURNOVER, 1);
  
        if(GetVar(HDL_MASK_TASK_VALUES) < GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN) || GetVar(HDL_MASK_TASK_VALUES) > GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MAX)) {
          SetVar(HDL_MASK_TASK_VALUES, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN));
        }
  
        taskValue = 0;
      }
      
      else if(IsKeyPressedNew(5)) {  // <-
        uint16_t timeTaskValue = GetVar(HDL_MASK_TASK_VALUES);
        if(timeTaskValue - 100 >= GetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MIN) && GetVar(HDL_PRESSURE_OR_TURNOVER) == 1) {
          SetVar(HDL_MASK_TASK_VALUES, timeTaskValue - 100);
        }
        if(timeTaskValue - 100 >= GetVar(HDL_MASK_ENGINE_VALUE_1) && GetVar(HDL_PRESSURE_OR_TURNOVER) == 0) {
          SetVar(HDL_MASK_TASK_VALUES, timeTaskValue - 100);
        }
      }
      
      else if(IsKeyPressedNew(6)) {  // ->
        uint16_t timeTaskValue = GetVar(HDL_MASK_TASK_VALUES);
        if(timeTaskValue + 100 <= GetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MAX) && GetVar(HDL_PRESSURE_OR_TURNOVER) == 1) {
          SetVar(HDL_MASK_TASK_VALUES, timeTaskValue + 100);
        }
        if(timeTaskValue + 100 <= GetVar(HDL_MASK_ENGINE_VALUE_2) && GetVar(HDL_PRESSURE_OR_TURNOVER) == 0) {
          SetVar(HDL_MASK_TASK_VALUES, timeTaskValue + 100);
        }
      }
      
      else if(IsKeyPressedNew(7)) {  // OK
        
      }
      
      else if(IsKeyPressedNew(8)) {  // ESC 
        PrioMaskOn(0);
        
        // Обнуление задания при выходе с маски
        // TODO: добавить такую же логику обнуления при аварии
        SetVar(HDL_MASK_TASK_VALUES, 0);
      }
    } break;
    
    // Menu
    case 8: {
      if(IsKeyPressedNew(1)) {       // F1
        PrioMaskOn(7);
        if(GetVar(HDL_PRESSURE_OR_TURNOVER) == 0) {
          SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MIN, GetVar(HDL_MASK_ENGINE_VALUE_1));
          SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MAX, GetVar(HDL_MASK_ENGINE_VALUE_2));
          if(GetVar(HDL_MASK_TASK_VALUES) < GetVar(HDL_MASK_ENGINE_VALUE_1) || GetVar(HDL_MASK_TASK_VALUES) > GetVar(HDL_MASK_ENGINE_VALUE_2)) {
            SetVar(HDL_MASK_TASK_VALUES, GetVar(HDL_MASK_ENGINE_VALUE_1));
          }
        } else if(GetVar(HDL_PRESSURE_OR_TURNOVER) == 1) {
          SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MIN, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN));
          SetVar(HDL_MASK_TASK_OUTLET_PRESSURE_MAX, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MAX));
          if(GetVar(HDL_MASK_TASK_VALUES) < GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN) || GetVar(HDL_MASK_TASK_VALUES) > GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MAX)) {
            SetVar(HDL_MASK_TASK_VALUES, GetVar(HDL_MASK_PUMP_OUTLET_PRESSURE_MIN));
          }
        }
      }
      
      else if(IsKeyPressedNew(2)) {  // F2
        PrioMaskOn(5);
      }
      
      else if(IsKeyPressedNew(3)) {  // F3
        
      }
      
      else if(IsKeyPressedNew(4)) {  // F4
        PrioMaskOn(1);
      }
      
      else if(IsKeyPressedNew(5)) {  // <-

      }
      
      else if(IsKeyPressedNew(6)) {  // ->

      }
      
      else if(IsKeyPressedNew(7)) {  // OK
      
      }
      
      else if(IsKeyPressedNew(8)) {  // ESC
        PrioMaskOn(0);
        passwordPage = 0;
      }
    } break;
    
    // Settings
    case 9: {
      if(IsKeyPressedNew(1)) {       // F1
        PrioMaskOn(10);
      }
      
      else if(IsKeyPressedNew(2)) {  // F2

      }
      
      else if(IsKeyPressedNew(3)) {  // F3
        
      }
      
      else if(IsKeyPressedNew(4)) {  // F4
        PrioMaskOn(2);
      }
      
      else if(IsKeyPressedNew(5)) {  // <-

      }
      
      else if(IsKeyPressedNew(6)) {  // ->

      }
      
      else if(IsKeyPressedNew(7)) {  // OK
        
      }
      
      else if(IsKeyPressedNew(8)) {  // ESC
        PrioMaskOn(8);
        passwordPage = 0;
      }
    } break;
    
    // Technical
    case 10: {
      if(IsKeyPressedNew(1)) {       // F1
      
      }
      
      else if(IsKeyPressedNew(2)) {  // F2
      
      }
      
      else if(IsKeyPressedNew(3)) {  // F3
        
      }
      
      else if(IsKeyPressedNew(4)) {  // F4
        
      }
      
      else if(IsKeyPressedNew(5)) {  // <-
        if (selectedFlagTechnical == 0) {
          // Режим выделения ячейки
          if (selectedObjectValueTechnical > 0) {
            selectedObjectValueTechnical--;
            SetVar(HDL_MASK_TECHNICAL_GRAY_0 + selectedObjectValueTechnical, 0x0000000A);
            SetVar(HDL_MASK_TECHNICAL_GRAY_0 + selectedObjectValueTechnical + 1, 0x00000000);
          }
        } else if (selectedFlagTechnical == 1) {
          // Режим редактирования значения
          uint16_t tempValueTechnical = GetVar(HDL_MASK_TECHNICAL_VALUE_0 + selectedObjectValueTechnical);

          if (tempValueTechnical > 50) {
            SetVar(HDL_MASK_TECHNICAL_VALUE_0 + selectedObjectValueTechnical, tempValueTechnical - 50);
          }
        }

      } else if (IsKeyPressedNew(6)) {  // ->
        if (selectedFlagTechnical == 0) {
          // Режим выделения ячейки
          if (selectedObjectValueTechnical < 1) {
            selectedObjectValueTechnical++;
            SetVar(HDL_MASK_TECHNICAL_GRAY_0 + selectedObjectValueTechnical, 0x0000000A);
            SetVar(HDL_MASK_TECHNICAL_GRAY_0 + selectedObjectValueTechnical - 1, 0x00000000);
          }
        } else if (selectedFlagTechnical == 1) {
          // Режим редактирования значения
          uint16_t tempValueTechnical = GetVar(HDL_MASK_TECHNICAL_VALUE_0 + selectedObjectValueTechnical);

          if (tempValueTechnical < 1000 && selectedObjectValueTechnical == 0) {
            SetVar(HDL_MASK_TECHNICAL_VALUE_0 + selectedObjectValueTechnical, tempValueTechnical + 50);
          } else if (tempValueTechnical < 500 && selectedObjectValueTechnical == 1) {
            SetVar(HDL_MASK_TECHNICAL_VALUE_0 + selectedObjectValueTechnical, tempValueTechnical + 50);
          }
        }
        
      } else if (IsKeyPressedNew(7)) {  // OK
        if (selectedFlagTechnical == 0) {
          // Вход в режим редактирования ячейки
          selectedFlagTechnical = 1;
          SetVar(HDL_MASK_TECHNICAL_GREEN_0 + selectedObjectValueTechnical, 0x00000008);
          SetVar(HDL_MASK_TECHNICAL_GRAY_0 + selectedObjectValueTechnical, 0x00000000);

          // Сохраняем текущее значение для возможного сброса
          originalValueTechnical = GetVar(HDL_MASK_TECHNICAL_VALUE_0 + selectedObjectValueTechnical);
        } else if (selectedFlagTechnical == 1) {
          // Выход из режима редактирования с сохранением значения
          selectedFlagTechnical = 0;
          SetVar(HDL_MASK_TECHNICAL_GREEN_0 + selectedObjectValueTechnical, 0x00000000);
          SetVar(HDL_MASK_TECHNICAL_GRAY_0 + selectedObjectValueTechnical, 0x0000000A);
        }
        
      } else if (IsKeyPressedNew(8)) {  // ESC
        if (selectedFlagTechnical == 0) {
          // Выход из режима выбора ячеек
          PrioMaskOn(9);
          passwordPage = 1;
        } else if (selectedFlagTechnical == 1) {
          // Выход из режима редактирования с сбросом значения
          selectedFlagTechnical = 0;
          SetVar(HDL_MASK_TECHNICAL_GREEN_0 + selectedObjectValueTechnical, 0x00000000);
          SetVar(HDL_MASK_TECHNICAL_GRAY_0 + selectedObjectValueTechnical, 0x0000000A);
          // Сброс значения на исходное
          SetVar(HDL_MASK_TECHNICAL_VALUE_0 + selectedObjectValueTechnical, originalValueTechnical);
        }
      }
    } break;
  }
}
