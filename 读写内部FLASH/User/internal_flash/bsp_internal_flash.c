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
<<<<<<< HEAD
#define FLASH_USER_END_ADDR     ADDR_FLASH_PAGE_48    /* End @ of user Flash area */
=======
#define FLASH_USER_END_ADDR     ADDR_FLASH_PAGE_48  /* End @ of user Flash area */
>>>>>>> remotes/origin/FIRST

#define DATA_32                 ((uint32_t)0x12345678)

uint32_t Address = 0, PAGEError = 0;
__IO uint32_t data32 = 0 , MemoryProgramStatus = 0;

<<<<<<< HEAD
/*V���ڲ������̵ı���*/
=======
/*Variable used for Erase procedure*/
>>>>>>> remotes/origin/FIRST
 FLASH_EraseInitTypeDef EraseInitStruct;


/**
  * @brief  InternalFlash_Test,���ڲ�FLASH���ж�д����
  * @param  None
  * @retval None
  */
void InternalFlash_Test(void)
{
<<<<<<< HEAD
	/* ����Flash������������ƼĴ�������*/
  HAL_FLASH_Unlock();

  /* ɾ���û�Flash����*/
  /* ���EraseInit�ṹ*/
=======
	/* Unlock the Flash to enable the flash control register access *************/
  HAL_FLASH_Unlock();

  /* Erase the user Flash area
    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

  /* Fill EraseInit structure*/
>>>>>>> remotes/origin/FIRST
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
  EraseInitStruct.PageAddress = FLASH_USER_START_ADDR;
  EraseInitStruct.NbPages     = (FLASH_USER_END_ADDR - FLASH_USER_START_ADDR) / FLASH_PAGE_SIZE;

  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
  {
<<<<<<< HEAD
    
    while (1)
    {
      LED1_ON;
      printf("����ʧ��\r\n");
    }
  }

  /* ���ֱ���û�Flash����*/
=======
    /*
      Error occurred while page erase.
      User can add here some code to deal with this error.
      PAGEError will contain the faulty page and then to know the code error on this page,
      user can call function 'HAL_FLASH_GetError()'
    */
    /* Infinite loop */
    while (1)
    {
      LED1_ON;
      /* indicate error in Erase operation */
     printf("����ʧ��\r\n");
    }
  }

  /* Program the user Flash area word by word
    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/
>>>>>>> remotes/origin/FIRST

  Address = FLASH_USER_START_ADDR;

  while (Address < FLASH_USER_END_ADDR)
  {
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Address, DATA_32) == HAL_OK)
    {
      Address = Address + 4;
    }
    else
    {
<<<<<<< HEAD
      while (1)
      {
         LED1_ON;
=======
      /* Error occurred while writing data in Flash memory.
         User can add here some code to deal with this error */
      while (1)
      {
         LED1_ON;
         /* indicate error in Erase operation */
>>>>>>> remotes/origin/FIRST
         printf("д��ʧ��\r\n");
      }
    }
  }

<<<<<<< HEAD
  /*���������Խ���������ƼĴ������ʣ��Ƽ�����FLASH�洢�����ܿ��ܵ����������*/
  HAL_FLASH_Lock();

  /* ����������Ƿ�����
        MemoryProgramStatus = 0�����ݱ����ȷ
        MemoryProgramStatus��= 0��δ��ȷ��̵�����*/
=======
  /* Lock the Flash to disable the flash control register access (recommended
     to protect the FLASH memory against possible unwanted operation) *********/
  HAL_FLASH_Lock();

  /* Check if the programmed data is OK
      MemoryProgramStatus = 0: data programmed correctly
      MemoryProgramStatus != 0: number of words not programmed correctly ******/
>>>>>>> remotes/origin/FIRST
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

<<<<<<< HEAD
  /*�����������Ƿ��������*/
  if (MemoryProgramStatus == 0)
  {
    printf("д��ɹ�\r\n");
=======
  /*Check if there is an issue to program data*/
  if (MemoryProgramStatus == 0)
  {
    printf("д��ɹ�\r\n");
    /* No error detected. Switch on LED2*/
>>>>>>> remotes/origin/FIRST
    LED2_ON;
  }
  else
  {
<<<<<<< HEAD
    while (1)
    {
      LED1_ON;
      printf("ʧ��\r\n");
    }
  }
=======
    /* Error detected. LED1 will blink with 1s period */
    while (1)
    {
      LED1_ON;
         /* indicate error in Erase operation */
      printf("ʧ��\r\n");
    }
  }

  /* Infinite loop */
>>>>>>> remotes/origin/FIRST
  while (1)
  {
  }
}
