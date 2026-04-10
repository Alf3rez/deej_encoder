# Deej system with encoder

In this repository you could find my project to build a [Deej](https://github.com/omriharel/deej) that have the posibility to be mounted screwed under desk or you can always put your own feets and use it on the desk.

You'll find my 3D models ready to print, the Arduino code (designed to use with any Arduino with keyboard capability to map the encoder keys), another code to also map your knobs as analog controls froma a joystick (not recommended unless you have a clear purpose to this use, because will mess up with other controllers in games) and and scheme of connection I used to build mine.

The design has in mind repairability, making easy to replace potenciometers, which are commonly wear out rapidly with frequent use.

## Arduino code

The easiest way of implement the encoder is using the Encoder library, the one I used was "Encoder by Paul Stoffregen", right now in version 1.4.4.

But for my needs I prefer to map the imputs directly to key strokes thanks to keyboard capabilities of Leonardo's board and keyboard library, so I defined the three function keys F20, F21 & F22 to avoid conflicts and due to the behaviour of encoders when a low imput is detected it translate in a switch of the encoder, and as it correspond to different pins is easy to map.

## 3D Models

You'll find 4 .stl files ready to be printed, each one gives you the option to build a slide body for any Arduino with the same mounting as Leonardo's one and 5 potenciometers and 1 encoder, also if you prefer a mounted ready side with the holes or just blank for any other purpose.
