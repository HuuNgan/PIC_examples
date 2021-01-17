//SPI master program
#include <16F877A.h>
void main()
{
    int number;
    setup_spi(spi_master);      //spi master mode
    
    while(1)
    {
        number = spi_read();    //read spi input BCD
        spi_write(number);
    }
}