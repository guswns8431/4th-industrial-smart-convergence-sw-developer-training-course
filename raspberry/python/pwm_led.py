import RPi.GPIO as GPIO
import time

pwmLED = 13

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(pwmLED,GPIO.OUT)

p = GPIO.PWM(pwmLED,50) #frequency = 50Hz
p.start(0)

try:
    while 1:
        for dc in range(0,101,5):
            p.ChangeDutyCycle(dc)
            time.sleep(0.1)
        for dc in range(100,-1,-5):
            p.ChangeDutyCycle(dc)
            time.sleep(0.1)
except KeyboardInterrupt:
    pass
p.stop()
GPIO.cleanup()
