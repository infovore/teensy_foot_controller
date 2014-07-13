#include <Bounce.h>

const int channel = 1; // midi Channel 1

Bounce button0 = Bounce(14,5); // pin 14 is the first button.
Bounce button1 = Bounce(15,5); 
Bounce button2 = Bounce(16,5); 
Bounce button3 = Bounce(17,5); 
Bounce button4 = Bounce(18,5); 
Bounce button5 = Bounce(19,5); 

int led1 = 12;
int led2 = 11;

int page = 0;

void setup() {
  // pullups. Connect pin -> button -> ground
  // button reads LOW when pushed to ground.
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if(page == 0) {
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
  } else {
    digitalWrite(led2, 1);
    digitalWrite(led1, 0);
  }
  
  // first, update all the buttons
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  
  if (button0.fallingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOn(60, 99, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOn(72, 99, channel);  // 60 = C4
    }
  }
  if (button1.fallingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOn(61, 99, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOn(73, 99, channel);  // 60 = C4
    }
  }
    if (button2.fallingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOn(62, 99, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOn(74, 99, channel);  // 60 = C4
    }
  }
  if (button3.fallingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOn(63, 99, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOn(75, 99, channel);  // 60 = C4
    }
  }
  if (button4.fallingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOn(64, 99, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOn(76, 99, channel);  // 60 = C4
    }
  }
  if (button5.fallingEdge()) {
    page = 1-page;
  }
  
  if (button0.risingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOff(60, 0, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOff(72, 0, channel);  // 60 = C4
    }
  }
  if (button1.risingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOff(61, 0, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOff(73, 0, channel);  // 60 = C4
    }
  }
  
    if (button2.risingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOff(62, 0, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOff(74, 0, channel);  // 60 = C4
    }
  }
  if (button3.risingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOff(63, 0, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOff(75, 0, channel);  // 60 = C4
    }
  }
  if (button4.risingEdge()) {
    if(page == 0) {
      usbMIDI.sendNoteOff(64, 0, channel);  // 60 = C4
    } else {
      usbMIDI.sendNoteOff(76, 0, channel);  // 60 = C4
    }
  }

  
  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // 
  }
}

