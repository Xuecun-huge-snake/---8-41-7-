#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/BEEP/beep.h"
#include "./BSP/KEY/key.h"
#include "./BSP/MODE/mode.h"

int indexled = 0;
int count = 0;


void close_all(void)
{
    LED0(0); 
    LED1(0);
    LED2(0);
    LED3(0);
	LED4(0);
    LED5(0);
}

void mode__1(void)
{
    close_all();
    if(indexled==0)
    {
        LED0(1);
		LED5(1); 
    }
    else if(indexled==1)
    {
        LED0(1);
		LED5(1);
		LED1(1);
		LED4(1);
    }
    else if(indexled==2)
    {
        LED0(1);
		LED5(1);
		LED1(1);
		LED4(1);
		LED2(1);
		LED3(1);		
    }
    else if(indexled==3)
    {
		LED0(1);
		LED5(1);
		LED1(1);
		LED4(1);
		LED2(0);
        LED3(0); 
    }
	  else if(indexled==4)
    {
        LED0(1);
		LED5(1);
		LED1(0);
        LED4(0); 
    }
	  else if(indexled==5)
    {
        LED0(0);
        LED5(0); 
    }
    indexled++;
    if(indexled>=6)
    {
        indexled = 0;
    }
}

void mode__2(void)
{
    LED0(1); 
    LED1(0);
    LED2(0);
    LED3(0);
	LED4(0);
    LED5(0);    
}

int i_1 = 0;
void mode__2_feq1(void)
{
	while(i_1 < 3)
	{
		LED0(1); 
		delay_ms(2000);	
		LED0(0); 
		delay_ms(2000);
		i_1++;
	}
}

int i_2 = 0;
void mode__2_feq2(void)
{
	while(i_2 < 5)
	{
		LED0(1); 
		delay_ms(833);	
		LED0(0); 
		delay_ms(833);
		i_2++;
	}
}

int i_3 = 0;
void mode__2_feq3(void)
{
	while(i_3 < 5)
	{
		LED0(1); 
		delay_ms(500);	
		LED0(0); 
		delay_ms(500);
		i_3++;
	}
}

int i_30 = 0;
void mode__3_led0(void)
{
	
	while(i_30 < 5)
	{
		LED0(1); 
		delay_ms(500);	
		LED0(0); 
		delay_ms(500);
		i_30++;
	}
}

int i_31 = 0;
void mode__3_led1(void)
{
	
	while(i_31 < 5)
	{
		LED0(1); 
		delay_ms(500);	
		LED0(0); 
		delay_ms(500);
		i_31++;
	}
}

int i_32 = 0;
void mode__3_led2(void)
{
	
	while(i_32 < 5)
	{
		LED0(1); 
		delay_ms(500);	
		LED0(0); 
		delay_ms(500);
		i_32++;
	}
}

int i_33 = 0;
void mode__3_led3(void)
{
	
	while(i_33 < 5)
	{
		LED0(1); 
		delay_ms(500);	
		LED0(0); 
		delay_ms(500);
		i_33++;
	}
}

int i_34 = 0;
void mode__3_led4(void)
{
	
	while(i_34 < 5)
	{
		LED0(1); 
		delay_ms(500);	
		LED0(0); 
		delay_ms(500);
		i_34++;
	}
}

int i_35 = 0;
void mode__3_led5(void)
{
	
	while(i_35 < 5)
	{
		LED0(1); 
		delay_ms(500);	
		LED0(0); 
		delay_ms(500);
		i_35++;
	}
}

extern uint8_t count_f1;
extern uint8_t count_f2;
int main(void)
{

    uint8_t current_mode = 0;  // 当前模式标志，0为mode_1，1为mode_2
    HAL_Init();                             /* 初始化HAL库 */
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */
    led_init();                             /* 初始化LED */
    //beep_init();                            /* 初始化蜂鸣器 */
    key_init();                             /* 初始化按键 */
    LED0(0); 					
    LED1(0);
    LED2(0);
    LED3(0);
	LED4(0);
	LED5(0);
	
	
	while(1)
    {
		current_mode = key_scan(0); 
		//进入模式1 默认频率1hz
        if (current_mode == 0) 
        {
            if(count % 100 == 0)
            {
                mode__1();
            }
        } 
		
		//进入模式1-频率1 0.6hz 一次1.67s
		else if(current_mode == 1  && count_f1 == 0)
		{
			if(count % 167 == 0)
            {
                mode__1();
            }
		}
		
		//进入模式1-频率2 2.2hz 一次0.45s
		else if(current_mode == 1  && count_f1 == 1)
		{
			if(count % 45 == 0)
            {
                mode__1();
            }			
		}
		
		//进入模式1-频率3 3hz 一次0.33s
		else if(current_mode == 1  && count_f1 == 2)
		{
			if(count % 33 == 0)
			{
                mode__1();
            }
		}
	
		
		
		//进入模式2  默认频率1hz
        else if(current_mode == 2)
        {
            if(count % 100 == 0)
            {
                mode__2();
            }
        }
		//进入模式2-频率1 0.5hz 一次2s
				else if(current_mode == 3  && count_f2 == 0)
        {
            if(count % 100 == 0)
            {
                mode__2_feq1();
            }
        }
		//进入模式2-频率2	1.2hz 一次0.83s
				else if(current_mode == 3  && count_f2 == 1)
        {
            if(count % 100 == 0)
            {
                mode__2_feq2();
            }
        }
		//进入模式2-频率3	2hz 一次0.5s	
				else if(current_mode == 3  && count_f2 == 2)
        {
            if(count % 100 == 0)
            {
                mode__2_feq3();
            }
        }
		
		
		//开始切换模式2led灯  默认频率1hz
        else if(current_mode == 4  && count_f2 == 0)
        {
            if(count % 100 == 0)
            {
                mode__3_led0();
            }
        }
		
		else if(current_mode == 4  && count_f2 == 1)
        {
            if(count % 100 == 0)
            {
                mode__3_led1();
            }
        }
		
		else if(current_mode == 4  && count_f2 == 2)
        {
            if(count % 100 == 0)
            {
                mode__3_led2();
            }
        }
		
		else if(current_mode == 4  && count_f2 == 3)
        {
            if(count % 100 == 0)
            {
                mode__3_led3();
            }
        }
		
		else if(current_mode == 4  && count_f2 == 4)
        {
            if(count % 100 == 0)
            {
                mode__3_led4();
            }
        }
		
		else if(current_mode == 4  && count_f2 == 5)
        {
            if(count % 100 == 0)
            {
                mode__3_led5();
            }
        }
		
		count++;

        // 延时，避免模式切换过快
        delay_ms(10);
    }
}
