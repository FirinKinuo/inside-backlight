/*
Скетч подсветки в шкафу
Реализованно на 2 микриках от мышки, которые так идеально встали в зазор между дверью и верхней крышкой(И какого хрена с завода там зазор),
куске ленты и валяющейся без дела атмеги

~/dev by f.kinuo, 2021 
*/

// ---- PINS DEFINE ----
#define LED_STRIP_PIN                 9   // Пин светодиодной ленты
#define LEFT_DOOR_STATUS_SENSOR_PINS  3   // Пин датчика левой двери
#define RIGHT_DOOR_STATUS_SENSOR_PINS 6   // Пин датчика правой двери
// ---- ---- ----

// ---- CONFIG CONSTS ----
const uint32_t SMOOTH_LIGHT_SPEED = 2000;  // Насколько быстро в MS зажигать на полную свет 
const uint8_t LED_MAX_BRIGHTNESS = 250;  // Яркость подсветки 0-255
// ---- ---- ----

// ---- SYSTEM VARS ----
uint8_t led_current_brightness = 0; 
// ---- ---- ----

// ---- LIBS ----
#include "GyverButton.h"
#include "GyverTimer.h"
// ---- ---- ----

// ---- CONSTRUCTORS ----
GTimer smoothLightTimer(US, (SMOOTH_LIGHT_SPEED / LED_MAX_BRIGHTNESS) * 1000);
GButton leftDoorSensor(LEFT_DOOR_STATUS_SENSOR_PINS, HIGH_PULL, NORM_OPEN);
GButton rightDoorSensor(RIGHT_DOOR_STATUS_SENSOR_PINS, HIGH_PULL, NORM_OPEN);
// ---- ---- ----


void setup() {
//  Однажды здесь будет что-то, но не сейчас )0)
}

void loop() {
  check_handlers();  // Проверяет все обработчики
  /*
   Вызывает функцию мягкого переключения режима света в зависимости от состояния микриков
   Если оба микрика зажаты, то выключаем, если хотя бы один отжат, то включаем

   Если работает наоборот, то пиздуем в раздел с конструктрами классов менять там 
   настроечки у GButton (Скорее всего поменять NORM_OPEN нп NORM_CLOSE)
   */ 
  smooth_turn_light(!(leftDoorSensor.isHold() && rightDoorSensor.isHold()));  
}
