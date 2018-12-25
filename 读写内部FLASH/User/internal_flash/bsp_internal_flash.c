/**
  ******************************************************************************
  * @file    bsp_internalFlash.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   �ڲ�FLASH��д���Է���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 �Ե� ������  
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./internal_flash/bsp_internal_flash.h"   
#include "./led/bsp_led.h"   


#define FLASH_USER_START_ADDR   ADDR_FLASH_PAGE_32   /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     ADDR_FLASH_PAGE_48    /* End @ of user Flash area */

#define DATA_32                 ((uint32_t)0x12345678)

uint32_t Address = 0, PAGEError = 0;
__IO uint32_t data32 = 0 , MemoryProgramStatus = 0;

/*V���ڲ������̵ı���*/
 FLASH_EraseInitTypeDef EraseInitStruct;


/**
  * @brief  InternalFlash_Test,���ڲ�FLASH���ж�д����
  * @param  None
  * @retval None
  */
void InternalFlash_Test(void)
{
	/* ����Flash������������ƼĴ�������*/
  HAL_FLASH_Unlock();

  /* ɾ���û�Flash����*/
  /* ���EraseInit�ṹ*/
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
  EraseInitStruct.PageAddress = FLASH_USER_START_ADDR;
  EraseInitStruct.NbPages     = (FLASH_USER_END_ADDR - FLASH_USER_START_ADDR) / FLASH_PAGE_SIZE;

  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
  {
    
    while (1)
    {
      LED1_ON;
      printf("����ʧ��\r\n");
    }
  }

  /* ���ֱ���û�Flash����*/

  Address = FLASH_USER_START_ADDR;

  while (Address < FLASH_USER_END_ADDR)
  {
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, DATA_32) == HAL_OK)
    {
      Address = Address + 4;
    }
    else
    {
      while (1)
      {
         LED1_ON;
         printf("д��ʧ��\r\n");
      }
    }
  }

  /*���������Խ���������ƼĴ������ʣ��Ƽ�����FLASH�洢�����ܿ��ܵ����������*/
  HAL_FLASH_Lock();

  /* ����������Ƿ�����
        MemoryProgramStatus = 0�����ݱ����ȷ
        MemoryProgramStatus��= 0��δ��ȷ��̵�����*/
  Address = FLASH_USER_START_ADDR;
  MemoryProgramStatus = 0x0;

  while (Address < FLASH_USER_END_ADDR)
  {
    data32 = *(__IO uint32_t *)Address;

    if (data32 != DATA_32)
    {
      MemoryProgramStatus++;
    }
    Address = Address + 4;
  }

  /*�����������Ƿ��������*/
  if (MemoryProgramStatus == 0)
  {
    printf("д��ɹ�\r\n");
    LED2_ON;
  }
  else
  {
    while (1)
    {
      LED1_ON;
      printf("ʧ��\r\n");
    }
  }
  while (1)
  {
  }
}
