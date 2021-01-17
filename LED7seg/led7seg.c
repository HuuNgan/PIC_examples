//Display led 7seg
#include <16F877A.h>
#use delay(clock=4000000)
main()
{
    int number[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
    while(1)
    {
      int i;
      for(i=0; i<10; i++)
      {
          output_D(number[i]);
          delay_ms(500);
      }
      delay_ms(2000);
    }
}
