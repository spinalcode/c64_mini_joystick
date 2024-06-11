/*
 * c64mini-arcade2usb-converter.ino
 * 
 * C64 Mini Arcade Joystick to USB Converter.
 *  
 * Version 1.1 (See CHANGELOG)
 * Release date: 2019-04-19
 *  
 * Written & released by M.F. Wieland (TSB)
 *  
 *  Licensed under the MIT License. See LICENSE file in the project root for full license information.  
 */

#include "joystick.h" 

// define buttons
// define buttons
const int pin_joystick_up = 2;
const int pin_joystick_down = 3;
const int pin_joystick_left = 4;
const int pin_joystick_right = 5;
const int pin_joystick_button1 = 6;

const int pin_joystick_button_menu = 7;
const int pin_joystick_button_a = 8;
const int pin_joystick_button_b = 9;
const int pin_joystick_button_c = 10;
const int pin_joystick_button2 = 16;

const int pin_joystick_switch = 14;

void setup() {
  
  // setup input pins
  pinMode(pin_joystick_up, INPUT_PULLUP);       
  pinMode(pin_joystick_down, INPUT_PULLUP);       
  pinMode(pin_joystick_left, INPUT_PULLUP);       
  pinMode(pin_joystick_right, INPUT_PULLUP);       
  pinMode(pin_joystick_button1, INPUT_PULLUP);       
  pinMode(pin_joystick_button2, INPUT_PULLUP);       
  pinMode(pin_joystick_button_menu, INPUT_PULLUP);       
  pinMode(pin_joystick_button_a, INPUT_PULLUP);       
  pinMode(pin_joystick_button_b, INPUT_PULLUP);       
  pinMode(pin_joystick_button_c, INPUT_PULLUP);       
  pinMode(pin_joystick_switch, INPUT_PULLUP);       
}

void loop() {
  
  // Reset values for next loop..  
  Joystick.reset();
  
  if (digitalRead(pin_joystick_switch) == LOW) {
    // Button - Fire (1)
    if (digitalRead(pin_joystick_button1) == LOW) {
      Joystick.button_press(0b1000000); 
    }
    // Button - Fire (2)
    if (digitalRead(pin_joystick_button2) == LOW) {
      Joystick.button_press(0b100000); 
    }
  }else{
    // Button - Fire (1)
    if (digitalRead(pin_joystick_button1) == LOW) {
      Joystick.button_press(0b1);
    }
    // Button - Fire (2)
    if (digitalRead(pin_joystick_button2) == LOW) {
      Joystick.button_press(0b1000);
    }
    
  }
  // Button - Menu
  if (digitalRead(pin_joystick_button_menu) == LOW) {
    Joystick.button_press(0b1000000000);
  }

  // Button - C
  if (digitalRead(pin_joystick_button_a) == LOW) {
    Joystick.button_press(0b100000000);
  }
  
  // Button - B (not in use at this moment)
  if (digitalRead(pin_joystick_button_b) == LOW) {
    Joystick.button_press(0b10);
  }

  // Button - A
  if (digitalRead(pin_joystick_button_c) == LOW) {
    Joystick.button_press(0b100);
  }

  // Button - Up
  if (digitalRead(pin_joystick_up) == LOW) {
    Joystick.up();  
  }
  
  // Button - Right
  if (digitalRead(pin_joystick_right) == LOW) {
    Joystick.right();
  }
  
  // Button - Down
  if (digitalRead(pin_joystick_down) == LOW) {
    Joystick.down();
  }
  
  // Button - Left
  if (digitalRead(pin_joystick_left) == LOW) {
    Joystick.left();
  }
  
  // update joystick actions
  Joystick.usb_update();
}

// Add the following to your boards.txt to allow changing the ID of the leonardo to that of a game controller
/*
##############################################################

leonardoC64.name=Arduino Leonardo C64
leonardoC64.vid.0=0x2341
leonardoC64.pid.0=0x0036
leonardoC64.vid.1=0x2341
leonardoC64.pid.1=0x8036
leonardoC64.vid.2=0x2A03
leonardoC64.pid.2=0x0036
leonardoC64.vid.3=0x2A03
leonardoC64.pid.3=0x8036

leonardoC64.upload.tool=avrdude
leonardoC64.upload.protocol=avr109
leonardoC64.upload.maximum_size=28672
leonardoC64.upload.maximum_data_size=2560
leonardoC64.upload.speed=57600
leonardoC64.upload.disable_flushing=true
leonardoC64.upload.use_1200bps_touch=true
leonardoC64.upload.wait_for_upload_port=true

leonardoC64.bootloader.tool=avrdude
leonardoC64.bootloader.low_fuses=0xff
leonardoC64.bootloader.high_fuses=0xd8
leonardoC64.bootloader.extended_fuses=0xcb
leonardoC64.bootloader.file=caterina/Caterina-Leonardo.hex
leonardoC64.bootloader.unlock_bits=0x3F
leonardoC64.bootloader.lock_bits=0x2F

leonardoC64.build.mcu=atmega32u4
leonardoC64.build.f_cpu=16000000L
leonardoC64.build.vid=0x22BA
leonardoC64.build.pid=0x1020
leonardoC64.build.usb_product="The C64 Joystick"
leonardoC64.build.board=AVR_LEONARDO
leonardoC64.build.core=arduino
leonardoC64.build.variant=leonardo
leonardoC64.build.extra_flags={build.usb_flags}

##############################################################
*/
