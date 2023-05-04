/**
 * @file interfaceT1.ino
 * @author CamFo Camille Fortin (camfortin2022@gmail.com)
 * @brief Interface qui contrôle la del su Board Adafruit ESP32 feather
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//INCLUSIONS
#include "main.h"
#include "piloteIOT1.h"
#include "interfaceT1.h"

//Definitions privees
//pas de definitions privees

//Declarations de fonctions privees:
//pas de fonction privees

//Definitions de variables privees:
//pas de variables privees

//Definitions de fonctions privees:
//pas de fonctions privees
int i=0;
bool Sense = true;

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void interfaceT1_allume(void)
{
  // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(0, pixels.Color(i, 100, 255-i));

    pixels.show();   // Send the updated pixel colors to the hardware.

    if(Sense == true)
    {
      i = i +5;
      if(i >= 255)
      {
        Sense = false;
      }
    }
    else
    {
      i = i - 5;
      if(i <= 0)
      {
        Sense = true;
      }
    }
  //piloteIOT1_metA(INTERFACET1_VALEUR_POUR_ALLUMER);
}

void interfaceT1_eteint(void)
{
  piloteIOT1_metA(INTERFACET1_VALEUR_POUR_ETEINDRE);
}

void interfaceT1_initialise(void)
{
  piloteIOT1_metA(INTERFACET1_VALEUR_POUR_ETEINDRE);
}
