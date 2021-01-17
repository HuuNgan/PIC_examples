//SPI receiver program
#include <16F877A.h>
void main()
{
    int recnum;
    setup_spi(spi_slave);       //spi slave mode
    while(1)
    {
        recnum = spi_read();    //read BCD code of spi port
        output_D(recnum);       //display it
    }
}