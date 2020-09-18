from flask import Flask, request
import RPi.GPIO as GPIO

app = Flask(__name__)

LED = 5
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED, GPIO.OUT, initial=GPIO.LOW)

@app.route("/")
def helloworld():
    return "Hello World"
 
@app.route("/led")
def led():
    state = request.args.get("state","error")
    if state == "on":
        GPIO.output(LED, GPIO.HIGH)
    elif state == "off":
        GPIO.output(LED, GPIO.LOW)
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
