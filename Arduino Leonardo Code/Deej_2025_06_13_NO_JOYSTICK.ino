#include <Keyboard.h>
#include <Joystick.h>

#define KEY_F20 0xF7
#define KEY_F21 0xF8
#define KEY_F22 0xF9


// Sliders for Deej
const int NUM_SLIDERS = 5;
const int NUM_BUT = 3;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3, A4};
const int digitalInputs[NUM_BUT] = {2, 3, 4};

int analogSliderValues[NUM_SLIDERS];


// Setup
void setup() { 
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }
  
  for (int i = 0; i < NUM_BUT; i++) {
    pinMode(digitalInputs[i], INPUT_PULLUP);
  }
  
  Serial.begin(9600);
  Keyboard.begin();

}

// Main loop
void loop() {
  updateSliderValues();
  sendSliderValues(); // Actually send data (all the time)

  teclado();
  
  // printSliderValues(); // For debug
  delay(10);
}

void teclado() {
  //if the button is pressed

  if (digitalRead(2) == LOW) {
    Keyboard.press(KEY_F20);
    delay(100);
  }else if (digitalRead(3) == LOW){
    Keyboard.press(KEY_F21);
    delay(100);
  }else{
    Keyboard.release(KEY_F20);
    Keyboard.release(KEY_F21);
  }

  if (digitalRead(4) == LOW) {
    //Send the message
    Keyboard.press(KEY_F22);
  }else {
    Keyboard.release(KEY_F22);
  }
}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}
