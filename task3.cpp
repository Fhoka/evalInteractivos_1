#include <Arduino.h>
#include "task3.h"
#include "events.h"

static bool compareKeys(BUTTONS *pSecret, BUTTONS *pKey)
{
    bool correct = true;
    for (uint8_t i = 0; i < 5; i++)
    {
        if (pSecret[i] != pKey[i]){
            correct = false;
            break;
        }
    }

    return correct;
}

void task3(){
    enum class TaskStates
    {
        INIT,LENTO, MEDIO, RAPIDO, ENCENDIDO, APAGADO
    };
    static TaskStates taskState = TaskStates::LENTO;
    const uint8_t led = 11;

    static BUTTONS secret[5] = {BUTTONS::ONE_BTN, BUTTONS::ONE_BTN,
                                BUTTONS::TWO_BTN, BUTTONS::TWO_BTN,
                                BUTTONS::ONE_BTN};

    static BUTTONS disarmKey[5] = {BUTTONS::NONE};
    static uint32_t lastTime;
    static constexpr uint32_t INTERVALSLOW = 1000;
    static constexpr uint32_t INTERVALMEDIUM= 500;
    static constexpr uint32_t INTERVALFAST = 250;
    static bool ledStatus = false;

    switch (taskState)
    {
       case TaskStates::INIT:
    {
        pinMode(led, OUTPUT);
        lastTime = millis();
        taskState = TaskStates::LENTO;
        break;
    }
        case TaskStates::LENTO:
        {
            uint32_t currentTime = millis();
            if( (currentTime - lastTime) >= INTERVALSLOW ){
                lastTime = currentTime;
                digitalWrite(led,ledStatus);
                ledStatus = !ledStatus;
        }
        break;
        }
}
}
