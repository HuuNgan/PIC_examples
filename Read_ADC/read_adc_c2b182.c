#include <16F877.h>
#use delay(clock=4000000)
int dl_time = 0;
#int_timer0
void ISR_tim0() {
    dl_time=1;
    set_timer0(156);
}
void delay_tim0() {
   while(dl_time==0);
    dl_time = 0;
}
void main() {
    enable_interrupts(int_timer0);
    enable_interrupts(global);
}