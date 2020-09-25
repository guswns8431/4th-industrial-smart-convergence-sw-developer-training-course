# python2 version execute

import smbus
import time
import math

address = 0x48
A0 = 0x40
A1 = 0x41
A2 = 0x42
A3 = 0x43

bus = smbus.SMBus(1)
while True:
    bus.write_byte(address, A0)
    a0_in = bus.read_byte(address)
    bus.write_byte(address, A1)
    a1_in = bus.read_byte(address)
    bus.write_byte(address, A2)
    a2_in = bus.read_byte(address)
    bus.write_byte(address, A3)
    a3_in = bus.read_byte(address)
    print("A0:%5d" % a0_in)
    print("A1:%5d" % a1_in)
    print("A2:%5d" % a2_in)
    print("A3:%5d" % a3_in)

    # LDR0
    a0_lux = 3.92 * a0_in

    # temp
    Vr = 3.3 * a1_in / 255
    Rt = 10000 * Vr / (5 - Vr)
    a1_temp = 1/(((math.log(Rt/10000)/3950) + (1/(273.15+25))))
    a1_temp = a1_temp - 273.15

    # LDR2
    a2_lux = 3.92 * a2_in

    # Potentio
    a3_volt = 0.02 * a3_in

    print("luminace_1 : %5d lx" % a0_lux)
    print("temp : %5d 'C" % a1_temp)
    print("luminace_2 :%5d lx" % a2_lux)
    print("POT : %5d V" % a3_volt)
    time.sleep(1)
