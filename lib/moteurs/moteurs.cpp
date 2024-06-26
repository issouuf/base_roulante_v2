#include <Arduino.h>
#include "moteurs.h"
#include "CRAC.h"

int inApin_MOTD = 16; // INA2 checked
int inApin_MOTG = 26; // INA1 checked
int inBpin_MOTD = 15; // INB2 checked
int inBpin_MOTG = 25; // INB1 checked







void Moteur_Init()
{
  // init pins carte de puiss
  pinMode(inApin_MOTG, OUTPUT);
  pinMode(inApin_MOTD, OUTPUT);
  pinMode(inBpin_MOTG, OUTPUT);
  pinMode(inBpin_MOTD, OUTPUT);
  pinMode(PWM_MOTG, OUTPUT);
  pinMode(PWM_MOTD, OUTPUT);
  pinMode(27, OUTPUT); // Je sais plus à quoi correspond cette pin
  // mise à l'arret
  digitalWrite(inApin_MOTG, 0);
  digitalWrite(inApin_MOTD, 1);
  digitalWrite(inBpin_MOTG, 1);
  digitalWrite(inBpin_MOTD, 0);
  // init pwm
  setupPWM(PWM_MOTD, PWMDChannel);
  setupPWM(PWM_MOTG, PWMGChannel);
  // ledcWrite(PWMDChannel, 2048);
  // ledcWrite(PWMGChannel, 2048);
}

//----------------------------------------------------------------------autres fonctions
/****************************************************************************************/
/* NOM : setupPWM                                                                       */
/* ARGUMENT : Pins de sortie et channel des PWM                                         */
/* RETOUR : rien                                                                        */
/* DESCRIPTIF : permet de setup les canaux de PWM et de les faire sortir sur les pins   */
/****************************************************************************************/
void setupPWM(int PWMpin, int PWMChannel)
{
  int freqMot = 20000;
  int resolution = 11;
  ledcSetup(PWMDChannel, freqMot, resolution);
  ledcSetup(PWMGChannel, freqMot, resolution);
  ledcAttachPin(PWM_MOTD, PWMDChannel);
  ledcAttachPin(PWM_MOTG, PWMGChannel);
}

//! Fonction de contrôle du moteur droit
void write_PWMD(double vitD)
{
  if (vitD > 0)
  {
    digitalWrite(inApin_MOTD, LOW);
    digitalWrite(inBpin_MOTD, HIGH);
    if (vitD > vitMax)
    {
      vitD = vitMax;
    }
    Serial.printf("vitD  ");
    Serial.println(vitD);
    ledcWrite(PWMDChannel, vitD);
  }
  else if (vitD < 0)
  {
    digitalWrite(inApin_MOTD, HIGH);
    digitalWrite(inBpin_MOTD, LOW);
    if (vitD < -vitMax)
    {
      vitD = -vitMax;
    }
    ledcWrite(PWMDChannel, -vitD);
  }
}

//! Fonction de contrôle du moteur gauche
void write_PWMG(double vitG)
{
  if (vitG > 0)
  {
    digitalWrite(inApin_MOTG, LOW);
    digitalWrite(inBpin_MOTG, HIGH);
    if (vitG > vitMax)
    {
      vitG = vitMax;
    }
    Serial.printf("vitG  ");
    Serial.println(vitG);
    ledcWrite(PWMGChannel, vitG);
  }
  else if (vitG < 0)
  {
    digitalWrite(inApin_MOTG, HIGH);
    digitalWrite(inBpin_MOTG, LOW);
    if (vitG < -vitMax)
    {
      vitG = -vitMax;
    }
    ledcWrite(PWMGChannel, -vitG);
  }
}