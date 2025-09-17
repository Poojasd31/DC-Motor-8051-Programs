//DC MOTOR SPEED CONTROL WITH 25%,50%,75% AND 100%Duty Cycle usingg functions

#include<reg51.h>

//EN = P1.0, IN1=P1.1 AND IN2=P1.2
sbit EN=P1^0;
sbit IN1=P1^1;
sbit IN2=P1^2;

//Switches
sbit SW1=P0^0; //SW1=P0.0
sbit SW2=P0^1; //SW2=P0.1
sbit SW3=P0^2; //SW3=P0.2
sbit SW4=P0^3; //SW1=P0.3

//FORWARD Declarations
void timer_5ms();
void timer_10ms();
void timer_15ms();
void timer_20ms();
void timer_start_stop();

void main()
{
	TMOD = 0X10; //TIMER 1 MODE 1
	
	//ALL SWITCHES ARE INITIALLY OFF
	SW1=1; SW2=1;SW3=1 ; SW4=1;
	
	//25% Duty Cycle if Switch one is pressed
	if(SW1 == 0)
	{
		IN1=1;
		IN2=0;
		EN=1;
		timer_5ms();
		EN=0;
		timer_15ms();		
	}
	
	//50% Duty Cycle if Switch two is pressed
	else if(SW2 == 0)
	{
		IN1=1;
		IN2=0;
		EN=1;
		timer_10ms();
		EN=0;
		timer_10ms();		
	}
	
	//75% Duty Cycle if Switch 3 is pressed
	else if(SW3 == 0)
	{
		IN1=1;
		IN2=0;
		EN=1;
		timer_15ms();
		EN=0;
		timer_5ms();		
	}
	
	//25% Duty Cycle if Switch one is pressed
	else if(SW4 == 0)
	{
		IN1=1;
		IN2=0;
		EN=1;
		timer_20ms();		
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
	TL1 = 0XFF,;
	timer_start_stop();
}

	

	
	