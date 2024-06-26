#include <Arduino.h>
#include <moteurs.h>
#include <CRAC.h>
#include <ESP32Encoder.h>



  


void setup() {
  Serial.begin(115200);
  Serial.println("debut init moteurs");
  Moteur_Init();
  Serial.println("fin init moteurs");


}



void loop() {

  
  write_PWMD(2048);
  write_PWMG(2048);
}