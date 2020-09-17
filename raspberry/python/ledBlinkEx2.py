import RPi.GPIO as GPIO
import time

led1 = 5 #GPIO5 : pin[29]
led2 = 6 #GPIO6 : pin[31]
led3 = 13 #GPIO13 : pin[33]
led4 = 19 #GPIO19 : pin[35]

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(led1,GPIO.OUT)
GPIO.setup(led2,GPIO.OUT)
GPIO.setup(led3,GPIO.OUT)
GPIO.setuo(led4,GPIO.OUT)

for i in range(10):
    GPIO.output(led1,1)
    time.sleep(1)
    GPIO.output(led1,0)  
    time.sleep(1)
    GPIO.output(led2,1)
    time.sleep(1)
    GPIO.output(led2,0)  
    time.sleep(1)
    GPIO.output(led3,1)
    time.sleep(1)
    GPIO.output(led3,0)  
    time.sleep(1)
    GPIO.output(led4,1)
    time.sleep(1)
    GPIO.output(led4,0)  
    time.sleep(1)

GPIO.cleanup()

