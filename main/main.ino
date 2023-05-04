//#############################################################################
/**
 * @file main.c
 * @author CamFo Camille Fortin (camfortin2022@gmail.com)
 * @brief
 * Program file containing the code defined in xmain.h
 * Please refer to this other file for information necessary in order to make this work.
 * @version 0.1
 * @date 2022-11-14
 * 
 * @copyright Copyright (c) 2022
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
void main_faitUnTest(void);

//Declarations de fonctions privees:

/// @brief Fonction qui permet de tester certain module en activant 
//      leur requête tout de suite après leur initialisation
/// @param void
void main_faitUnTest(void)
{
  
}
/// @brief Fonction qui fait l'initialisation de tout les modules permettant
//   au fonctionnement global du véhicule.
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
  main_faitUnTest();
  serviceTaskServer_DemarreLesTachesALaTouteFinDeSetup();
}

void loop(void) 
{
  serviceTaskServer_gestion.execute();
  serviceBaseDeTemps_gereDansLoop();   
}

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
//pas de fonctions publiques
