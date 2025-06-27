#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "MPU6050.h"


uint8_t ID;
int16_t AX, AY, AZ, GX, GY, GZ;
uint8_t temp[3];

int main(void)
{
	OLED_Init();
	LED_Init();
	MPU6050_Init();
	
	OLED_ShowString(1, 1, "ID:");
	ID = MPU6050_GetID();
	OLED_ShowHexNum(1, 4, ID, 2);
	
	while (1)
	{  
		temp[0] = AX;
		temp[1] = AY;
		temp[2] = AZ;
		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
		OLED_ShowSignedNum(2, 1, AX, 5);
		OLED_ShowSignedNum(3, 1, AY, 5);
		OLED_ShowSignedNum(4, 1, AZ, 5);
		OLED_ShowSignedNum(2, 8, GX, 5);
		OLED_ShowSignedNum(3, 8, GY, 5);
		OLED_ShowSignedNum(4, 8, GZ, 5);

		if(AX >= 1500 || AX <= -1500){
			LED1_ON();
		}
		else{
			LED1_OFF();
		}

		if(AY >= 1500 || AY <= -1500){
			LED2_ON();
		}
		else{
			LED2_OFF();
		}
	}
}
