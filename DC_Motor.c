#include<reg51.h>

sbit SW1=P3^0;  //SW1=P3.0
sbit SW2=P3^1; //SW2=P3.1

sbit IN1=P1^0;  //IN1=P1.0
sbit IN2=P1^1; //IN2=P1.1
sbit EN=P1^2; //EN=P1.2

void delay(int); //Forward Declaration

void main()
{
	SW1=1; //Switch1  is Off
	SW2=1; //Switch2 is off
	
	EN=0; //Enable is off
	IN1=0; //Input 1 is off
	IN2=0; //Input 2 is off 
	
	while(1) //Infinite loop
	{
		if(SW1==0) //SWitch 1 is On
		{
			delay(75); //calling delay
			EN=1;     //Enable on
			IN1=1;    //Input1 is on
			IN2=0;    // Input2 is off
		}
		else if(SW2==0)
		{ 
			delay(75); //calling delay
			EN=1;   //Enable is on
			IN1=0;  //Input1 is off
			IN2=1; //input2 is on
		}
	}
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
	
	
	