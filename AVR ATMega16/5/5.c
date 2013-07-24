#include<avr/io.h>
#include<avr/delay.h>
#include<avr/interrupt.h>
main()
{	
	DDRC=255;
	DDRD=255;
	DDRA=0;
	DDRB=0b11001111;
	//pwm_init();

	PORTD=0b11110000;
	PORTB|=0b10000000;
	int c = 0;
	PORTD=255;

	while(1)
	{	/*PORTC=0;
		_delay_ms(200);
		PORTD&=0b11110000;
		PORTD|=c;

		if(PINB&0b00100000==0b00000000);
		//break;
		*/
		if(	((PINA)&(0b10011001))   ==   0b00001000)
				PORTC=0b10000000;
		if(	((PINA)&(0b10011001))   ==   0b00011000)
				PORTC=0b10010000;		
		if(	((PINA)&(0b10011001))	==   0b00010000)
				PORTC=0b00010000;
		
 
			
		

				

	

		if(PINA&0b10011001==0b00011001)
		{	_delay_ms(400);	
			PORTC=10100000;
			_delay_ms(400);
			while(PINA&0b10011001!=0b00010000)
			{
				PORTC=0b10100000;
			}
			PORTC=0b10010000;
		}
		
		if(PINA&0b10011001==0b10011000)
		{	_delay_ms(400);
			PORTC=0b01010000;
			_delay_ms(300);
			while(PINA&0b10011001!=0b00001000)
			{
				PORTC=0b01010000;
			}
			PORTC=0b10010000;
		}

		if(PINA&0b10011001==0b10011001)
		{
			c++;
		}
		
	}
}
