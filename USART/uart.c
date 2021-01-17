#include <16F877.h>
#use delay(clock = 20000000)
#use rs232(UART)

void main()
{
  int incode;
  setup_uart(9600);     //baurate
  
  while(1)
  {
    incode = getc();    //read character from uart
    printf("ASCII = %d ",incode);    //display it on
    putc(13);              //new line on display
  }
}
