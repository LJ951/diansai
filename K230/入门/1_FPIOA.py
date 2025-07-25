
from machine import FPIOA

# 实例化FPIOA
fpioa = FPIOA()

# 打印所有引脚配置
fpioa.help()

# 打印指定引脚详细配置
fpioa.help(0)

# 打印指定功能所有可用的配置引脚
fpioa.help(FPIOA.IIC0_SDA, func=True)

# 获取指定功能当前所在的引脚
fpioa.get_pin_num(FPIOA.UART0_TXD)

# 获取指定引脚当前功能
fpioa.get_pin_func(0)
