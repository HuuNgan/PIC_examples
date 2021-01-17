#include <16F877.h>
#use delay(clock=20000000)
// #use fast_io(D)

#include <lcd.c>
void main()
{
    char text1[]="Hello World";
    char text2[]="Number:";
    char text3[]="0123456789";
    char *ptr;
    set_tris_d(0x00);
    lcd_init();
    ptr = text3;
    lcd_gotoxy(1,1);
    printf(lcd_putc, "%s", text1);
    lcd_gotoxy(1,2);
    printf(lcd_putc, "%s", text2);
    while(1)
    {
        if(*ptr==0)    ptr=text3;
            lcd_gotoxy(8,2);
            lcd_putc(*ptr++);
            delay_ms(100);
    }
}
