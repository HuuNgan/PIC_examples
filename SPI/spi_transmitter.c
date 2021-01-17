//SPI transmitter program
#include <16F877A.h>
void main()
{
    int sendnum;
    setup_spi(spi_slave);       //spi slave mode
    while(1)
    {
        sendnum = input_D();    //get BCD input
        spi_write(sendnum);     //send BCD code to master
    }
}