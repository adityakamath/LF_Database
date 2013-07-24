 

//connect the left sensors on CN3 and right one on CN2

// defines the clock speed
#include<avr/io.h>
#include<util/delay.h>

int main(void)
{
DDRB=0b11111111; //PORTB as output Port connected to motors
DDRC=0b0000000; //PORTC Input port connected to Sensors



int left_sensor=0, right_sensor=0;
int count=0;
int c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0,c10=0,c11=0,c12=0,c13=0,c14=0,c15=0;

while(1) // infinite loop
{
     left_sensor=PINC&0b0010000; // mask PC4 bit of Port C
     right_sensor=PINC&0b0100000;// mask PC5 bit of Port C
	 
	
	if((left_sensor==0b0000000) & (right_sensor==0b0000000) ) //if both sensors "off"
     {
	 //if(count<0x03)

	 
		
	 	if((count==1)&(c2==1)&(c3==1)&(c4==1)&(c5==1)&(c6==1)&(c7==1)&(c8==1)&(c9==1)&(c10==1)&(c11==1)&(c12==1)&(c13==1)&(c14==1)&(c15==1))
	 	{	PORTB=0b00000000;}
		else
		{
		PORTB=0b00101010; 
		c15=c14;
		c14=c13;
		c13=c12;
		c12=c11;
		c11=c10;
		c10=c9;
		c9=c8;
		c8=c7;
		c7=c6;
		c6=c5;
		c5=c4;
		c4=c3;
		
		c3=c2;
		c2=count;
		count=1;

	}
		while((left_sensor==0b0000000) & (right_sensor==0b0000000) )
		{_delay_ms(500);
		PORTB=0b00101010;
		_delay_ms(500);
			left_sensor=PINC&0b0010000; // mask PC4 bit of Port C
     		right_sensor=PINC&0b0100000;// mask PC5 bit of Port C
		}
	//else
	//	PORTB=0b00101010;
	
	


				
	}
          if((left_sensor==0b0010000) & (right_sensor==0b0100000)) //if both sensors "on"
              {	 _delay_ms(700);
	 PORTB=0b00000000;
	 _delay_ms(300);;
                 PORTB=0b00101010; // move straigh
               
               }
			if((left_sensor==0b0000000)&(right_sensor==0b0100000))
              {


                 PORTB=0b00000010; // turn left

PORTB=0b0000010;

               }
			                       if((left_sensor==0b0010000)&(right_sensor==0b0000000))
              {
                 PORTB=0b00101000; // turn right


                 ; // turn left
				PORTB=0b00101000;

               }
			 


 
 
 }}


