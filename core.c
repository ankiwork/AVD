#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <UserCAPI.h>
#include <UserCEvents.h> 

#include "vartab.h"
#include "objtab.h"

bool on = false;           // Флаг включения системы
bool zazh = false;         // Флаг зажигания
bool stop = false;         // Флаг остановки
bool turbo = false;        // Флаг турбины
bool startFlag = false;    // Флаг запуска двигателя
bool alarmTurbo = false;   // Флаг аварии турбины
bool systemAlarm = false;  // Флаг аварии

int tmr1 = 0;     // Таймер 1 (для запуска)
int tmr2 = 0;     // Таймер 2 (для задержки повторного запуска)
int tmr3 = 0;     // Таймер 3 (для турбины)
int tOil = 0;     // Температура масла
int XX = 1000;    // Примерное значение оборотов холостого хода
int rpmSet = 0;   // Установленные обороты двигателя
int rpmFact = 0;  // Фактические обороты двигателя

// Процедура запуска двигателя
void startEngine(void) {
  // Устанавливаем обороты на холостой ход
  rpmFact = XX; 
}

// Процедура остановки двигателя
void stopEngine(void) {
  // Сбрасываем обороты
  rpmFact = 0; 
}

int mainAlgorithm(void) {
  while (1) {
    // Блок 1: Проверка условий для начала запуска
    if (zazh == true && stop == false) {
      sleep(5);           // Задержка 5 секунд
    } else {
      startFlag = false;  // Если условия не выполнены, сбрасываем флаг запуска
      continue;           // Возвращаемся в начало цикла
    }

    // Блок 2: Проверка векторов аварий
    if (systemAlarm) {
      startFlag = false;  // Если авария, сбрасываем флаг запуска
      continue;           // Возвращаемся в начало цикла
    }

    // Блок 3: Проверка условий для запуска двигателя
    if (on == true && rpmFact == 0 && tmr2 == 0) {
      startFlag = true;   // Устанавливаем флаг запуска
    } else {
      startFlag = false;  // Если условия не выполнены, сбрасываем флаг запуска
      continue;           // Возвращаемся в начало цикла
    }

    // Блок 4: Процедура запуска двигателя
    if (tmr1 < 7 && rpmFact > XX - 10 && startFlag == true) {
      startEngine();  // Запуск двигателя
      sleep(7);       // Ожидание 7 секунд
      tmr1++;         // Увеличиваем таймер
      continue;       // Возвращаемся в начало блока 4
    }

    // Блок 5: Проверка условий аварии пуска
    if (tmr1 == 7 && rpmFact < XX - 10) {
      sleep(30);          // Задержка повторного запуска 30 секунд
      tmr2 = 30;          // Устанавливаем таймер задержки
      tmr1 = 0;           // Сбрасываем таймер 1
      startFlag = false;  // Сбрасываем флаг запуска
    }

    // Блок 6: Проверка условий остановки или аварии
    if ((stop == true || systemAlarm == true) && rpmFact > 0) {
      // Блок 7: Управление турбиной
      if (tOil > 70 && tmr3 < 60 && alarmTurbo == true) {
        turbo = true;  //
        rpmSet = XX;   // Устанавливаем обороты
        sleep(60);     // Задержка турботаймера 60 секунд
        tmr3 = 60;     // Устанавливаем таймер
        continue;      // Возвращаемся в начало блока 7
      } else {
        // Блок 8: Остановка турбины и двигателя
        turbo = false;  //
        stopEngine();   // Остановка двигателя
        stop = false;   // Сбрасываем флаг остановки
        tmr3 = 0;       // Сбрасываем таймер 3
      }
      break;
    } else { break; }
  } return 0;
}
