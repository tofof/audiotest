#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Keypad.h>

AudioPlaySdWav           sdWavPlayer1;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(sdWavPlayer1, 0, i2s1, 0);
AudioConnection          patchCord2(sdWavPlayer1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;
#define SDCARD_CS_PIN    BUILTIN_SDCARD
#define SDCARD_MOSI_PIN  11  // not actually used
#define SDCARD_SCK_PIN   13  // not actually used

#define ROWS 2 
#define COLS 3 
char keys[ROWS][COLS] = {
  {'A','B','C'},
  {'D','E','F'},
};
byte rowPins[ROWS] = { 24, 25 };        // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 41, 40, 39 };  // Connect keypad COL0, COL1 and COL2 to these Arduino pins.
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  Serial.begin(9600);
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);   //TODO: change to 0.8 or more for installation
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  delay(1000);
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    Serial.printf("key:%c",key);
    // for (int i=0; i<ROWS; i++) {
    //   for (int j=0; j<COLS; j++) {
    //     if (key == keys[i][j]) 
    //       Serial.printf("  row:%d  col:%d  rpin:%d  cpin:%d", i, j, rowPins[i], colPins[j]);
    //   }
    // }
    Serial.println();

    switch(key) {
      case 'A': sdWavPlayer1.play("and.wav"); break;
      case 'B': sdWavPlayer1.play("ball.wav"); break;
      case 'C': sdWavPlayer1.play("come.wav"); break;
      case 'D': sdWavPlayer1.play("done.wav"); break;
      case 'E': sdWavPlayer1.play("eatfood.wav"); break;
      case 'F': sdWavPlayer1.play("friend.wav"); break;
    }
    delay(10); //allow parsing file
  }

  
}



