import serial
ser=serial.Serial("COM19", baudrate=9600,
                           bytesize=8) #CHANGE SERIAL NAME
print(ser.name)

import turtle as jack
jack.screensize(500, 500)
jack.hideturtle()
jack.penup()
jack.setposition(-500, -500)
jack.pendown()

def varFunc():
    arduinoInput0 = input("input: ")
    #arduinoInput2 = input("which knob? 0 - Left & 1 - Right")
    arduinoInput1 = str(arduinoInput0[0:4])
    #print(arduinoInput1)
    arduinoInput2 = str(arduinoInput0[4:-1])
    #print(arduinoInput2)
    cleanscreen = str(arduinoInput0[-1])
    #print(cleanscreen)
    return (arduinoInput1,arduinoInput2, cleanscreen)

while True:
    if(ser.in_waiting>0):
        jack.hideturtle()
        jack.delay(0)
        jack.speed(0)
        msgstring=ser.readline().decode('Ascii')[0:-2]
        #print(msgstring)
        arduinoInput0 = msgstring
        arduinoInput1 = str(arduinoInput0[0:4])
        #print(arduinoInput1)
        arduinoInput2 = str(arduinoInput0[4:-1])
        #print(arduinoInput2)
        cleanscreen = str(arduinoInput0[-1])
        #print(cleanscreen)
        #(inputHolder1,inputHolder2, cleanscreen) = varFunc()
        jack.setheading(90)
        jack.pendown()
        if int(cleanscreen) == 1:
            jack.clearscreen()
            jack.hideturtle()
            jack.up()
            jack.setx(var1)
            jack.sety(var2)
            jack.down()

        else:
            jack.setheading(0)
            var1 = (int(arduinoInput1) / 1.36)-382
            #print(var1)
            jack.setx(var1)
            #jack.up()
            jack.setheading(90)
            var2 = (int(arduinoInput2) / 1.6)-314
            #print(var2)
            jack.sety(var2)
            jack.up()
