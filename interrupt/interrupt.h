#include <stdint.h>

#ifndef INTERRUPT_H
#define INTERRUPT_H


void interrupt_init(void);
void EXTI1_IRQHandler(void);
void enable_interrupt_exti1(void);


#endif /* INTERRUPT_H */
