//Scan LED 7seg - 4 LED common anode
#include <16F877A.h>
#use delay(clock=4000000)

int number[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int led_value[4] = {0, 1, 2, 3};
int choosed_led = 1;

void scan_led()
{
  int i;
  for(i=0; i<4; i++)
  {
      output_A(~choosed_led);
      output_D(number[led_value[i]]);
      delay_ms(10);
      output_D(255);
      choosed_led = choosed_led << 1;
      if(choosed_led==16) choosed_led =1;
  }
}

main()
{
    while(1)
    {
      scan_led();
    }
}
