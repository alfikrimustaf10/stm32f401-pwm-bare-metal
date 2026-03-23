#define GPIOA_OTYPER_P ~(1 << 5) //push and pull
#define GPIOA_OTYPER_O (1 << 5) //open-drain
#include <stdint.h>
#define GPIOA_OTYPER_O (1 << 5) //open-drain
#include <stdint.h>
#include "../include/exti.h"
#include "../include/rcc.h"
#include "../include/gpio.h"
#include "../include/syscfg.h"
#include "../include/nvic.h"

void enable_gpioa_pa1_exti(void){
    //enable syscfg clock
     RCC_APB2ENR |= (1 << 14);
    
    //set PA1 as input exti
     GPIOA_MODER &= ~(3 << (1*2));

    //clear and set pull up register
     GPIOA_PUPDR &= ~(3 << (1*2));
     GPIOA_PUPDR |= (1 << (1*2));

    //mapping PA1 to exti1 because exti1 provide line 0 to 3
     SYSCFG_EXTICR1 &= ~(0xF << 4);
     SYSCFG_EXTICR1 |= (0x0 << 4);

    //enable exti line
     EXTI_IMR |= (1 << 1);

    //set exti rising trigger edge
     EXTI_RISING |= (1 << 1);

     nvic_enable_irq(7);
}

void gpio_init_led(void){
     
    //as usual, we enable clock for gpioa 
     RCC_AHB1ENR |= (1 << 0);

    // set output moder int PA5
     GPIOA_MODER &= ~(3 << (5*2));
     GPIOA_MODER |= (1 << (5*2));
}

void gpio_init_button(void){
     RCC_AHB1ENR |= (1 << 0);
     GPIOA_MODER &= (3 << (1*2));
     GPIOA_PUPDR &= ~(3 << (1*2));
     GPIOA_MODER |= (1 << (1*2));
}
