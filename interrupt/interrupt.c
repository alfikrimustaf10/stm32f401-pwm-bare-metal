#include "../interrupt/interrupt.h"
#include <stdint.h>
#include "../include/exti.h"
#include "../include/gpio.h"


  
 
void interrupt_init (void){
    enable_gpioa_pa1_exti();// this one is from gpio.h/gpio.c//
}

void EXTI1_IRQHandler(void){
     if (EXTI_PR & (1 << 1)){
              EXTI_PR |= (1 << 1);
              GPIOA_ODR ^= (1 << 5);
             }
}
