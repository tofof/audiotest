#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Keypad.h>
#include <string>
#include <queue>

//Setup for playing WAVs from the SD card.
//The teensy 4.1 has 8 MB of program flash, so I could use wav2sketch to convert wavs to .h files and play directly from memory.
//That would be faster, and would eliminate the SD card entirely, but it's not worth the effort right now.
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

std::queue<String> q;
char key;

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
  key = keypad.getKey(); //getKey can return a spurious hit on the first key the first time it's called because the keypad constructor doesn't initialize pins
  delay(1000);
}

void loop() {
  key = keypad.getKey();
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
      case 'A': q.push("and.wav"); break;
      case 'B': q.push("ball.wav"); break;
      case 'C': q.push("come.wav"); break;
      case 'D': q.push("done.wav"); break;
      case 'E': q.push("eatfood.wav"); break;
      case 'F': q.push("friend.wav"); break;
    }
  }

  if (q.size()>0 && !sdWavPlayer1.isPlaying()) {
    sdWavPlayer1.play(q.front().c_str());
    q.pop();
    delay(5); //access time, so we don't keep restarting playback
  }
  
}



