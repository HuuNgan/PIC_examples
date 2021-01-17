#include <16F877.h>
#use delay(clock=20000000)
#include <lcd.c>
void main()
{
    char text[]="Embedded System";
    char *ptr;
    set_tris_d(0x00);
    lcd_init();
    ptr = text;
    lcd_gotoxy(1,2);
    printf(lcd_putc, "%s", text);
    
    while(1);
}
