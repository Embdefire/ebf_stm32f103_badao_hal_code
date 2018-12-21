#ifndef __ADVANCE_TIM_H
#define	__ADVANCE_TIM_H


#include "stm32f1xx.h"

// ��ʱ��Ԥ��Ƶ
#define ADVANCED_TIM_PRESCALER            0 
// ��ʱ������
#define ADVANCED_TIM_PERIOD               1000
// �߼���ʱ���ظ������Ĵ���ֵ
#define ADVANCED_TIM_REPETITIONCOUNTER    0


/* ��ʱ�� */

#define ADVANCED_TIMx                        TIM1
#define ADVANCED_TIM_RCC_CLK_ENABLE()        __HAL_RCC_TIM1_CLK_ENABLE()
#define ADVANCED_TIM_RCC_CLK_DISABLE()       __HAL_RCC_TIM1_CLK_DISABLE()
#define ADVANCED_TIM_GPIO_RCC_CLK_ENABLE()   {__HAL_RCC_GPIOA_CLK_ENABLE();__HAL_RCC_GPIOC_CLK_ENABLE();}

/* TIM8ͨ��1������� */
#define ADVANCE_OCPWM_PIN           		GPIO_PIN_6              
#define ADVANCE_OCPWM_GPIO_PORT     		GPIOC                      


/* TIM8ͨ��1����������� */
#define ADVANCE_OCNPWM_PIN            		GPIO_PIN_5              
#define ADVANCE_OCNPWM_GPIO_PORT      		GPIOA                      


extern TIM_HandleTypeDef TIM_TimeBaseStructure;

void  ADVANCE_TIM_Mode_Config(void);

#endif /* __ADVANCE_TIM_H */

