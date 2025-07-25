# 导入蜂鸣器库 (Import buzzer library)
from ybUtils.YbBuzzer import YbBuzzer
# 导入时间库 (Import time library)
import time

# 创建蜂鸣器实例 (Create buzzer instance)
buzzer = YbBuzzer()

# 示例1：短鸣一声 (Example 1: Short beep)
buzzer.beep()  # 使用默认参数发出蜂鸣声 (Make a beep with default parameters)

# 等待3秒 (Wait for 3 seconds)
time.sleep(3)

# 示例2：自定义频率和持续时间 (Example 2: Custom frequency and duration)
buzzer.on(2000, 50, 0.5)  # 2000Hz，音量50%，持续0.5秒 (2000Hz, volume 50%, duration 0.5 seconds)

# 等待3秒 (Wait for 3 seconds)
time.sleep(3)

# 示例3：警报声效果 (Example 3: Alarm sound effect)
for i in range(3):  # 循环3次 (Loop 3 times)
    buzzer.on(1000, 50, 0.1)  # 1000Hz，音量50%，持续0.1秒 (1000Hz, volume 50%, duration 0.1 seconds)
    time.sleep(0.1)  # 短暂停顿0.1秒 (Brief pause for 0.1 seconds)
