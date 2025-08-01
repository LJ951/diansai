#include "Trail.h"


uint8_t  gw_gray_serial_read(void)
{
	uint8_t i;
	uint8_t ret = 0;
	for (i = 0; i < 8; ++i) {
		/* 输出时钟下降沿 */
		DL_GPIO_clearPins(Trail_PORT, Trail_Trail_CLK_PIN);
		delay_us(2);
		//避免GPIO翻转过快导致反应不及时
		ret |= (DL_GPIO_readPins(Trail_PORT, Trail_Trail_DAT_PIN)==0?0:1) << i;

		/* 输出时钟上升沿,让传感器更新数据*/
		DL_GPIO_setPins(Trail_PORT, Trail_Trail_CLK_PIN);
	
		/* 延迟需要在5us左右 */
		delay_us(5);
	}
	return ret;
}


