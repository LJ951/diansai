# 导入YbRGB库 (Import YbRGB library)
from ybUtils.YbRGB import YbRGB
# 导入时间库 (Import time library)
import time

# 实例化YbRGB对象 (Initialize YbRGB object)
YbRGB = YbRGB()

# 让RGB灯显示蓝色 (82, 139, 255) (Make the RGB light display blue color (82, 139, 255))
YbRGB.show_rgb((82, 139, 255))

# 程序阻塞等待3秒 (Block the program for 3 seconds)
time.sleep(3)

# 关闭RGB灯 (0,0,0) (Turn off the RGB light by setting color to (0,0,0))
YbRGB.show_rgb((0,0,0))
