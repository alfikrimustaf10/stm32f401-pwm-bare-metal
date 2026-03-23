#include <stdint.h>
#include "../include/timer.h"
#include "../include/rcc.h"
#include "../include/gpio.h"


void timer1_pwm_init(void){
    RCC_APB2ENR |= (1 << 0);
    GPIOA_MODER &= ~(3 << (8*2));
    GPIOA_MODER |= (1 << (8*2));
    GPIOA_AFRH &= ~(0xF << 0);
    GPIOA_AFRH |= (1 << 0);
    TIMER1->PSC = 16-1;
    TIMER1->ARR = 1000-1;
    TIMER1->CCR1 = 500;
    TIMER1->CCMR1 |= (6 << 4);
    TIMER1->CCMR1 |= (1 << 3);
    TIMER1->CCER |= (1 << 0);
    TIMER1->BDTR |= (1 << 15);
    TIMER1->CR1 |= (1 << 7);
    TIMER1->CR1 |= (1 << 0);
}

void timer1_set_duty(uint16_t duty){
     if (duty > 1000) duty = 1000;
     TIMER1->CCR1 = duty;
}
