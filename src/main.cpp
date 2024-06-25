#include <Arduino.h>
#include <moteurs.h>
#include <CRAC.h>



void setup() {
  Serial.begin(115200);
  Serial.println("debut init moteurs");
  Moteur_Init();
  Serial.println("fin init moteurs");


}



void loop() {



}