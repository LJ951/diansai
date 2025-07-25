#include "bsp_siic.h"
#include "bsp_systick.h"

/* 软件iic */

#define userconfig_USE_DELAY  1 //是否使用延迟功能,部分设备不支持高速,需要加入延迟才可正常通信
#define userconfig_DELAY_TIME 25 //延迟的时间,while( userconfig_DELAY_TIME-- ) \
                                      主频越高的单片机,数值需要越大.可以根据实际通信效果来调整.注：数值调整的过低,可能会导致时序不对而无法正常通信

#define userconfig_delayus 1		 									  

#define sIIC_SDA_H DL_GPIO_setPins(sIIC_PORT,sIIC_IIC_SDA_PIN)
#define sIIC_SDA_L DL_GPIO_clearPins(sIIC_PORT,sIIC_IIC_SDA_PIN)
#define sIIC_SCL_H DL_GPIO_setPins(sIIC_PORT,sIIC_IIC_SCL_PIN)
#define sIIC_SCL_L DL_GPIO_clearPins(sIIC_PORT,sIIC_IIC_SCL_PIN)

static uint8_t init_flag = 0;


static void SDA_IN(void)
{
	DL_GPIO_initDigitalInput(sIIC_IIC_SDA_IOMUX);
}

static void SDA_OUT(void)
{
    DL_GPIO_initDigitalOutput(sIIC_IIC_SDA_IOMUX);
    DL_GPIO_setPins(sIIC_PORT, sIIC_IIC_SDA_PIN);
    DL_GPIO_enableOutput(sIIC_PORT, sIIC_IIC_SDA_PIN);
}

static uint8_t READ_SDA(void)
{
    return ( DL_GPIO_readPins(sIIC_PORT,sIIC_IIC_SDA_PIN) & sIIC_IIC_SDA_PIN ) > 0 ? 1:0;
}

static void siic_init(void)
{

}


static void sIIC_Start(void)
{
	SDA_OUT();
    sIIC_SCL_L;
	sIIC_SDA_H;
	sIIC_SCL_H;
	delay_us(userconfig_delayus);
	sIIC_SDA_L;
	delay_us(userconfig_delayus);
    sIIC_SCL_L;
	delay_us(userconfig_delayus);
}

static void sIIC_Stop(void)
{
    SDA_OUT();   // 设置 SDA 为输出
    sIIC_SCL_L;  // 拉低 SCL
    sIIC_SDA_L;  // 拉低 SDA
	
    sIIC_SCL_H;  // 将 SCL 置为高电平
	
	delay_us(userconfig_delayus);
	
    sIIC_SDA_H;  // 在 SCL 为高时，将 SDA 拉高生成停止信号
    delay_us(userconfig_delayus);
}

static uint8_t sIIC_WaitAck(uint32_t timeout)
{
    uint32_t time = 0;

    SDA_IN();    // 设置 SDA 为输入
    sIIC_SDA_H;  // 拉高 SDA
	
	delay_us(userconfig_delayus);
	
    sIIC_SCL_H;  // 拉高 SCL，等待应答信号
	
	delay_us(userconfig_delayus);
	
    while (READ_SDA()) {  // 检测从设备是否拉低 SDA，产生ACK信号
        time++;
        delay_us(userconfig_delayus);
        if (time > timeout) {
            sIIC_Stop();  // 超时则发送停止信号
            return 0;     // 无应答
        }
    }

    sIIC_SCL_L;  // 拉低 SCL，继续传输
    SDA_OUT();
    return 1;    // 收到应答
}

static void sIIC_Ack(void)
{
    SDA_OUT();   // 设置 SDA 为输出
    sIIC_SCL_L;  // 拉低 SCL
    sIIC_SDA_L;  // 拉低 SDA，发送 ACK
	
	delay_us(userconfig_delayus);

    sIIC_SDA_L;
    sIIC_SCL_H;  // 拉高 SCL，确认传输
	
	delay_us(userconfig_delayus);

    sIIC_SCL_L;  // 拉低 SCL，结束 ACK 信号
    sIIC_SDA_H;
}

