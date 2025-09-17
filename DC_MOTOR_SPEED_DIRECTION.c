//DC Motor with Interrupts...1- for speed and 2- for Direction

#include<reg51.h>

#define LED P0//port 0= led

//PINS for DC Motors
sbit EN=P1^0;
sbit IN1=P1^1;
sbit IN2=P1^2;

int count=0;
bit dir = 0;//For Direction Control


//FORWARD Declarations

void timer_5ms();
void timer_10ms();
void timer_15ms();
void timer_20ms();
void timer_start_stop();

//INTERRUPT FOR SPEED CONTROL 
void Interrupt_Increment(void) interrupt 0
{
	if(count<=4)
	{
		count++;
	}
	if(count>4)
	{
		count=0;
	}
}

//INTERRUPT FOR DIRECTION CONTROL
void Interrupt_Decrement(void) interrupt 2
{
	dir = ~dir;
}

void main()
{
	
	
	TMOD=0X10; //Timer 1 mode 1
	
	IE = 0X85; //Interrupt Enable Register
	
	//TCON Register
	IT0=1;
	IT1=1;
	
	LED = 0X00; //led's are off
	
	
	
	while(1)
	{
		
	//25% Duty Cycle 
	if(count==1)
	{
		LED=0X01;
		
		EN=1;
		if(dir==0)
		{
			IN1=1;
		  IN2=0;
		}
		else
		{
			IN1=0;
		  IN2=1;
		}
		timer_5ms();
		EN=0;
		timer_15ms();
	}
	
	//50% Duty Cycle 
	else if(count==2)
	{
		LED=0X02;
		EN=1;
		if(dir==0)
		{
			IN1=1;
		  IN2=0;
		}
		else
		{
			IN1=0;
		  IN2=1;
		}
		timer_10ms();
		EN=0;
		timer_10ms();
	}
	
	
	//75% Duty Cycle 
	else if(count == 3)
	{
		LED=0X04;
		EN=1;
		if(dir==0)
		{
			IN1=1;
		  IN2=0;
		}
		else
		{
			IN1=0;
		  IN2=1;
		}
		timer_15ms();
		EN=0;
		timer_5ms();
	}
	
	
	//100% Duty Cycle 
	else if(count == 4)
	{
		LED=0X08;
		EN=1;
		if(dir==0)
		{
			IN1=1;
		  IN2=0;
		}
		else
		{
			IN1=0;
		  IN2=1;
		}
		timer_20ms();
		
	}
 }
}

void timer_start_stop()
{
	TR1=1;//START THE TIMER
	while(TF1 == 0);
	TR1=0;//STOP THE TIMER
	TF1=0;//clear the overflow flag
}

void timer_5ms()
{
	TH1 = 0XEE;
	TL1 = 0X00;
	timer_start_stop();
}

void timer_10ms()
{
	TH1 = 0XDC;
	TL1 = 0X0D;
	timer_start_stop();
}

void timer_15ms()
{
	TH1 = 0XCA;
	TL1 = 0X00;
	timer_start_stop();
}

void timer_20ms()
{
	TH1 = 0XB7;
	TL1 = 0XFF;
	timer_start_stop();
}


