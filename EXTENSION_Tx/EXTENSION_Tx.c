#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

void main()
{
DDRB&=~(1<<0);
DDRB&=~(1<<1);
DDRB&=~(1<<2);
DDRB&=~(1<<3);
DDRB&=~(1<<4);

PORTB|=(1<<0);
PORTB|=(1<<1);
PORTB|=(1<<2);
PORTB|=(1<<3);
PORTB|=(1<<4);

    MCUCSR=0x80;
	MCUCSR=0x80;
	USARTInit(95);
	InitLCD(0);
	LCDClear();
	LCDWriteString("Welcome");
  // _delay_ms(5000);
   //_delay_ms(5000);
	LCDClear();
	LCDWriteString("Ready To Transmit");
	LCDClear();
	while(1)
	{
        if((!(PINB&1))&&(PINB&2)&&(PINB&4)&&(PINB&8))
		{
	    LCDClear();
		LCDWriteStringXY(0,0,"Main ON");
		USARTWriteChar('a');
		_delay_ms(20);
		}
		else if((PINB&1)&&(!(PINB&2))&&(PINB&4)&&(PINB&8))
		{
	    LCDClear();
		LCDWriteStringXY(0,0,"PORT 1 ON");
		USARTWriteChar('b');
		_delay_ms(20);
        }
		else if((PINB&1)&&(PINB&2)&&(!(PINB&4))&&(PINB&8))
		{
	    LCDClear();
		LCDWriteStringXY(0,0,"PORT 2 ON");
		USARTWriteChar('c');
		_delay_ms(20);
        }
		else if	((PINB&1)&&(PINB&2)&&(PINB&4)&&(!(PINB&8)))
		{
		LCDClear();
		LCDWriteStringXY(0,0,"PORT 3 ON");
		USARTWriteChar('d');
    	_delay_ms(20);
		}
		else 
		{
		LCDClear();
		LCDWriteStringXY(0,0," STOP");
		USARTWriteChar('e');
    	_delay_ms(1000);
		}
	
    }
}