static void sIIC_NAck(void)
{
    SDA_OUT();   // 设置 SDA 为输出
    sIIC_SCL_L;  // 拉低 SCL
    sIIC_SDA_L;  // 拉低 SDA，发送 ACK
	
	delay_us(userconfig_delayus);

    sIIC_SDA_H;
    sIIC_SCL_H;  // 拉高 SCL，确认传输
	
	delay_us(userconfig_delayus);

    sIIC_SCL_L;  // 拉低 SCL，结束 ACK 信号
    sIIC_SDA_H;
}

static void sIIC_SendByte(uint8_t byte)
{
    uint8_t i;

    SDA_OUT();  // 设置 SDA 为输出
    sIIC_SCL_L; // 拉低 SCL

    for (i = 0; i < 8; i++) {
        if (byte & 0x80) {
            sIIC_SDA_H;  // 发送高位
        } else {
            sIIC_SDA_L;  // 发送低位
        }
        delay_us(1);
        byte <<= 1;       // 移动到下一位
        sIIC_SCL_H;       // 拉高 SCL，传输当前位
		delay_us(1);
        sIIC_SCL_L;       // 拉低 SCL，准备下一位
  
    }
}

static uint8_t sIIC_ReadByte(uint8_t ack)
{
    uint8_t i, byte = 0;

    SDA_IN();  // 设置 SDA 为输入

    for (i = 0; i < 8; i++) {
        sIIC_SCL_L;  // 拉低 SCL
        delay_us(1);	
        sIIC_SCL_H;  // 拉高 SCL，读取当前位
		delay_us(1);
        byte <<= 1;
        if (READ_SDA()) {
            byte |= 0x01;  // 读取到高电平
        }
        delay_us(1);
    }

    if (!ack) {
        sIIC_NAck();  // 如果不需要应答，发送 NACK
    } else {
        sIIC_Ack();   // 需要应答则发送 ACK
    }

    return byte;
}

static IIC_Status_t IIC_Master_Transmit(uint16_t dev_addr, uint8_t *data, uint16_t size,uint32_t timeout)
{
    sIIC_Start();    // 发送起始信号

    sIIC_SendByte(dev_addr);        // 发送从设备地址（写模式）
    if (!sIIC_WaitAck(timeout)) {          // 等待应答
        sIIC_Stop();                // 如果没有应答，则停止通信
        return IIC_TIMEOUT;
    }

    for (uint16_t i = 0; i < size; i++) {
        sIIC_SendByte(data[i]);     // 逐字节发送数据
        if (!sIIC_WaitAck(timeout)) {      // 每发送一个字节后等待应答
            sIIC_Stop();            // 如果没有应答，则停止通信
            return IIC_TIMEOUT;
        }
    }

    sIIC_Stop();                    // 发送停止信号
    return IIC_OK;                       // 成功
}

static IIC_Status_t IIC_Master_Receive(uint16_t dev_addr, uint8_t *data, uint16_t size,uint32_t timeout)
{
    sIIC_Start();    // 发送起始信号

    sIIC_SendByte(dev_addr | 0x01); // 发送从设备地址（读模式）
    if (!sIIC_WaitAck(timeout)) {          // 等待应答
        sIIC_Stop();                // 如果没有应答，则停止通信
        return IIC_TIMEOUT;
    }

    for (uint16_t i = 0; i < size; i++) {
        data[i] = sIIC_ReadByte(i == (size - 1) ? 0 : 1); // 逐字节读取数据，最后一个字节发送NACK
    }

    sIIC_Stop();                    // 发送停止信号
    return IIC_OK;                       // 成功
}


static IIC_Status_t IIC_Mem_Write(uint16_t dev_addr, uint16_t mem_addr, uint8_t *data, uint16_t size,uint32_t timeout)
{
    sIIC_Start();                  // 发送起始信号
    
    sIIC_SendByte(dev_addr);       // 发送从设备地址（写模式）
    if (!sIIC_WaitAck(timeout)) return IIC_TIMEOUT; // 等待应答

    sIIC_SendByte(mem_addr);       // 发送内存/寄存器地址
    if (!sIIC_WaitAck(timeout)) return IIC_TIMEOUT; // 等待应答

    for (uint16_t i = 0; i < size; i++) {
        sIIC_SendByte(data[i]);    // 逐字节发送数据
        if (!sIIC_WaitAck(timeout)) return IIC_TIMEOUT; // 等待应答
    }
    
    sIIC_Stop();                   // 发送停止信号
    return IIC_OK;                      // 写入成功
}

