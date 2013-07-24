#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"lcd_16.h" //include lcd_16.h 
#include"lcd_16.c" //include lcd_16.c


void left();
void right();
void forward();
void stop();
void sharp_left();
void sharp_right();
void count_if_black();
void count_if_blackright();
void count_if_blackleft();

int main()
{

	int flag=0;



char s[5];


	DDRC=0XFF;	// L293D CONNECTIONS ON PORT C
	DDRA=0X00;		// INPUT COS SENSORS ARE CONNECTED TO PORT A sensor array
	DDRD=0XC0;  // ENABLE PIN OF L293D and making few pins input
	//PORTD=0XC0;
	PORTD=(1<<PD7) | (1<<PD6) ;

	unsigned char a;
	a= PIND& 0b00100000;
	DDRB=0X00;	// ir wall sensors
	//unsigned char ch, chb;
	//int flag=0,count=0;
	//chb=PINA& 0b00000001;
	while(1)
	{
		//ch=PINB & 0b11111110;			//  sensor array
	//	a= PIND& 0b00100000;
		//chb=PINA &0b00000001;			//  wall sensors


		if( bit_is_set (PINA,7) && bit_is_set (PINA,6) && bit_is_set (PINA,2) && bit_is_set (PINA,1) )
		{	
			forward();
		}
			
		if( bit_is_clear (PINA,2)  && bit_is_set (PINA,1) )
		{
			//right();
			left();
		}

		if( bit_is_clear (PINA,6)  && bit_is_set (PINA,7) )
		{
			//left();
			right();
		}

		if( bit_is_clear (PINA,2)  && bit_is_clear (PINA,1) )
		{
			//sharp_right();
			sharp_left();
		}




		if( bit_is_clear (PINA,6)  && bit_is_clear (PINA,7) )
		{
			//sharp_left();
			sharp_right();
		}


		if( bit_is_clear (PINA,2) && bit_is_clear (PINA,3) && bit_is_clear (PINA,4) && bit_is_clear (PINA,5) && bit_is_clear (PINA,6) )
		{
			forward();
		//	count++;
		}
		int count=0;
		char s[5];

		if( bit_is_clear (PINA,1) && bit_is_clear (PINA,2) && bit_is_clear (PINA,3) && bit_is_clear (PINA,4) && bit_is_clear (PINA,5) && bit_is_clear (PINA,6) && bit_is_clear (PINA,7) )
		{
			forward();

			lcd_init(LCD_DISP_ON);

DDRD=0x00;
PORTD=0xff;
;
		itoa(count, s, 10);
		lcd_clrscr();
		lcd_puts(s);

		count++;
		}


		// other conditions


		if( bit_is_clear (PINA,2)  && bit_is_clear (PINA,1)  && bit_is_set(PINA,7))  //this is not essential
		{

			sharp_left();
		}
		
		
		if( bit_is_clear (PINA,6)  && bit_is_clear (PINA,7) && bit_is_set(PINA,1) )
		{
			sharp_right();
		}


		if( bit_is_set(PINA,1) &&  bit_is_clear (PINA,2) && bit_is_clear (PINA,3) && bit_is_clear (PINA,4) && bit_is_clear (PINA,5) && bit_is_clear (PINA,6) && bit_is_clear(PINA,7) ) 
		{
			sharp_right();
		}

		if( bit_is_set(PINA,7) &&  bit_is_clear (PINA,2) && bit_is_clear (PINA,3) && bit_is_clear (PINA,4) && bit_is_clear (PINA,5) && bit_is_clear (PINA,6) && bit_is_clear(PINA,1) ) 
		{
			sharp_left();
		}
	
		if( bit_is_set(PINA,1) && bit_is_set (PINA,2) && bit_is_set (PINA,3) && bit_is_set (PINA,4) && bit_is_set (PINA,5) && bit_is_set (PINA,6) && bit_is_set(PINA,7))
		{
			stop();
		}
		
		if( bit_is_set(PINA,1) && bit_is_set (PINA,2) && bit_is_set (PINA,3) && bit_is_set (PINA,4) && bit_is_set (PINA,5) && bit_is_set (PINA,6) && bit_is_clear(PINA,7))
		{
			sharp_right();
		}

		if( bit_is_clear(PINA,1) && bit_is_set (PINA,2) && bit_is_set (PINA,3) && bit_is_set (PINA,4) && bit_is_set (PINA,5) && bit_is_set (PINA,6) && bit_is_set(PINA,7))
		{
			sharp_left();
		}
		if( bit_is_clear (PINA,1) && bit_is_clear (PINA,2) && bit_is_clear (PINA,3) && bit_is_set (PINA,4) && bit_is_set (PINA,5) && bit_is_clear (PINA,6) && bit_is_clear (PINA,7) )
		{
			sharp_right();
		
		}

		if( bit_is_clear (PINA,1) && bit_is_clear (PINA,2) && bit_is_set (PINA,3) && bit_is_set (PINA,4) && bit_is_clear (PINA,5) && bit_is_clear (PINA,6) && bit_is_clear (PINA,7) )
		{
			count_if_blackleft();
		
		}
//

		if( bit_is_set(PINA,1) && bit_is_set (PINA,2) && bit_is_clear (PINA,3) && bit_is_clear (PINA,4) && bit_is_set (PINA,5) && bit_is_set (PINA,6) && bit_is_set(PINA,7))
		{
			//forward();
			count_if_blackforward();
		}

		if( bit_is_set(PINA,1) && bit_is_set (PINA,2) && bit_is_set (PINA,3) && bit_is_clear (PINA,4) && bit_is_clear (PINA,5) && bit_is_set (PINA,6) && bit_is_set(PINA,7))
		{
			count_if_blackforward();
			//forward();
		}
//
		if( bit_is_set (PIND,5) )
		{
			stop();
			break;
		}
		
		if(flag==1)
		count++;
			lcd_init(LCD_DISP_ON);

DDRD=0x00;
PORTD=0xff;
;
		itoa(count, s, 10);
		lcd_clrscr();
		lcd_puts(s);

	}







lcd_init(LCD_DISP_ON);
lcd_clrscr();
	_delay_ms(5000);
lcd_puts(s);


	while(1);
}


void left()
{
	PORTC=0X02;   //0000 0010 ie 1motor stop 1 moving frwd
	_delay_ms(5);
	flag=0;
}

void right()
{
	PORTC=0X04;
	_delay_ms(5);
	flag=0;
}

void forward()
{
	PORTC=0X06; //01 10
	_delay_ms(5);
	flag=0;
}
void slow_forward()
{
	PORTC=0X06;
	_delay_ms(1);
	flag=0;
}

void stop()
{
	PORTC=0X00;
	_delay_ms(1500);
	flag=0;
}



void sharp_left()
{
	PORTC=0X0A;   //0000 1010 ie 1motor stop 1 moving frwd
	_delay_ms(5);
	flag=0;
}

void sharp_right()
{
	flag=0;
	PORTC=0X05;  //0000  0101
	_delay_ms(5);
}

void count_if_blackforward()
{
     flag=1;
	 forward();
}
void count_if_blackright()
{
	flag=1;
	right();
}
void count_if_blackleft()
{
	flag=1;
	left();
}














