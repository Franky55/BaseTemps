//#############################################################################
/**
 * @file main.c
 * @author Francis Gratton
 * @brief
 * Program file containing the code defined in xmain.h
 * Please refer to this other file for information necessary in order to make this work.
 * @version 0.0.0
 * @date 2023-05-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
//#############################################################################


//INCLUSIONS
#include "main.h"

// inlcude des pilotes

//#include "piloteEntree1.h"
#include "piloteIOT1.h"

// Include des Services
#include "serviceTaskServer.h"
#include "serviceBaseDeTemps.h"

// Inlude des interfaces
//#include "interfaceEntree1.h"
#include "interfaceT1.h"


// Include des processus
#include "processusClignotant.h"

//Definitions privees
//pas de definitions privees
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        48 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 5 // Time (in milliseconds) to pause between pixels


/// @brief Fonction qui fait l'initialisation de tout les modules permettant
//   au fonctionnement
/// @param void
void main_initialise(void);

//Definitions de variables privees:
//pas de variables privees

//Definitions de fonctions privees:

void main_initialise(void)
{
  serviceTaskServer_initialise();
  serviceBaseDeTemps_initialise();

//  piloteEntree1_initialise();
  piloteIOT1_initialise(); 

  //interfaceEntree1_initialise();
  interfaceT1_initialise();

  processusClignotant_initialise();
}

void setup(void) 
{
  Serial.begin(115200);
  main_initialise();

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  serviceTaskServer_DemarreLesTachesALaTouteFinDeSetup();
}

void loop(void) 
{
  serviceTaskServer_gestion.execute();
  serviceBaseDeTemps_gereDansLoop();   
}

