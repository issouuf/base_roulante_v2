#include <Arduino.h>
#include "moteurs.h"
#include "ESP32Encoder.h"





#define COEFF_ROUE_GAUCHE 0
#define COEFF_ROUE_DROITE 0

/* encodeurs */
ESP32Encoder Encoder_Gauche;
ESP32Encoder Encoder_Droit; 


//! Fonction d'initialisation des encodeurs
void encodeurs_Init() {
    ESP32Encoder::useInternalWeakPullResistors;
    Encoder_Gauche.attachFullQuad(36,39); 
    Encoder_Droit.attachFullQuad(23,22);

    Encoder_Gauche.clearCount();
    Encoder_Droit.clearCount();
}


//! Fonction de lecture de l'encodeur gauche
double lecture_Encoder_Gauche() {
    return COEFF_ROUE_GAUCHE * Encoder_Gauche.getCount();
}

//! Fonction de lecture de l'encodeur droit

double lecture_Encoder_Droit() {
    return COEFF_ROUE_DROITE * Encoder_Droit.getCount();
}

