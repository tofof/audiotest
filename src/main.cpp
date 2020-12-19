#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Keypad.h>
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

//setup for keypad
#define ROWS 8 
#define COLS 10 
char keys[ROWS][COLS] = {
  {'\x10','\x11','\x12','\x13','\x14','\x15','\x16','\x17','\x18','\x19'},
  {'\x20','\x21','\x22','\x23','\x24','\x25','\x26','\x27','\x28','\x29'},
  {'\x30','\x31','\x32','\x33','\x34','\x35','\x36','\x37','\x38','\x39'},
  {'\x40','\x41','\x42','\x43','\x44','\x45','\x46','\x47','\x48','\x49'},
  {'\x50','\x51','\x52','\x53','\x54','\x55','\x56','\x57','\x58','\x59'},
  {'\x60','\x61','\x62','\x63','\x64','\x65','\x66','\x67','\x68','\x69'},
  {'\x70','\x71','\x72','\x73','\x74','\x75','\x76','\x77','\x78','\x79'},
  {'\x80','\x81','\x82','\x83','\x84','\x85','\x86','\x87','\x88','\x89'},
}; //I would prefer to have both be zero-indexed but \x00 is NO_KEY
byte rowPins[ROWS] = { 24, 25, 26, 27, 28, 29, 30, 31 };        
byte colPins[COLS] = { 41, 40, 39, 38, 37, 36, 35, 34, 33, 32 }; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

std::queue<int> q;
char key;
char lastkey;
char filename[6];
elapsedMillis msSinceLastEnqueue;
#define DEBOUNCE_TIME_MINIMUM 100
#define DEBOUNCE_TIME_IF_SAME 500

void setup() {
  Serial.begin(9600);
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(1.0);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  while (!(SD.begin(SDCARD_CS_PIN))) {
      Serial.println("Unable to access the SD card");
      delay(500);
  }
  //keypad.setDebounceTime(200); //keypad's implementation limits how often key matrix is scanned, decreasing responsiveness
  key = keypad.getKey(); //getKey can return a spurious hit on the first key the first time it's called because the keypad constructor doesn't initialize pins
  delay(1000);
}

void loop() {
  key = keypad.getKey();
  if (key != NO_KEY && msSinceLastEnqueue > DEBOUNCE_TIME_MINIMUM) {
    Serial.printf("key: %c", key);
    Serial.printf("  id: %02x", (int) key);
    // for (int i=0; i<ROWS; i++) {
    //   for (int j=0; j<COLS; j++) {
    //     if (key == keys[i][j]) 
    //       Serial.printf("  row:%d  col:%d  rpin:%d  cpin:%d", i, j, rowPins[i], colPins[j]);
    //   }
    // }
    Serial.println();

    if (key != lastkey || msSinceLastEnqueue > DEBOUNCE_TIME_IF_SAME) {
      q.push((int) key);
      lastkey=key;
      msSinceLastEnqueue=0;
    }
  }

  if (q.size()>0 && !sdWavPlayer1.isPlaying()) {
    sprintf(filename, "%02x.wav", q.front());
    Serial.printf("Playing %s\n", filename);
    sdWavPlayer1.play(filename);
    q.pop();
    delay(5); //access time, so we don't keep restarting playback
  }
}