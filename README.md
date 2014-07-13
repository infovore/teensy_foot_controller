# Teensy Foot Controller

A MIDI Foot controller powered by Teensy.

As described, this code expects:

* 6 momentary footswitches
* two LEDs
* a Teensy 3.1

Momentary footswitches are all wired directly into pins 14-19.

LEDs are wired directly into pins 12/11 (because it's 3.3v so we don't really need a resistor).

The controller has two "pages" of notes. When it starts up, buttons 0-4 transmit MIDI notes 60-64. Pushing button 5 will toggle to "page 2", lighting the other LED, and then buttons 0-4 will transmit 72-76.

It was built as a foot controller for [Sooperlooper](http://sonosaurus.com/sooperlooper/), but would work as equally well as a transport controller for your DAW, for other plugins, or for DJ tools like Traktor.