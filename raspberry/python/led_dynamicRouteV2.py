from flask import Flask, request
import RPi.GPIO as GPIO
import time as t

app = Flask(__name__)

LED_red = 5
LED_yellow = 6
LED_green = 13
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_red, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(LED_yellow, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(LED_green, GPIO.OUT, initial=GPIO.LOW)

@app.route("/")
def helloworld():
    return "Hello World"
 
@app.route("/led")
def led():
    state = request.args.get("state","error")
    if state == "red":
        GPIO.output(LED_red, GPIO.HIGH)
    elif state == "yellow":
        GPIO.output(LED_yellow, GPIO.HIGH)
    elif state == "green":
        GPIO.output(LED_green, GPIO.HIGH)
    elif state == "all":
        GPIO.output(LED_red,GPIO.HIGH) 
        GPIO.output(LED_yellow,GPIO.HIGH)  
        GPIO.output(LED_green,GPIO.HIGH)
    elif state == "offred":
        GPIO.output(LED_red,GPIO.LOW)
    elif state == "offyellow":
        GPIO.output(LED_yellow,GPIO.LOW)
    elif state == "offgreen":
        GPIO.output(LED_green,GPIO.LOW)
    elif state == "off":
        GPIO.output(LED_red, GPIO.LOW)   
        GPIO.output(LED_yellow, GPIO.LOW)   
        GPIO.output(LED_green, GPIO.LOW)
    elif state == "showtime":
        GPIO.output(LED_red, GPIO.HIGH)
        t.sleep(0.5)
        GPIO.output(LED_red, GPIO.LOW)
        t.sleep(0.5)
        GPIO.output(LED_yellow, GPIO.HIGH)
        t.sleep(0.5)
        GPIO.output(LED_yellow, GPIO.LOW)
        t.sleep(0.5)
        GPIO.output(LED_green, GPIO.HIGH)
        t.sleep(0.5)
        GPIO.output(LED_green, GPIO.LOW)
        t.sleep(0.5)
    elif state == "error":
        return "ㅎㅎㅎㅎquery wasn't deliveried"
    else:
        return "wrong query was deliveried"
    return "LED"+state

@app.route("/gpio/cleanup")
def gpio_cleanup():
    GPIO.cleanup()
    return "GPIO CLEANUP"

if __name__ == "__main__":
    app.run(host="192.168.0.123")
