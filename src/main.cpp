#include <Arduino.h>

extern "C" {
  #include <Hermes.h>
}

#ifndef TEST
#define TEST 0
#endif

Hermes_t Hermes;

// put function declarations here:
int myFunction(int, int);

void setup() {

  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  pinMode(USER_BTN, INPUT);
  Serial.begin(115200);
  Serial.printf("Flag TEST = %d\n\r", TEST);
  Serial.printf("Flag HERMES_BUFFER_COUNT = %d\n\r", HERMES_BUFFER_COUNT);
  Serial.printf("Flag HERMES_MAX_BUFFER_LEN = %d\n\r", HERMES_MAX_BUFFER_LEN);
  Serial.printf("Hermes size = %d\n\r", sizeof(Hermes_t));

  Hermes_init(&Hermes, 12, 8);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Btn: %d\n\r", digitalRead(USER_BTN));
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}