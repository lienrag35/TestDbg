#ifndef __SCREEN_CONFIG_H__
#define __SCREEN_CONFIG_H__
#include <Arduino.h>
#include <GenericForm.h>   // for constant

// constant for IO
#define LEDWIFIOK 5 // green
#define LEDWIFICMD 3  // yellow
#define LEDWIFIAPP 2 // blue
#define BTN1 26
#define BTN2 27
#define BTN3 28
#define BTN4 29
static const byte BTN_PIN[] = {BTN1,BTN2,BTN3,BTN4};




// contains structure that represents a screen

struct ScreenConfig
{
    byte screenNb;
    char screenTitle[GenericForm::FORM_MAX_TITLE];
    char screenBTNText[GenericForm::FORM_MAX_NB_BUTTON][GenericForm::FORM_MAX_TEXT_BUTTON+1];
    byte screenBTNValue[GenericForm::FORM_MAX_NB_BUTTON];   // Value used in order to known next screen, if stay in the same screen set to 255 (screen internal action)
};


// Global variable for config

const ScreenConfig gScreenConfig[] = {{0,"Welcome",{"Wifi","Bleu","Jaune","Vert"},{1,2,3,4}},
                                      {1,"Welcome WIFI",{"Liste","Connect.","Discon.","Retour"},{10,11,12,0}},
                                      {2,"Gerer BLEU",{"Allumer","Eteindre","Clign.","Retour"},{21,22,23,0}},
                                      {3,"Gerer JAUNE",{"Allumer","Eteindre","Clign.","Retour"},{31,32,33,0}},
                                      {4,"Gerer VERT",{"Allumer","Eteindre","Clign.","Retour"},{41,42,43,0}}
                                     };



#endif // __SCREEN_CONFIG_H__