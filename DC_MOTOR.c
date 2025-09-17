//DC MOTOR SPEED

#include<reg51.h>

//PINS for DC Motors
sbit EN=P1^0;
sbit IN1=P1^1;
sbit IN2=P1^2;

//Pins for switch
sbit SW1=P0^0; 
sbit SW2=P0^1;

//FORWARD Declarations
void delay(int);
void timer_5ms();
void timer_10ms();
void timer_15ms();
void timer_20ms();
void timer_start_stop();

void main()
{
	int count=0;
	
	TMOD=0X10; //Timer 1 mode 1
	
	SW1=1;SW2=1; //Two switches are off
	while(1)
	{
		if(SW1==0)
	{
		delay(75);
		
		if(count<=4)
		{
			count++;
		}
	}
  if(SW2==0)
	{
		delay(75);
		
		if(count>0)
		{
			count--;
		}
	}
	
	
	//25% Duty Cycle 
	if(count==1)
	{
		IN1=1;
		IN2=0;
		EN=1;
		timer_5ms();
		EN=0;
		timer_15ms();
	}
	
	//50% Duty Cycle 
	else if(count==2)
	{
		IN1=1;
		IN2=0;
		EN=1;
		timer_10ms();
		EN=0;
		timer_10ms();
	}
	
	
	//75% Duty Cycle 
	else if(count == 3)
	{
		IN1=1;
		IN2=0;
		EN=1;
		timer_15ms();
		EN=0;
		timer_5ms();		
	}
	
	
	//100% Duty Cycle 
	else if(count == 4)
	{
		IN1=1;
		IN2=0;
		EN=1;
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

void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<1000;j++)
		{
		}
	}
}
