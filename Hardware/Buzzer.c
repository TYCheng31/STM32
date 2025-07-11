#include "stm32f10x.h"

void Buzzer_Init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOB, &GPIO_InitStructure); 

    GPIO_SetBits(GPIOB, GPIO_Pin_12); 
}

void Buzzer_ON(void){
    GPIO_ResetBits(GPIOB, GPIO_Pin_12); 
}

void Buzzer_OFF(void){
    GPIO_SetBits(GPIOB, GPIO_Pin_12); 
}

void Buzzer_turn(void){
    if(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_1) == 0){
        GPIO_SetBits(GPIOB, GPIO_Pin_12); 
    }
    else{
        GPIO_ResetBits(GPIOB, GPIO_Pin_12); 
    }
}