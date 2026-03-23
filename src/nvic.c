#include "../include/nvic.h"
#include <stdint.h>

void nvic_enable_irq(uint8_t irq) {
    NVIC_ISERO |= (1 << irq);
}
