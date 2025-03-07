from gpiozero import OutputDevice

pin = OutputDevice(17)

def control_gpio(state):
    if state == "on":
        pin.on()
        print("GPIO 17번 핀: HIGH")
    elif state == "off":
        pin.off()
        print("GPIO 17번 핀: LOW")
