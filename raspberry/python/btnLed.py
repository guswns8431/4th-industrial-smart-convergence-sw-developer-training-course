import RPi.GPIO as GP
import time
btn = 23
led = 5
GP.setwarnings(False)
GP.setmode(GP.BCM)
GP.setup(btn,GP.IN,pull_up_down=GP.PUD_DOWN)
GP.setup(led,GP.OUT)

light_on = False

def button_callback(channel):
    global light_on
    if light_on == False:
        GP.output(led,1)
        print("LED ON!")
    else:
        GP.output(led,0)
        print("LED OFF!")
    light_on = not light_on
GP.add_event_detect(btn,GP.RISING,callback=button_callback,bouncetime=300)
while 1:
    time.sleep(0.1)


