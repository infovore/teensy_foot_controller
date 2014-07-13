# Teensy Foot Controller

A class-compliant MIDI Foot controller powered by [Teensy](https://www.pjrc.com/teensy/teensy31.html).

## Requirements

* 6 momentary footswitches (SPST)
* two LEDs
* a Teensy 3.1

It uses the Bounce library. I programmed my Teensy via Teensyduino.


## Hardware

Momentary footswitches are all wired directly into pins 14-19.

LEDs are wired directly into pins 12/11 (because it's 3.3v so we don't really need a resistor).

## Usage

It's a class-compliant MIDI HID device, so you should just be able to plug it into your computer and have it picked up immediately. (It might even work with an iPad, I don't know).

The controller has two "pages" of notes. When it starts up, buttons 0-4 transmit MIDI notes 60-64. Pushing button 5 will toggle to "page 2", lighting the other LED, and then buttons 0-4 will transmit 72-76.

It was built as a foot controller for [Sooperlooper](http://sonosaurus.com/sooperlooper/), but would work as equally well as a transport controller for your DAW, for other plugins, or for DJ tools like Traktor.

It sends both NoteOn and NoteOff messages for each button, so you might want to make your mapping detect "NoteOn" rather than "Note" if you have double-triggering issues (which I did, in Sooperlooper/Reaper).