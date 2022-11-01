# This project requires PyBluez
import tkinter
from tk import *
import bluetooth



def tryConnection():
    #Look for all Bluetooth devices
    print ("Searching for devices...")

    #Create an array with all the MAc addresses of the detected devices
    nearby_devices = bluetooth.discover_devices()
    names_devices= []

    #Run through all the devices found and list their name
    num = 0
    print ("Select your device by entering its coresponding number...")

    for i in nearby_devices:
        num+=1
        name = bluetooth.lookup_name( i )
        print (num , ": " , name)
        names_devices.append(name)

    print(0,": ", "Quit?")

    selection = int(input("> ")) - 1 
    if (selection < 0 ):
        print("Program OVER")
        return 1
    if names_devices[selection] == "None":
        print("WRONG BLE Device Chosen")
        return 2
    print ("You have selected", str(bluetooth.lookup_name(nearby_devices[selection])))

    bd_addr = nearby_devices[selection]

    port = 1
    
    print("Init BLE SOCKET --> ....")
    sock = bluetooth.BluetoothSocket( bluetooth.RFCOMM )
    print("Init BLE SOCKET --> done ")

    print("TRY CONNECTION ...")
    try :
        sock.connect((bd_addr, port))
        test = input("END test ?")
        sock.close()
        return 0
    except :
        print("ERROR occured retry conection")
        return -1

if __name__ == "__main__":
    connection_result = tryConnection()
    if connection_result == -1 :
        print("i will retry connection")
    elif connection_result == 2 :
        print("retry and choose an others number")
    elif connection_result == 1 :
        exit
    elif connection_result == 0:
        print("Continuer execution")