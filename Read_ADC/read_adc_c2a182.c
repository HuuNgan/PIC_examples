#include <16F877.h>
#device ADC=8        //8bit conversion
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_D0, rcv=PIN_D1)    //lcd output

void main()
{
   int x2, x3;                        //input variable
   setup_adc(ADC_CLOCK_INTERNAL);   //adc clock
   setup_adc_ports(ALL_ANALOG);      //input combination
   
   while(1)
   {
      set_adc_channel(2);              //select RA2
      delay_ms(500);
      x2=read_adc();              //get input byte

      set_adc_channel(3);              //select RA2
      delay_ms(500);
      x3=read_adc();              //get input byte
   }
}
