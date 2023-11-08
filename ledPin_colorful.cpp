#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 3
#define NUM_PIXELS 120

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

int receivePin1 = 5;
int receivePin2 = 9;

void ledBlass(int a, int b_leds, int r, int g, int b){
  for (int i = a; i < b_leds; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
  delay(1);
  strip.clear();
}

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(10);
  strip.show();
  pinMode(receivePin1, INPUT);
  pinMode(receivePin2, INPUT);
}

void loop() {
  int receiverValue1 = pulseIn(receivePin1, HIGH);
  int receiverValue2 = pulseIn(receivePin2, HIGH);

  int ledCount = map(receiverValue2, 945, 1989, 0, NUM_PIXELS/2);
  ledBlass(0, ledCount, 255, 0, 0);

  // int ledCount2 = map(receiverValue1, 945, 1989, 60, NUM_PIXELS);
  // ledBlass(60, ledCount2, 0, 255, 0);

  // Serial.println(ledCount2);
    Serial.println(ledCount);
  delay(100);
}
