#include "it.h"

static GPIO_InitTypeDef 	  GPIO_InitStructure;
static EXTI_InitTypeDef   	EXTI_InitStructure;
static NVIC_InitTypeDef   	NVIC_InitStructure;

void exti0_init(void)
{
	//使能(打开)端口A的硬件时钟，就是对端口A供电
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	
	//使能系统配置时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	//配置PA0引脚为输入模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;		//第0根引脚
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IN;		//输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//高速响应
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	//没有使能上下拉电阻
	GPIO_Init(GPIOA,&GPIO_InitStructure);	


	//将PA0和EXTI0连接在一起
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

	//外部中断的配置
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;		//外部中断0
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//中断
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//下降沿触发，用于识别按键的按下；上升沿触发，用于检测按键的松开；  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				//使能
	EXTI_Init(&EXTI_InitStructure);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//外部中断0的请求通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;//抢占优先级0x02
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;		//响应优先级0x03
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//使能该通道
	NVIC_Init(&NVIC_InitStructure);
	
}

void exti2_init(void)
{
	//使能(打开)端口E的硬件时钟，就是对端口E供电
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	
	//使能系统配置时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	
	
	//配置PE2引脚为输入模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;		//第2根引脚
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IN;		//输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//高速响应
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	//没有使能上下拉电阻
	GPIO_Init(GPIOE,&GPIO_InitStructure);	


	//将PE2和EXTI2连接在一起
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource2);

	//外部中断的配置
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;		//外部中断2
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//中断
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//下降沿触发，用于识别按键的按下；上升沿触发，用于检测按键的松开；  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				//使能
	EXTI_Init(&EXTI_InitStructure);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//外部中断2的请求通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x03;//抢占优先级0x03
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;		//响应优先级0x03
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//使能该通道
	NVIC_Init(&NVIC_InitStructure);
	
}

void exti3_init(void)
{
	//使能(打开)端口E的硬件时钟，就是对端口E供电
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	
	//使能系统配置时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	
	
	//配置PE3引脚为输入模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;		//第3根引脚
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IN;		//输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//高速响应
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	//没有使能上下拉电阻
	GPIO_Init(GPIOE,&GPIO_InitStructure);	


	//将PE2和EXTI2连接在一起
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);

	//外部中断的配置
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;		//外部中断3
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//中断
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//下降沿触发，用于识别按键的按下；上升沿触发，用于检测按键的松开；  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				//使能
	EXTI_Init(&EXTI_InitStructure);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//外部中断3的请求通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x03;//抢占优先级0x03
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;		//响应优先级0x03
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//使能该通道
	NVIC_Init(&NVIC_InitStructure);
	
}

