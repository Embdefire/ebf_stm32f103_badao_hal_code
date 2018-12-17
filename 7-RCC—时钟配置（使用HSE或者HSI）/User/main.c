/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-�Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx.h"
#include "./led/bsp_led.h"
#include "./rcc/bsp_clkconfig.h"

void Delay(__IO uint32_t nCount); 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{

    // ��������main����֮ǰ�������ļ���statup_stm32f746xx.s�Ѿ�����
    // SystemInit()������ϵͳʱ�ӳ�ʼ����16MHZ
    // SystemInit()��system_stm32f7xx.c�ж���
    // ����û����޸�ϵͳʱ�ӣ������б�д�����޸�	
    // ��������ϵͳʱ�ӣ���ʱ�����ѡ��ʹ��HSE����HSI
  
    //ϵͳʱ������Ϊ216M�������250M
    HSE_SetSysClock();
        
    // ʹ��HSI������ϵͳʱ��Ϊ216M
    //HSI_SetSysClock(16, 336, 2, 7);
        
    // LED �˿ڳ�ʼ�� 
    LED_GPIO_Config();
        
    // MCO1 ���PLLCLK	
    HAL_RCC_MCOConfig(RCC_MCO,RCC_MCO1SOURCE_PLLCLK, RCC_MCODIV_1);
        
    while (1)
    {
        LED2( ON );			 // �� 
        Delay(0x0FFFFF);
        LED2( OFF );		 // ��
        Delay(0x0FFFFF);
    }
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
