#include "main.h"

pinConfig_struct pinConfig;
bool aPin;
bool bPin;
bool prev_aPin;
bool prev_bPin;


void setup() {
  Serial.begin(115200);
  Serial.println("decoder boot...");
  pinMode(pinConfig.a,INPUT_PULLUP);
  pinMode(pinConfig.b,INPUT_PULLUP);
}

void loop() {
  aPin = digitalRead(pinConfig.a);
  bPin = digitalRead(pinConfig.b);

  if (aPin != prev_aPin || bPin != prev_bPin) {

        // Jobbra forgás állapotok
        if (prev_aPin == 0 && prev_bPin == 0 && aPin == 1 && bPin == 0) {
            Serial.println("Jobbra tekerted");
        }
        else if (prev_aPin == 1 && prev_bPin == 0 && aPin == 1 && bPin == 1) {
            Serial.println("Jobbra tekerted");
        }
        else if (prev_aPin == 1 && prev_bPin == 1 && aPin == 0 && bPin == 1) {
            Serial.println("Jobbra tekerted");
        }
        else if (prev_aPin == 0 && prev_bPin == 1 && aPin == 0 && bPin == 0) {
            Serial.println("Jobbra tekerted");
        }

        // Balra forgás állapotok
        else if (prev_aPin == 0 && prev_bPin == 0 && aPin == 0 && bPin == 1) {
            Serial.println("Balra tekerted");
        }
        else if (prev_aPin == 0 && prev_bPin == 1 && aPin == 1 && bPin == 1) {
            Serial.println("Balra tekerted");
        }
        else if (prev_aPin == 1 && prev_bPin == 1 && aPin == 1 && bPin == 0) {
            Serial.println("Balra tekerted");
        }
        else if (prev_aPin == 1 && prev_bPin == 0 && aPin == 0 && bPin == 0) {
            Serial.println("Balra tekerted");
        }

        // debug kiírás
        Serial.print("aPin: ");
        Serial.print(aPin);
        Serial.print(" bPin: ");
        Serial.print(bPin);
        Serial.println();
    }

    prev_aPin = aPin;
    prev_bPin = bPin;
}
