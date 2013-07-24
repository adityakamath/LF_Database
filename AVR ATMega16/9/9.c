#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include "lcd.h"
unsigned char l=0,r=0,m=0,b=0,count=0;
void main()
{ DDRD=0x0E;
  DDRA=0x00;
  lcd_init();
  DDRA=0x00;
  DDRB=0x0f;
  ADMUX=0x20;
  ADCSRA=0x87;
  while(1)
  { l=0;
    r=0;
    m=0;
	b=0;
	
    ADMUX=0x20;  //right
    ADCSRA|=0x40;
    while(ADCSRA&(1<<ADSC));
	if(ADCH>200)
	r=1;
	
	ADMUX=0x21;  //middle
    ADCSRA|=0x40;
    while(ADCSRA&(1<<ADSC));
	if(ADCH>200)
	m=1;
	
	ADMUX=0x22;  //left
    ADCSRA|=0x40;
    while(ADCSRA&(1<<ADSC));
	if(ADCH>200)
	l=1;
	
	ADMUX=0x23;
	ADCSRA|=0x40;
	while(ADCSRA&(1<<ADSC));
	if(ADCH>200)
	b=1;
	
	if((l==1) && (m==1) && (r==0)) // simple right
	{ PORTB=0b00000001;
	}
	
	if((l==0) && (m==1) && (r==1))// simple left // looking from backside
	{ PORTB=0b00000100;
	}
	if((l==1) && (m==0) && (r==1))  //straight  wbw
	{ PORTB=0b00000101;
	}
	if((l==1) && (m==0) && (r==0)) // sharp right
	{ PORTB=0b00001001;
	  //if((l==0)&&(m==0)&&(r==0)&&(b==1))
	  //{ PORTB=0b00001001;
	   // _delay_ms(200);
	  //}
	}
	if((l==0) && (m==0) && (r==1)) //sharp left
	{ PORTB=0b00000110;
	  _delay_ms(100);
	  /*if((l==0)&&(m==0)&&(r==0)&&(b==1))
	  { PORTB=0b00000110;
	    _delay_ms(200);
	  }*/
	}
	if((l==0) && (r==0) && (m==0) && (b==0))
	{ PORTB=0b00000101;
	  count++;
	  PORTD=(1<<count);
	  _delay_ms(200);
	}
	if((PINA&(1<<7))==0)
	{ PORTB=0x00;
	}
	lcd_gotoxy(0,0);
	lcd_showvalue(r);
	lcd_gotoxy(0,5);
	lcd_showvalue(m);
	lcd_gotoxy(0,9);
	lcd_showvalue(l);
	lcd_gotoxy(1,0);
	lcd_showvalue(b);
	lcd_gotoxy(1,6);
	lcd_showvalue(count);
	//_delay_ms(200);
  }
}
