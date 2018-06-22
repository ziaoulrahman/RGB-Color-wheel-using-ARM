#include <stdint.h>
#include <stdlib.h>
#include "tm4c123gh6pm.h"

#define SYSCTL_RCGC2_R         (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOF     0X00000020    //PortF
#define GPIO_PORTF_DATA_R      (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R       (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R       (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AFSEL_R     (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_LOCK_R			 (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_PUR_R       (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_CR_R        (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
	
#define SYSCTL_RCGC2_R         (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOA     0X00000001    //PortA
#define GPIO_PORTA_DATA_R      (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R       (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_DEN_R       (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_AFSEL_R     (*((volatile unsigned long *)0x40004220))
#define GPIO_PORTA_PUR_R       (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_CR_R        (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
	
void lag(int second);

void PortF_Init(void){ 
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
  delay = SYSCTL_RCGC2_R;           // reading register adds a delay   
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0 
	
} 


void lag(int second) // lag function
	{
		int m=1,n=1;
		for(m=1;m<=second;m++)
			for(n=1;n<=500 ;n++){
			}
		}
	
int main(void)
{
	unsigned long sw1,sw2;
	
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; //activate for port F

GPIO_PORTF_DATA_R = 0;

int cond = 0;

GPIO_PORTF_DIR_R = 0x0E;

GPIO_PORTF_PUR_R = 0x11U;

GPIO_PORTF_LOCK_R = 0x4C4F434B;

GPIO_PORTF_CR_R = 0x1F;

GPIO_PORTF_AMSEL_R = 0x00;

GPIO_PORTF_PCTL_R = 0x00000000;

GPIO_PORTF_DIR_R = 0x0E;

GPIO_PORTF_AFSEL_R = 0x00;

GPIO_PORTF_DEN_R = 0xff;
	
	 PortF_Init();  
	SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;
	
	GPIO_PORTF_DATA_R = 0;

	int count1=0;
	int count2=100;
	int j;
  
		 while(1){
		
		 j=0;
			 while (j<=100)
		{
		GPIO_PORTF_DIR_R = 0x08; // green   
		GPIO_PORTF_DEN_R = 0x08;
		GPIO_PORTF_DATA_R &= 0x08;   
	  lag(count2);
		count2++;
			
		GPIO_PORTF_DIR_R = 0x0A;  //sari    
		GPIO_PORTF_DEN_R = 0x0A;
		GPIO_PORTF_DATA_R = 0x0A;
	  lag(count1);
		count1--;
			
		j++;
		}
		
		 j=0;
			 while (j<=100)
				 {
		GPIO_PORTF_DIR_R = 0x02;  // red     
		GPIO_PORTF_DEN_R = 0x02;
		GPIO_PORTF_DATA_R &= 0x02;   
	  lag(count2);
		count2--;
			
		GPIO_PORTF_DIR_R = 0x0A; // yellow    
		GPIO_PORTF_DEN_R = 0x0A;
		GPIO_PORTF_DATA_R = 0x0A;
	  lag(count1);
		count1++;
			
		j++;	
		}	
		
		 j=0;
			 while (j<=100)
		{
		GPIO_PORTF_DIR_R = 0x04;   // koyu mavi    
		GPIO_PORTF_DEN_R = 0x04;
		GPIO_PORTF_DATA_R &= 0x04;   
	  lag(count2);
		count2++;
			
		GPIO_PORTF_DIR_R = 0x0C;    // acik mavi  
		GPIO_PORTF_DEN_R = 0x0C;
		GPIO_PORTF_DATA_R = 0x0C;
	  lag(count1);
		count1--;
			j++;
		
		}
			j=0;
			 while (j<=100)
		{
		GPIO_PORTF_DIR_R = 0x0C; // acik mavi       
		GPIO_PORTF_DEN_R = 0x0C;
		GPIO_PORTF_DATA_R = 0x0C;
	  lag(count1);
		count1++;
			
		GPIO_PORTF_DIR_R = 0x08;    //yesil   
		GPIO_PORTF_DEN_R = 0x08;
		GPIO_PORTF_DATA_R &= 0x08;   
	  lag(count2);
		count2--;
		
			j++;
		}
		
		 j=0;
			 while (j<=100)
		{
		GPIO_PORTF_DIR_R = 0x02;       // kirmizi
		GPIO_PORTF_DEN_R = 0x02;
		GPIO_PORTF_DATA_R &= 0x02;   
	  lag(count2);
		count2++;
			
		GPIO_PORTF_DIR_R = 0x06;      // magenta  color
		GPIO_PORTF_DEN_R = 0x06;
		GPIO_PORTF_DATA_R = 0x06;
	  lag(count1);
		count1--;
			
		j++;
		}
		j=0;
			 while (j<=100)
		{
		GPIO_PORTF_DIR_R = 0x06;       // magenta
		GPIO_PORTF_DEN_R = 0x06;
		GPIO_PORTF_DATA_R = 0x06;
	  lag(count1);
		count1++;
			
		GPIO_PORTF_DIR_R = 0x04;       // koyu mavi
		GPIO_PORTF_DEN_R = 0x04;
		GPIO_PORTF_DATA_R &= 0x04;   
	  lag(count2);
		count2--;
		j++;
			
		}
			sw2=GPIO_PORTA_DATA_R&0x01;
      sw1=GPIO_PORTA_DATA_R&0x10;
if(sw1==0) {

GPIO_PORTA_DATA_R=0x02;
}

if(sw2==0){

GPIO_PORTA_DATA_R=0x08;//pf3 yesil led 
	}

}
	return 0;

	
	}