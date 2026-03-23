#include <stdint.h>
#include "../include/gpio.h"
#include "../include/timer.h"
#include "../interrupt/interrupt.h"
#include "../core/app.h"

void system_init(void){
     gpio_init_led();
     gpio_init_button();
     timer_pwm_init();
     interrupt_init();
}

void system_run(void){
     while(1){
         app_update();
     }
}

