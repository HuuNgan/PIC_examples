#include <16F877.h>
#use delay(clock = 20000000)
#use rs232(UART)
#define LED_OFF_ALL  0x61
#define Toggle_ALL   0x62
#define RUN_SEQUENCE 0x63
int incode;
#INT_RDA
void ISR_UART_RECEIVE() {
  incode = getc();    //read character from uart
}

void main() {
  enable_interrupts(INT_RDA);
  enable_interrupts(global);
  int i;
  setup_uart(9600);     //baurate
  
  while(1) {    
    if(incode==LED_OFF_ALL)      output_D(0); 
    else if(incode==Toggle_ALL) {
      output_D(255);
      delay_ms(500);
      output_D(0);
      delay_ms(500);
    }
    else if(incode==RUN_SEQUENCE){
      int portD_state = 1;
      for(i=0; i<8; i++){
        output_D(portD_state);
        delay_ms(500);
        portD_state = portD_state << 1;
      }
    }
  }
}
