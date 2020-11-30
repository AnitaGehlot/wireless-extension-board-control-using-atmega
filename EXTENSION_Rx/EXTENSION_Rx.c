#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

void main()
{
    MCUCSR=0x80;;
	MCUCSR=0x80;
	USARTInit(95);
	InitLCD(0);
	LCDClear();
    LCDWriteString("Welcome");
	_delay_ms(2000);
	LCDClear();
	LCDWriteString("Ready To Receiver");
	_delay_ms(2000);
	LCDClear();
	char data;
	DDRB=0xFF;
	while(1)
	{
	data= USARTReadChar();
	if(data=='a')
	   {
	    LCDClear();
		LCDWriteStringXY(0,0,"Main ON");
		PORTB=0b00000001;
		_delay_ms(10);
    	}
	else if(data=='b')
	   {
	    LCDClear();
		LCDWriteStringXY(0,0,"PORT 1 ON");
		PORTB=0b00000010;
		_delay_ms(10);
    	}
	else if(data=='c')
	   {
	    LCDClear();
		LCDWriteStringXY(0,0,"PORT 2 ON");
	    PORTB=0b00000100;
		_delay_ms(10);
    	}
	else if (data=='d')
	   {
	    LCDClear();
		LCDWriteStringXY(0,0,"PORT 3 ON");
	    PORTB=0b00001000;
    	_delay_ms(10);
    	}
	else if (data=='e')
	   {
	    LCDClear();
		LCDWriteStringXY(0,0,"STOP");
	    PORTB=0b00000000;
    	_delay_ms(1000);
    	}
	}
}
