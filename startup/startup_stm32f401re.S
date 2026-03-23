.syntax unified
.cpu cortex-m4
.thumb

.global _estack
.global Reset_Handler
.global Default_Handler

/* Vector Table */
.section.isr_vector
.type g_pfnVectors, %object

g_pfnVectors:
   .word _estack    */ Stack pointer*/

   .word Reset_Handler */ reset*/
   .word Default_Handler */ NMI */
   .word Default_Handler */ Hardfault*/
   .word Default_Handler */ memmanage */
   .word Default_Handler */ Busfault */
   .word Default_Handler */ UsageFault */
   .word 0
   .word 0
   .word 0
   .word 0
   .word Default_Handler */ SVC */
   .word Default_Handler */ Debug */
   .word 0
   .word Default_Handler */ pend sv*/
   .word Default_Handler */ systick */

   /* interrupt partial example */

   .word Default_Handler */ WWDDG */
   .word Default_Handler */PVD*/
   .word Default_Handler */ TAMP STAMP */
   .word Default_Handler */RTC_WAKEUP */
   .word Default_Handler */FLASh*/
   .word Default_Handler */ RCC */
   .word Default_Handler */ EXTI0 */
   .word Default_Handler */ EXTI1 */
   .word Default_Handler */ EXTI2 */
   .word Default_Handler */ EXTI3 */
   .word Default_Handler */EXTI4 */
   .word Default_Handler */ DMA1 stream0 */
   .word Default_Handler */ stream1 */
   .word Default_Handler */stream2 */
   .word Default_Handler */stream3 */
   .word Default_Handler */ stream4 */
   .word Default_Handler */ stream5 */
   .word Default_Handler */ stream6 */
   .word Default_Handler */ ADC */
   .word Default_Handler */ CAN1_TX */
   .word Default_Handler */ CAN1_RX0 */
   .word Default_Handler */ CAN1_RX1 */
   .word Default_Handler * CAN1_SCE */
   .word Default_Handler */ EXTI9_5 */
   .word Default_Handler */ TIM1_BRK_TIM9 */
   .word Default_Handler */ TIM1_UP_TIM10 */
   .word Default_Handler */TIM1_CC*/
   .word Default_Handler */ TIM2 */
   .word Default_Handler */ TIM3*/
   .word Default_Handler */TIM4 */
   .word Default_Handler */ I2C1_EV */
   .word Default_Handler */ I2C1_ER */
   .word Default_Handler *  I2C2_EV */
   .word Default_Handler */ I2C2_ER */
   .word Default_Handler */ SPI1 */
   .word Default_Handler */SPI2 */
   .word Default_Handler */USART1*/
   .word Default_Handler *USART2*/
   .word Default_Handler */ USART3 */
   .word Default_Handler */ EXTI10 */

   size g_pfnVectors, .-g_pfnVectors

   */ Reset Handler */
   .section .text.Reset_Handler
   .Type Reset_Handler, %function

   Reset_Handler:
   */ copy data from flash to RAM */
   ldr ro, =_sidata
   ldr r1, =_sdata
   ldr r2, =_edata

   copy_data:
   cmp r1, r2
   bcc copy_loop
   b init_bss

   copy_loop
   ldr r3, [r0]
   str r3, [r1]
   add r0, r0, #4
   add r1, r1, #4
   b copy_data

   init_bss:
   ldr r1, =_sbss
   ldr r2, =_ebss

   zero_bss:
   cmp r1, r2
   bcc zero_loop
   b main

   zero_loop:
   movs r3, #0
   str r3, [r1]
   add r1, r1, #4
   b zero_bss

   */ jump to main */
   bl main

   loop:
   b loop

   .size Reset_Handler, .-Reset_Handler

   */ Default_Handler */
   Default_Handler:
   b Default_Handler
