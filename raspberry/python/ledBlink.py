import RPi.GPIO as GPIO
import time

led1 = 5 #GPIO5 : pin[29]
GPIO.setwarnings(false)
GPIO.setmode(GPIO.BCM)
GPIO.setup(led1,GPIO.OUT)

 for i in range(10):
      GPIO.output(led1,1)
      time.sleep(1)
      GPIO.output(led1,0)
      time.sleep(1)
GPIO.cleanup()
