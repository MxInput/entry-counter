#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

#define OLED_RESET -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define MOTION_PIN 19
#define CLEAR_PIN 26
#define DELETE_PIN 18
#define RELAY_PIN 4

int number_of_entrants = 0;

int currentMotion;
int prevMotion;

int clearInput;
int deleteInput;

unsigned long initialMillis;
unsigned long currentMillis;
const unsigned long sound_length = 1000;

bool checked = false;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Entries: ");
  display.println(number_of_entrants);
  display.display(); 

  pinMode(MOTION_PIN, INPUT);
  pinMode(CLEAR_PIN, INPUT_PULLUP);
  pinMode(DELETE_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);

  initialMillis = millis();
}

void loop() {
  currentMotion = digitalRead(MOTION_PIN);
  clearInput = digitalRead(CLEAR_PIN);
  deleteInput = digitalRead(DELETE_PIN);
  Serial.println(clearInput);

  if (digitalRead(RELAY_PIN) == HIGH) {
    currentMillis = millis();

    if (currentMillis - initialMillis >= sound_length) {
      digitalWrite(RELAY_PIN, LOW);
    }
  }

  if (prevMotion == LOW && currentMotion == HIGH && !checked) {
    number_of_entrants++;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Entries: ");
    display.println(number_of_entrants);
    display.display(); 

    digitalWrite(RELAY_PIN, HIGH);
    
    checked = true;
    delay(3000);
  }

  if (prevMotion == LOW && currentMotion == HIGH) {
    checked = false;
  }

  if (clearInput == HIGH) {
    number_of_entrants = 0;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("CLEARING ENTRANT COUNT");
    display.display(); 

    delay(1000);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Entries: ");
    display.println(number_of_entrants);
    display.display(); 
    clearInput = LOW;
    delay(1000);
  }

  if (deleteInput == HIGH) {
    number_of_entrants--;
    if (number_of_entrants < 0) {
      number_of_entrants = 0;
    }

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("DECREMENTING COUNT");
    display.display(); 

    delay(1000);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Entries: ");
    display.println(number_of_entrants);
    display.display(); 
  }
}