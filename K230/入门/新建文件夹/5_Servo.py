from machine import PWM
from machine import FPIOA
import time

# 实例化FPIOA
fpioa = FPIOA()
# 设置PIN42为PWM通道0
fpioa.set_function(42, fpioa.PWM0)

# 实例化PWM通道0，频率为1000Hz，占空比为50%，默认使能输出
pwm0 = PWM(0, 100)

pwm0.duty(1)

# 打开通道1输出
pwm0.enable(1)

time.sleep(1)
