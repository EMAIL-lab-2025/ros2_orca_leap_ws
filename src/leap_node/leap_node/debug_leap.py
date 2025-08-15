#!/home/xingyi/.venvs/leapc/bin/python
import leap
import time

class DebugListener(leap.Listener):
    def on_tracking_event(self, event):
        for hand in event.hands:
            print(f"手的类型: {hand.type}")
            finger_names = ['thumb', 'index', 'middle', 'ring', 'pinky']
            
            for finger_name in finger_names:
                if hasattr(hand, finger_name):
                    finger = getattr(hand, finger_name)
                    if finger and hasattr(finger, 'bones') and finger.bones:
                        print(f"\n{finger_name} 手指:")
                        for i, bone in enumerate(finger.bones):
                            print(f"  骨骼 {i}:")
                            print(f"    属性: {[attr for attr in dir(bone) if not attr.startswith('_')]}")
                            # 检查位置信息
                            if hasattr(bone, 'prev_joint'):
                                print(f"    prev_joint: 存在")
                            if hasattr(bone, 'next_joint'):
                                print(f"    next_joint: 存在")
                            if hasattr(bone, 'direction'):
                                print(f"    direction: 存在")
            break  # 只调试第一只手
        print("=" * 50)

def main():
    listener = DebugListener()
    connection = leap.Connection()
    connection.add_listener(listener)
    
    with connection.open():
        connection.set_tracking_mode(leap.TrackingMode.Desktop)
        print("调试 Bone 结构，请挥动手部...")
        time.sleep(10)

if __name__ == '__main__':
    main()
