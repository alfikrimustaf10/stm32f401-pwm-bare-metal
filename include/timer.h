#include <stdint.h>

#define TIMER1_BASE_ADDR 0x40010000
#define TIMER2_BASE_ADDR 0x40000000
#define TIMER3_BASE_ADDR 0x40000400
#define TIMER4_BASE_ADDR 0x40000800
#define TIMER5_BASE_ADDR 0x40000C00
#define TIMER9_BASE_ADDR 0x40014000
#define TIMER10_BASE_ADDR 0x40014400
#define TIMER11_BASE_ADDR 0x40014800

#define TIMER1 ((TIM_Typedef*)TIMER1_BASE_ADDR)
#define TIMER2 ((TIM_Typedef*)TIMER2_BASE_ADDR)
#define TIMER3 ((TIM_Typedef*)TIMER3_BASE_ADDR)
#define TIMER4 ((TIM_Typedef*)TIMER4_BASE_ADDR)
#define TIMER5 ((TIM_Typedef*)TIMER5_BASE_ADDR)
#define TIMER9 ((TIM_Typedef*)TIMER9_BASE_ADDR)
#define TIMER10 ((TIM_Typedef*)TIMER10_BASE_ADDR)
#define TIMER11 ((TIM_Typedef*)TIMER11_BASE_ADDR)

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;
    volatile uint32_t CCR1;
    volatile uint32_t CCR2;
    volatile uint32_t CCR3;
    volatile uint32_t CCR4;
    volatile uint32_t BDTR;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
}TIM_Typedef;

void timer_pwm_init(void);
void timer1_set_duty(uint16_t duty);
