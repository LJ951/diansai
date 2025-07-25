from ybUtils.YbKey import YbKey
import time

# 创建按键实例
# create key
key = YbKey()

# 持续监测按键状态
# Monitor key status
while True:
    if key.is_pressed():
        print("检测到按键按下", "pressed")
    time.sleep_ms(100)  # 延时以避免过于频繁的检测 (Delay to reduce detect frequence)
