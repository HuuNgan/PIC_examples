#include <16F877.h>
#device ADC=8
#use delay(clock=4000000)
#use rs232(baud=9600, xmit=PIN_D0, rcv=PIN_D1)

void main()
{
    int chan;
    float analin[8], disvolts[8];

    setup_adc(ADC_CLOCK_INTERNAL);
    setup_adc_ports(AN0_AN1_AN2_AN4_AN5_AN6_AN7_VSS_VREF);
    while(1)
    {
        for(chan=0; chan<8; chan++)
        {
            delay_ms(1000);
            set_adc_channel(chan);
            analin[chan] = read_adc(0);
            disvolts[chan] = (analin[chan])/400;
            putc(254);
            putc(1);
            delay_ms(10);
            // printf("RA%d = %4.3g",chan,disvolts|chan|);
            printf("RA%d = %d",chan,disvolts||chan);
        }
    }
}
