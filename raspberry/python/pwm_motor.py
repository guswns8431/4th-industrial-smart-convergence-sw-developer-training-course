import RPi.GPIO as GPIO
import time
servo = 18
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(servo,GPIO.OUT)
svoFreq = GPIO.PWM(servo,50)
svoFreq.start(0)
try:
    while True:
        svoFreq.ChangeDutyCycle(7.5)
        time.sleep(1)
        svoFreq.ChangeDutyCycle(12.5)
        time.sleep(1)
        svoFreq.ChangeDutyCycle(2.5)
        time.sleep(1)
except KeyboardInterrupt:
    svoFreq.stop()
    GPIO.Cleanup()
