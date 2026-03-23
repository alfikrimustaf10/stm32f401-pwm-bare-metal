#ifndef SYSCFG_H
#define SYSCFG_H

#include <stdint.h>

#define SYSCFG_BASE 0x40013800UL
#define SYSCFG_EXTICR1 (*(volatile uint32_t*)(SYSCFG_BASE + 0x08)) //register configuration for what pin number to connect with EXTI line from 0 to 3//
#define SYSCFG_EXTICR2 (*(volatile uint32_t*)(SYSCFG_BASE + 0x0C)) //EXTI line from 4 to 7

#endif /* SYSCFG */
