#include <avr/io.h>
#include <util/delay.h>
#include <compat/deprecated.h>

void forward(void);
void forward1(void);
void backward(void);
void left(void);
void right(void);
void stop(void);

void InitADC()
{
	ADMUX=(1<<REFS0);                         				// For Aref=AVcc;
	ADCSRA=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS0); 	//Prescalar div factor =128
}

uint16_t ReadADC(uint8_t ch)
{
   //Select ADC Channel ch must be 0-7
   //ch=ch&0b00000001;
   ADMUX|=(1<<MUX0)|(1<<MUX1)|(1<<MUX2);
   //ADMUX|=(1<<MUX0);

   //Start Single conversion
   ADCSRA|=(1<<ADSC);

   //Wait for conversion to complete
   while(!(ADCSRA && (1<<ADIF)));

   //Clear ADIF by writing one to it
   //Note you may be wondering why we have write one to clear it
   //This is standard way of clearing bits in io as said in datasheets.
   //The code writes '1' but it result in setting bit to '0' !!!

   ADCSRA|=(1<<ADIF);

   return(ADC);
}
int count=0;
int main()
{
	
	DDRA=0x0F;
	PORTA=0x00;
	DDRB=0x00;
	PORTB=0xFF;
	DDRC=0xFF;
	DDRD=0XFF;
	sbi(PORTD,4);
	sbi(PORTD,5);
	InitADC();
	uint16_t adc_result;
	while(1)
	{	
		adc_result=	ReadADC(0);
		if(adc_result >= 750)
		{
			stop();
		}
		else
		{
			if(bit_is_set(PINB,4)&&bit_is_clear(PINB,2)&&bit_is_set(PINB,0))
				forward();
			else if(bit_is_clear(PINB,4)&&bit_is_clear(PINB,2)&&bit_is_set(PINB,0))
				left();
			else if(bit_is_clear(PINB,4)&&bit_is_set(PINB,2)&&bit_is_set(PINB,0))
				left();
			else if(bit_is_set(PINB,4)&&bit_is_clear(PINB,2)&&bit_is_clear(PINB,0))
				right();
			else if(bit_is_set(PINB,4)&&bit_is_set(PINB,2)&&bit_is_clear(PINB,0))	
				right();
			else if(bit_is_clear(PINB,6)&&bit_is_clear(PINB,5)&&bit_is_clear(PINB,4)&&bit_is_clear(PINB,3)&&bit_is_clear(PINB,2)&&bit_is_clear(PINB,1)&&bit_is_clear(PINB,0))
			{
				forward1();
			}
			else if(bit_is_set(PINB,4)&&bit_is_set(PINB,3)&&bit_is_set(PINB,2)&&bit_is_set(PINB,1)&&bit_is_set(PINB,0))
				backward();
			//else
			//{
				//backward();
			//}
			PORTA=count;
		
		}
		
	}
	return 0;
}

void backward(void)
{	
	
	cbi(PORTC,3);
	sbi(PORTC,2);
	cbi(PORTC,1);
	sbi(PORTC,0);
	_delay_ms(10);
}

void forward(void)
{	
	
	sbi(PORTC,3);
	cbi(PORTC,2);
	sbi(PORTC,1);
	cbi(PORTC,0);
	//_delay_ms(20);
}

void forward1(void)
{	
	count++;
	sbi(PORTC,3);
	cbi(PORTC,2);
	sbi(PORTC,1);
	cbi(PORTC,0);
	_delay_ms(50);
}

void right(void)
{	
	cbi(PORTC,3);
	cbi(PORTC,2);
	sbi(PORTC,1);
	cbi(PORTC,0);
	if((bit_is_set(PINB,4)&&bit_is_set(PINB,3)&&bit_is_set(PINB,2)&&bit_is_set(PINB,1)&&bit_is_set(PINB,0)))
	{	right();
		//_delay_ms(70);
	}	
	//stop();	
}

void left(void)
{
	sbi(PORTC,3);
	cbi(PORTC,2);
	cbi(PORTC,1);
	cbi(PORTC,0);
	if((bit_is_set(PINB,4)&&bit_is_set(PINB,3)&&bit_is_set(PINB,2)&&bit_is_set(PINB,1)&&bit_is_set(PINB,0)))
	{	left();
		//_delay_ms(70);
	}	
	//stop();	
}

void stop(void)
{
	cbi(PORTC,3);
	cbi(PORTC,2);
	cbi(PORTC,1);
	cbi(PORTC,0);
	//_delay_ms(20);
}	