from flask import Flask,request
from flask import render_template
import RPi.GPIO as GPIO
import time as t

app = Flask(__name__)

LED_red = 5
LED_yellow = 6
LED_green = 13

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_red, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(LED_yellow,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(LED_green,GPIO.OUT,initial=GPIO.LOW)

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/led/red")
def red_on():
    try:
        GPIO.output(LED_red,GPIO.HIGH)
        return "ok"
    except expression as identifier:
        return "fail"

@app.route("/led/offred")
def red_off():
    try:
        GPIO.output(LED_red,GPIO.LOW)
        return "ok"
    except expression as identifier:
        return "fail"
@app.route("/led/yellow")
def yellow_on():
    try:
        GPIO.output(LED_yellow,GPIO.HIGH)
        return "ok"
    except expression as identifier:
        return "fail"

@app.route("/led/offyellow")
def yellow_off():
    try:
        GPIO.output(LED_yellow,GPIO.LOW)
        return "ok"
    except expression as identifier:
        return "fail"

@app.route("/led/green")
def green_on():
    try:
        GPIO.output(LED_green,GPIO.HIGH)
        return "ok"
    except expression as identifier:
        return "fail"

@app.route("/led/offgreen")
def green_off():
    try:
        GPIO.output(LED_green,GPIO.LOW)
        return "ok"
    except expression as identifier:
        return "fail"

@app.route("/led/off")
def off():
    try:
        GPIO.output(LED_red,GPIO.LOW)
        GPIO.output(LED_yellow,GPIO.LOW)
        GPIO.output(LED_green,GPIO.LOW)
        return "ok"
    except expression as identifier:
        return "fail"

@app.route("/led/all")
def all():
    try:
        GPIO.output(LED_red,GPIO.HIGH)
        GPIO.output(LED_yellow,GPIO.HIGH)
        GPIO.output(LED_green,GPIO.HIGH)
        return "ok"
    except expression as identifier:
        return "fail"

@app.route("/led/showtime")
def showtime():
    try:
        GPIO.output(LED_red,GPIO.HIGH)
        t.sleep(0.3)
        GPIO.output(LED_red,GPIO.LOW)
        t.sleep(0.3)
        GPIO.output(LED_yellow,GPIO.HIGH)
        t.sleep(0.3)
        GPIO.output(LED_yellow,GPIO.LOW)
        t.sleep(0.3)
        GPIO.output(LED_green,GPIO.HIGH)
        t.sleep(0.3)
        GPIO.output(LED_green,GPIO.LOW)
        t.sleep(0.3)
        return "ok"
    except expression as identifier:
        return "fail"

@app.route("/gpio/cleanup")
def gpio_cleanup():
    try:
        GPIO.cleanup()
        return "GPIO CLEANUP"
    except expression as identifier:
        return "fail"

if __name__ == "__main__":
    app.run(host="192.168.0.123")
