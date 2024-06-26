#include <Arduino.h>


//Fonctions Moteurs :
void Moteur_Init();
void setupPWM(int PWMpin, int PWMChannel);
void write_PWMD(double vitD);
void write_PWMG(double vitG);