static IIC_Status_t IIC_Mem_Read(uint16_t dev_addr, uint16_t mem_addr, uint8_t *data, uint16_t size,uint32_t timeout)
{
    sIIC_Start();                   // 发送起始信号
    
    sIIC_SendByte(dev_addr);        // 发送从设备地址（写模式）
    if (!sIIC_WaitAck(timeout)) return IIC_TIMEOUT;  // 等待应答

    sIIC_SendByte(mem_addr);        // 发送内存/寄存器地址
    if (!sIIC_WaitAck(timeout)) return IIC_TIMEOUT;  // 等待应答
    
    sIIC_Start();                    // 重新启动信号，准备读数据
    sIIC_SendByte(dev_addr | 0x01); // 发送从设备地址（读模式）
    if (!sIIC_WaitAck(timeout)) return IIC_TIMEOUT;  // 等待应答

    for (uint16_t i = 0; i < size; i++) {
        data[i] = sIIC_ReadByte(i == (size - 1) ? 0 : 1); // 逐字节读取数据，最后一个字节发送NACK
    }

    sIIC_Stop();                    // 发送停止信号
    return IIC_OK;                       // 读取成功
}

static void iic_delayms(uint16_t ms)
{
	delay_ms(ms);
}
void mpu6050_i2c_sda_unlock(void)
{
	__asm__("nop");
}
//挂载驱动
IICInterface_t User_sIICDev = {
	.init = siic_init,
	.write = IIC_Master_Transmit , 
	.read = IIC_Master_Receive ,
	.write_reg = IIC_Mem_Write ,
	.read_reg = IIC_Mem_Read ,
	.delay_ms = iic_delayms
};

//use demo
//void mpu6050_init(void)
//{
//	#define MPU6050_DEV 0x68
//	pIICInterface_t iic = &UserII2Dev;
//	uint8_t writebuf = 0;
//	
//	writebuf=0;
//	iic->write_reg(MPU6050_DEV<<1,0x6B,&writebuf,1,200);
//	
//	writebuf=0x07;
//	iic->write_reg(MPU6050_DEV<<1,0x19,&writebuf,1,200);
//	
//	writebuf=0x06;
//	iic->write_reg(MPU6050_DEV<<1,0x1A,&writebuf,1,200);
//	
//	writebuf=0x01;
//	iic->write_reg(MPU6050_DEV<<1,0x1C,&writebuf,1,200);//±2g
//	
//	writebuf=0x18;
//	iic->write_reg(MPU6050_DEV<<1,0x1B,&writebuf,1,200);//±2000
//	
//	printf("read mpu:%d\r\n",iic->read_reg(0x68<<1,0x3B,accel,6,200));
//	printf("X:%.2f\r\n",(float)(short)(accel[0]<<8|accel[1])*0.00059814453125f);
//	printf("Y:%.2f\r\n",(float)(short)(accel[2]<<8|accel[3])*0.00059814453125f);
//	printf("Z:%.2f\r\n\r\n",(float)(short)(accel[4]<<8|accel[5])*0.00059814453125f);
//}

//void IO_TOP_demo(void* param)
//{
//	pIICInterface_t iic = &UserII2Dev;

//	#define IO_TOP_Dev 0x20 //IO TOP设备地址
//	
//	uint8_t buf[2] = { 0,0 };
//	uint8_t readbuf[2] = { 0xAA,0xBB };
//	uint8_t flag=0;
//	iic->write(IO_TOP_Dev<<1,buf,2,200);//关闭所有电平
//	
//	for(;;)
//	{
//		flag=!flag;
//		if( flag ) buf[0]=0,buf[1]=0;
//		else buf[0] = 0xff,buf[1]=0xff;
//		
//		printf("wrtie:%d\r\n",iic->write(IO_TOP_Dev<<1,buf,2,200));
//		
//		printf("read:%d\r\n",iic->read(IO_TOP_Dev<<1,readbuf,2,200));
//		printf("0x%2X    0x%2X\r\n",readbuf[0],readbuf[1]);
//	}
//}

