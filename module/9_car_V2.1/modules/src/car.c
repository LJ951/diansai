#include "empty.h"

uint8_t Trail_Num[8];
uint8_t KeyNum;
uint8_t state, state_set;

static void OLED(void)
{
    OLED_Printf(0, 0, OLED_6X8, "state:%d  ", state);
    OLED_Printf(54, 0, OLED_6X8, "state_set:%d  ", state_set);

    OLED_Printf(0, 8, OLED_6X8, "Pitch:%.2f ", mpu6050.pitch);
    OLED_Printf(0, 16, OLED_6X8, "Roll:%.2f  ", mpu6050.roll);
    OLED_Printf(0, 24, OLED_6X8, "Yaw:%.2f  ", mpu6050.yaw);

    OLED_Printf(0, 32, OLED_6X8, "E1:%.0f  ", PID_L1.Actual);
    OLED_Printf(0, 40, OLED_6X8, "E2:%.0f  ", PID_L2.Actual);
    OLED_Printf(0, 48, OLED_6X8, "E3:%.0f  ", PID_R1.Actual);
    OLED_Printf(0, 56, OLED_6X8, "E4:%.0f  ", PID_R2.Actual);

    OLED_Printf(54, 32, OLED_6X8, "kp:%.2f  ", PID_L1.Kp);
    OLED_Printf(54, 40, OLED_6X8, "ki:%.2f  ", PID_L1.Ki);
    OLED_Printf(54, 48, OLED_6X8, "kd:%.2f  ", PID_L1.Kd);
    OLED_Update();
}

static void Serial(void)
{
    // printf("%.2lf,%.2lf,%.2lf\r\n",mpu6050.pitch,mpu6050.roll,mpu6050.yaw);
    printf("%.2f,%.2f,%.2f,%.2f\r\n",PID_L1.Target,PID_L1.Out/100.0,PID_L1.Actual, PID_L1.ErrorInt);
}

static void Key(void)
{
    KeyNum = Key_GetNum();

    if(KeyNum == 1)
    {
        // state ++;
        // if(state >= 4)
        //     state = 0;

        PID_L1.Target += 5;
        if(PID_L1.Target >= 30)
            PID_L1.Target = 0;
    }
    if(KeyNum == 2)
    {
        // state_set = !state_set;

        PID_L1.Kp += 0.01;
    }
    if(KeyNum == 3)
    {
        PID_L1.Kp -= 0.01;
    }
    if(KeyNum == 4)
    {
        PID_L1.Kp += 0.02;
    }
}

void Trail(void)
{
	uint8_t PID_Out, ret, speed_L, speed_R;
    
	ret = gw_gray_serial_read();
	for(int i=0;i<8;i++)
	{
		Trail_Num[i] = (ret>>i)&0x01;
	}

	// PID_Out = PID_Trail.Out * 8;
	// speed_L = 80 - PID_Out;
	// speed_R = 80 - PID_Out;
	
	// PIDL.Target = speed_L;
	// PIDR.Target = speed_R;
}


static void car_state(uint8_t state)
{
    // 停止
    if(state == 1)
    {

    }
    // 直走
    if(state == 2)
    {
        
    }
    // 循迹
    if(state == 3)
    {
        Trail();
    }
    // 对角
    if(state == 4)
    {

    }
}

void Topic(void)
{
    Key();
    OLED();
    Serial();
    Trail();
    if(state == 0 && state_set == 1)
    {

    }
    // 第一问
    if(state == 1 && state_set == 1)
    {
        car_state(2);
        if(Trail_Num[0])
        {
            car_state(1);
        }
    }
    // 第二问
    if(state == 2 && state_set == 1)
    {
        car_state(2);
        if(Trail_Num[0])
        {
            car_state(3);
        }
        else 
        {
            car_state(2);
        }
        if(Trail_Num[0])
        {
            car_state(1);
        }
    }
    // 第三问
    if(state == 3 && state_set == 1)
    {
        car_state(3);
    }
    // 第四问
    if(state == 4 && state_set == 1)
    {
        
    }
}


