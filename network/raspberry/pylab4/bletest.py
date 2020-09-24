from bluetooth import *

client_socket = BluetoothSocket(RFCOMM)
client_socket.connect("C8:FD:19:88:8C:67",1)

while True:
    msg = raw_input("Send : ")
    print(msg)
    client_socket.send(msg)

print("Finished")

client_socket.close()
