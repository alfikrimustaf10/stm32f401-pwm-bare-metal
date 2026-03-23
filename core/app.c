#include <stdint.h>
#include "app.h" 
#include "../include/timer.h"

volatile int button_flag = 0;
volatile int duty = 10;

void app_update(void){
     if (button_flag){
      duty += 10;
      if (duty > 100) {duty = 10;}
     }

     timer1_set_duty(duty);
     button_flag = 0;
}

