#include <16F877.h>
#use delay(clock = 20000000)
#use rs232(UART)
#define RELAY1  PIN_C4
#define RELAY2  PIN_C5
int number[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int MODE =0;
char string[3];
#INT_RDA
void ISR_UART_RECEIVE() {
  gets(string);    //read character from uart
  //printf("%s ",string);
  if(string[0]=='G')
  {
      if(string[1]=='0') MODE=0;
      else if(string[1]=='1') MODE=1;
      else if(string[1]=='2') MODE=2;
  }
}

void main() {
  enable_interrupts(INT_RDA);
  enable_interrupts(global);
  int i;
  setup_uart(9600);     //baurate  
  while(1) {    
    if(MODE==0) {
        output_low(RELAY1);
        output_low(RELAY2);
        output_D(number[0]);
    }
    else if(MODE==1) {
        output_high(RELAY1);
        output_low(RELAY2);
        output_D(number[1]);
    }
    else if(MODE==2){
        output_high(RELAY1);
        output_D(number[2]);
    }
  }
}
