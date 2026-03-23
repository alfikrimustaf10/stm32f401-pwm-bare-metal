#include <stdint.h>

#define GPIOA_BASE_ADDR 0x40020000
#define GPIOB_BASE_ADDR 0x40020400
#define GPIOC_BASE_ADDR 0x40020800
#define GPIOA_AFRH (*(volatile uint32_t*)(GPIOA_BASE_ADDR + 0x24))//this one for enabling alternative function of gpioa
#define GPIOA_MODER (*(volatile uint32_t*)(GPIOA_BASE_ADDR + 0x00))// for setting gpioa moder, either it's an output or an in
#define GPIOA_PUPDR (*(volatile uint32_t*)(GPIOA_BASE_ADDR + 0x0C)) //gpioa pull up / pull down register//
#define GPIOA_OTYPER  (*(volatile uint32_t*)(GPIOA_BASE_ADDR + 0x04))
#define GPIOB_OTYPER  (*(volatile uint32_t*)(GPIOA_BASE_ADDR + 0x04))
#define GPIOC_OTYPER  (*(volatile uint32_t*)(GPIOA_BASE_ADDR + 0x04))
#define GPIOA_ODR (*(volatile uint32_t*)(GPIOA_BASE_ADDR + 0x14))
#define GPIOB_ODR (*(volatile uint32_t*)(GPIOB_BASE_ADDR + 0x14))
#define GPIOC_ODR (*(volatile uint32_t*)(GPIOC_BASE_ADDR + 0x14))


void enable_gpioa_pa1_exti();
void gpio_init_led(void);
void gpio_init_button(void);
