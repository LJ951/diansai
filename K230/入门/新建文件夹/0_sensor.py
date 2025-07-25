# 导入必要的模块：时间、操作系统、垃圾回收
import time, os, gc

# 导入媒体相关模块：传感器、显示、媒体管理
from media.sensor import *
from media.display import *
from media.media import *

# 定义图像宽度和高度常量
WIDTH = 640
HEIGHT = 480

# 初始化传感器变量为空
sensor = None

try:
    # 使用默认配置构造传感器对象
    sensor = Sensor()

    # 传感器复位
    sensor.reset()

    # 设置水平镜像（当前被注释）
    # sensor.set_hmirror(False)

    # 设置垂直翻转（当前被注释）
    # sensor.set_vflip(False)

    # 设置通道0的输出尺寸
    sensor.set_framesize(width = WIDTH, height = HEIGHT)

    # 设置通道0的输出格式为RGB565
    sensor.set_pixformat(Sensor.RGB565)

    # 使用IDE作为输出目标初始化显示
    Display.init(Display.ST7701, width = WIDTH, height = HEIGHT, to_ide = True)

    # 初始化媒体管理器
    MediaManager.init()

    # 启动传感器运行
    sensor.run()

    # 创建时钟对象用于计算帧率
    fps = time.clock()

    # 主循环
    while True:
        # 帧率计时器tick
        fps.tick()

        # 检查是否应该退出程序
        os.exitpoint()

        # 从传感器获取一帧图像
        img = sensor.snapshot()

        # 在屏幕上显示结果图像
        Display.show_image(img)

        # 执行垃圾回收
        gc.collect()

        # 短暂延时5毫秒
        time.sleep_ms(5)

        # 打印当前帧率
        print(fps.fps())

except KeyboardInterrupt as e:
    # 捕获键盘中断异常（用户手动停止）
    print(f"user stop")
except BaseException as e:
    # 捕获所有其他异常
    print(f"Exception '{e}'")
finally:
    # 无论如何都执行清理工作
    # 停止传感器运行（如果传感器对象存在）
    if isinstance(sensor, Sensor):
        sensor.stop()

    # 反初始化显示
    Display.deinit()

    # 设置退出点，允许进入睡眠模式
    os.exitpoint(os.EXITPOINT_ENABLE_SLEEP)

    # 短暂延时100毫秒
    time.sleep_ms(100)

    # 释放媒体缓冲区
    MediaManager.deinit()

