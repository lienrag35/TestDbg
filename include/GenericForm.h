#ifndef __GENERIC_FORM_H__
#define __GENERIC_FORM_H__
#include <Arduino.h>
#include <U8g2lib.h>   // screen lib
extern U8G2_SH1106_128X64_NONAME_1_HW_I2C gU8g2; // to test with debugger if better
// to move later
// int freeRam ();

// represents all form based on u8g2 list
class GenericForm {
    public:
      // constant
    static const byte FORM_MAX_TEXT_BUTTON = 10;
    static const byte FORM_MAX_NB_BUTTON = 4;
    
    static const byte FORM_MAX_TITLE = 24; // 25

    // method
   
    GenericForm();
    GenericForm(const char *aTitle,byte aBtn1,byte aBtn2,byte aBtn3,byte aBtn4);
    GenericForm(const char *aTitle,byte aNbBtns,const byte aBtnPins[], const char  aBtnText[][FORM_MAX_TEXT_BUTTON+1]);
    virtual ~GenericForm();
    void initForm(); // init screen + specific to this form
    
    void display(); // Send data to the speicif screen.
    byte  loopGF();  // do all internal form actions and exit if one action request it (return the specific code)


    // accessors and mutator
    void setTitle(const char *aTitle);
    void setNbBtn(byte aNbBtns) {mNbBtns = aNbBtns <= FORM_MAX_NB_BUTTON ? aNbBtns : FORM_MAX_NB_BUTTON; }; 
    void setBtnText(byte aNbBtns, const char aBtnsText[][FORM_MAX_TEXT_BUTTON+1]);
    void setBtnPins(byte aNbBtns, const byte aBtnsPin[]);
    const char * getBtn1Text() {return mBtn1Text;}
    const char * getBtn2Text() {return mBtn2Text;}



 
    protected :
    /*
    virtual void draw(); // specific draw function (call by display that made the loop display)
    virtual void drawBtn(); // default display of button (call by draw)
    */
    virtual void drawTitle(); // default display of title (call by draw)
    
    
   
    virtual byte doBtn1Action(); // return code related to define action
    virtual byte doBtn2Action(); // return code related to define action
    virtual byte doBtn3Action(); // return code related to define action
    virtual byte doBtn4Action(); // return code related to define action
      
    // return position in X for text that depends on the the font
    //int getCenterPos(const char * aText);

    
    char mTitle[FORM_MAX_TITLE+1]; // form Title
    byte mNbBtns;
    char *mBtn1Text; // text for button 1 null if no text 
    char *mBtn2Text;
    char *mBtn3Text;
    char *mBtn4Text;
    

    private:
    byte mBtn1; // list of button from left to right (pin);
    byte mBtn2;
    byte mBtn3;
    byte mBtn4;



};




#endif // __GENERIC_FORM_H__