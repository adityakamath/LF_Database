#include<avr/io.h>
#include<util/delay.h>
#include<compat/deprecated.h>
#define checkbit(value,position)  (value&(1<<position))
void motorALL_ON(void);
void motorALL_OFF(void);
void motor1_Forward(void);
void motor2_Forward(void);
void motor2_OFF(void);
void motor1_OFF(void);
void turnright( void);
void turnleft(void);
  
  int j=0; 
void main()
{

DDRA=0XFF;
DDRC=0xFF;
//PORTC=0XFF;           //led 
                    // PORT F Initialization
DDRF=0x00;
PORTF=0xFF;            //SENSOR


DDRB=0XF0;


DDRE=0x0F;  //motor enable
int i=PINF;
    
while(1)
   { 
 
 if(checkbit(i,4)==0)
  {
  PORTA=0X00;
   
   if(( checkbit(i,6)==0 && checkbit(i,7)!=0 && checkbit(i,5)!=0) || (checkbit(i,6)==0 && checkbit(i,7)==0 && checkbit(i,5)!=0))
		turnright();
  
	else if(( checkbit(i,6)!=0 && checkbit(i,7)!=0 && checkbit(i,5)==0) || (checkbit(i,6)!=0 && checkbit(i,7)==0 && checkbit(i,5)==0))

          turnleft();
		  
  else if(checkbit(i,5)==0 && checkbit(i,7)!=0 && checkbit(i,6)==0)                               
	{
		motorALL_ON();
		motor2_Forward();   
	   motor1_Forward();
		//PORTC=0x00;
		
			 if ((checkbit(i,6)!=0 && checkbit(i,7)!=0 && checkbit(i,5)!=0)||(checkbit(i,6)!=0 && checkbit(i,7)==0 && checkbit(i,5)!=0))  //THE CROSSOVER DETECTED
                {
					
				               
                              motorALL_ON();
                               motor2_Forward();   
							   motor1_Forward();
								j++;
							  
								/*lcd_gotoxy2(5);
								lcd_showvalue(j);*/
								PORTC=~j;
								_delay_ms(500);	
								
				}
	}
}						
	else
	 {
	    PORTA=0X0A;
        //_delay_ms(500);
        //PORTA=0X00; 
        motor2_OFF();
		motor1_OFF();
		motorALL_OFF();
		
		}

     }
  
}
void motorALL_ON(void)
{
sbi(PORTB,4);

}

void motorALL_OFF(void)
{
cbi(PORTB,4);
}

void motor1_Forward(void)
{
sbi(PORTB,5);
cbi(PORTB,6);
}


void motor2_Forward(void)
{
sbi(PORTE,3);
cbi(PORTE,2);
}




void motor2_OFF(void)
{
cbi(PORTE,2);
cbi(PORTE,3);
}

void motor1_OFF(void)
{
cbi(PORTB,5);
cbi(PORTB,6);
}
void turnright( void)
{
                          motorALL_ON();
                               
                                motor1_Forward(); 
								motor2_OFF();
								if ((checkbit(PINF,6)!=0 && checkbit(PINF,7)!=0 && checkbit(PINF,5)!=0)||(checkbit(PINF,6)!=0 && checkbit(PINF,7)==0 && checkbit(PINF,5)!=0))  //THE CROSSOVER DETECTED
                {
					
				               
                              
								j++;
							  
								/*lcd_gotoxy2(5);
								lcd_showvalue(j);*/
								PORTC=~j;
								_delay_ms(500);	
								
				}
								//PORTC=0x01;

if(((checkbit(PINF,6)==0) && (checkbit(PINF,7)==0) && (checkbit(PINF,5)==0)||(checkbit(PINF,6)!=0) && (checkbit(PINF,7)!=0) && (checkbit(PINF,5)!=0)) )
turnright();
}

void turnleft(void)
{

    motorALL_ON();
   motor2_Forward(); 
motor1_OFF();
if ((checkbit(PINF,6)!=0 && checkbit(PINF,7)!=0 && checkbit(PINF,5)!=0)||(checkbit(PINF,6)!=0 && checkbit(PINF,7)==0 && checkbit(PINF,5)!=0))  //THE CROSSOVER DETECTED
                {
					
				               
                              
								j++;
							  
								/*lcd_gotoxy2(5);
								lcd_showvalue(j);*/
								PORTC=~j;
								_delay_ms(500);	
								
				}
//PORTC=0x02;
if((checkbit(PINF,6)==0) && (checkbit(PINF,7)==0) && (checkbit(PINF,5)==0)||(checkbit(PINF,6)!=0) && (checkbit(PINF,7)!=0) && (checkbit(PINF,5)!=0)) 
turnleft();
}