# 摄像头显示
import sys
import uos as os
import time

from media.sensor import *
from media.display import *
from media.media import *

def init_sensor():
    sensor = Sensor(width=1280, height=960)

    sensor.reset()

    sensor.set_framesize(width=640, height=480, chn=CAM_CHM_ID_1)
    sensor.set_pixformat(Sensor.RGB565, chn=CAM_CHM_ID_1)

    sensor.set_framesize(width=640, height=480, chn=CAM_CHM_ID_0)
    sensor.set_pixformat(Sensor.GRAYSCALE, chn=CAM_CHM_ID_0)

    return sensor

def main():
    sensor = None
    roi=(220, 140, 200, 200)
    try:
        sensor = init_sensor()

        Display.init(Display.VIRT, width=640, height=480, to_ide=True)

        MediaManager.init()

        sensor.run()

        while True:
            img = sensor.snapshot(chn=CAM_CHM_ID_1)

            img_g = sensor.snapshot(chn=CAM_CHM_ID_0)
            img.draw_rectangle(roi, color=(173, 216, 230), fill=False, thickness=3)
            keypoints = img_g.find_keypoints(
                threshold=30,
                scale_factor=1.2,
                max_keypoints=30,
                roi=roi
            )
            if keypoints:
                print(keyoints)
                img.draw_keypoints(
                    keypoints,
                    color=(255, 0, 0),
                    size = 8,
                    thickness=4,
                    fill=True
                )
            Display.show_image(img)

    except KeyboardInterrupt:
        print("User interrupted the program")
        print("用户中断了程序")

    except Exception as e:
        print(f"An error occurred:{str(e)}")
        print(f"发生错误：{str(e)}")

    finally:
        if isinstance(sensor, Sensor):
            sensor.stop()

        Display.deinit()

        os.exitpoint(os.EXITPOINT_ENABLE_SLEEP)
        time.sleep_ms(100)

        MediaManager.deinit()

if __name__ == "__main__":
    main()

