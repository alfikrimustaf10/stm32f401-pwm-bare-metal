#include <stdint.h>

#define EXTI_BASE_ADDR 0x40013C00
#define EXTI_RISING (*(volatile uint32_t*)(EXTI_BASE_ADDR + 0x08))
#define EXTI_FALLING (*(volatile uint32_t*)(EXTI_BASE_ADDR + 0x0C))
#define EXTI_IMR (*(volatile uint32_t*)(EXTI_BASE_ADDR + 0x00))
#define EXTI_EMR (*(volatile uint32_t*)(EXTI_BASE_ADDR + 0x04))
#define EXTI_SWIER (*(volatile uint32_t*)(EXTI_BASE_ADDR + 0x10))
#define EXTI_PR (*(volatile uint32_t*)(EXTI_BASE_ADDR + 0x14))

