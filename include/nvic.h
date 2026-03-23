#ifndef NVIC_H
#define NVIC_H

#include <stdint.h>

#define NVIC_ISERO (*(volatile uint32_t*)0xE000E100) //set enable interrupt register
#define NVIC_ICERO (*(volatile uint32_t*)0xE000E180)

void nvic_enable_irq(uint8_t irq);

#endif /* NVIC_H */
