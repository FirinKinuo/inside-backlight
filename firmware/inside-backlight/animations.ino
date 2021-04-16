/*
Модуль анимаций подсветки
*/

/*
Просто мягко включать свет
true - включить свет
false - выключить
*/ 
void smooth_turn_light(bool type_switch){
    // Вот эта шайтанка для проверки от переполнения байтика со значием текущей яркости
    // Ну и еще против флуда analogWrite без надобности))
    if ((!type_switch and led_current_brightness <= 0) || (type_switch and led_current_brightness > LED_MAX_BRIGHTNESS)) return;

    // Если таймер мягкости готов, то повышаем яркость на 1 ну или вырубаем ко всем чертям
    if (smoothLightTimer.isReady()) {
        if (type_switch){
            led_current_brightness++;
        } else {
            led_current_brightness = 0;
        }
        analogWrite(LED_STRIP_PIN, led_current_brightness); //  О святой ШИМ, спасибо, что существуешь
    }
}
