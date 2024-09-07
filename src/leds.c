#include "leds.h"

#define LSB 0x0001
#define LED_OFFSET 1
#define ALL_LEDS_OFF 0x0000

static uint16_t *puerto;

uint16_t LedToMask(int led){
    return LSB << (led - LED_OFFSET);
}

void LedsCreate(uint16_t *direccion){
    puerto = direccion;
    *puerto = ALL_LEDS_OFF;
}

void LedsSetOn(int led){
    *puerto |= LedToMask(led);
}

void LedsSetOff(int led){
    *puerto &= ~LedToMask(led);
}