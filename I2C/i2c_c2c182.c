#include <16F877.h>
#use delay(clock=4000000)
#use i2c(MASTER, SCL=PIN_C3, SDA=PIN_C4)

void main()
{
    int sendbyte, lowadd;
    lowadd=0;
    port_b_pullups(1);
    sendbyte = 0x0F;

    while(1)
    {
        i2c_start();            //start write cycle
        i2c_write(0xA0);        //send control byte
        i2c_write(0x00);        //send high address
        i2c_write(lowadd);      //send low address
        i2c_write(sendbyte);    //send data
        i2c_stop();

        delay_ms(5);        //wait for write
        lowadd++;           //inc address
    }
}
