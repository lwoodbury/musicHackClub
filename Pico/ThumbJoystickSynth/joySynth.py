#import the required modules/libraries
from machine import Pin, PWM, ADC
from utime import sleep

#set up the pins
built_in_led = Pin(25, Pin.OUT) #use the built in LED as an 'On' indicator
speaker = PWM(Pin(15))
yPot = ADC(Pin(27)) # y axis of joystick
xPot = ADC(Pin(28)) # x axis

built_in_led.on() #turn LED on

# 'convert' function returns an integer between out_min and out_max
# use to scale the joystick input to an output range that we want
# just like 'map' function in Arduino
def convert(x, i_m, i_M, o_m, o_M):
    return max(min(o_M, (x - i_m) * (o_M - o_m) // (i_M - i_m) + o_m), o_m)

# function to play our tone
def playtone(vol, frequency):
    speaker.duty_u16(vol)
    speaker.freq(frequency)

# the loop
while True:
    # read the joystick input to set values
    vol = (xPot.read_u16()) 
    freq = (yPot.read_u16())
    #print(vol)
    # use 'convert' function to set range of values desired
    vol = convert(vol, 34000, 65535, 0, 1000) # 0 to full volume
    # mapping musical note to frequencies as described here https://github.com/bhagman/Tone
    freq = convert(freq, 65535, 400, 65, 262) # play notes from C2 to C4
    #print(vol)
    # play the tone
    playtone(vol, freq)
    sleep(0.05)

