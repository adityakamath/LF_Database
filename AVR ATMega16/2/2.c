 

//connect the left sensors on CN3 and right one on CN2

// defines the clock speed
#define F_CPU 1600000UL
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
DDRB=0b11111111; //PORTB as output Port connected to motors
DDRC=0b0000000; //PORTC Input port connected to Sensors



int left_sensor=0, right_sensor=0, up_sensor=0;
int i=0;

 while(1) // infinite loop
 {
     left_sensor=PINC&0b0010000; // mask PC4 bit of Port C
     right_sensor=PINC&0b0100000;// mask PC3 bit of Port C
	 up_sensor=PINC&0b0001000;//mask PC5 bit of Port C
	 
	 if((left_sensor==0b0000000) & (right_sensor==0b0000000) & (up_sensor==0b0000000)) //if both sensors "off"
              {
                 PORTB=0b00001010; // straight
				// _delay_ms(255);
				// _delay_ms(255);
		
               }
 

      if((left_sensor==0b0010000) & (right_sensor==0b0100000) & (up_sensor==0b0000000)) //if both sensors "on"
              {
                 PORTB=0b00001010; // move straight
                
               }

           
       if((left_sensor==0b0000000) & (up_sensor==0b0000000))
  
            {
                    PORTB=0b00001000;
               if((left_sensor==0b0000000) & (right_sensor==0b0000000) & (up_sensor==0b0000000)) //if both sensors "off"
               {
                 PORTB=0b00001010; // straight
		        }
			}	

       
        if((right_sensor==0b0000000) &  (up_sensor==0b0000000))
           {
		    
           PORTB=0b00000010;

             if((left_sensor==0b0000000) & (right_sensor==0b0000000) & (up_sensor==0b0000000)) //if both sensors "off"
              {
                 PORTB=0b00001010; // straight
		       }

            }         
                    
			 

	   			if((left_sensor==0b0000000)&(right_sensor==0b0100000) &  (up_sensor==0b0000000))
              {
                 PORTB=0b00001000;
		         		                           // turn left
	           

              }


	   			if((left_sensor==0b0000000)&(right_sensor==0b0100000) &  (up_sensor!=0b0000000))
              {
                 PORTB=0b00001000;
		         		                           // turn left
	           

              }



			if((left_sensor==0b0010000)&(right_sensor==0b0000000) &  (up_sensor==0b0000000))
              {
                 
                 PORTB=0b00000010;
				// turn right and move straight
                 
               }

             	if((left_sensor==0b0010000)&(right_sensor==0b0000000) &  (up_sensor!=0b0000000))
              {
                 
                 PORTB=0b00000010;
				// turn right and move straight
                 
               }
	
	

  }

  
  
 }
