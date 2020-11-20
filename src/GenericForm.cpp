#include <GenericForm.h>
// intialize it only once
// this not compatible with acr-debugger lib U8G2_SH1106_128X64_NONAME_1_HW_I2C GenericForm::u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

GenericForm::GenericForm():mNbBtns(0),mBtn1Text(nullptr),mBtn2Text(nullptr),mBtn3Text(nullptr),mBtn4Text(nullptr)
{
}
GenericForm::GenericForm(const char *aTitle, byte aBtn1, byte aBtn2, byte aBtn3, byte aBtn4):mNbBtns(4),mBtn1Text(nullptr),mBtn2Text(nullptr),mBtn3Text(nullptr),mBtn4Text(nullptr)
{
    setTitle(aTitle);
    mBtn1 = aBtn1;
    mBtn2 = aBtn2;
    mBtn3 = aBtn3;
    mBtn4 = aBtn4;
}
GenericForm::GenericForm(const char *aTitle,byte aNbBtns,const byte aBtnPins[], const char aBtnText[][FORM_MAX_TEXT_BUTTON+1])
{
    
    setTitle(aTitle);
    setNbBtn(aNbBtns); 
    setBtnPins(mNbBtns,aBtnPins);
    setBtnText(mNbBtns,aBtnText);
    
}
GenericForm::~GenericForm() 
{
    delete [] mBtn1Text;
    delete [] mBtn2Text;
    delete [] mBtn3Text;
    delete [] mBtn4Text;
}



// init screen + specific to this form (call in setup, only once)
void GenericForm::initForm()
{
    // a deplacer a  l'exterieur car ne pas le faire a chaque fois
    
    gU8g2.begin();
    gU8g2.setFont(u8g2_font_5x7_tf);
}

// Send data to the speicif screen but without managing buttons (see loop)

void GenericForm::display()
{
    /*gU8g2.firstPage();
    do
    {
        draw();
    } while (gU8g2.nextPage());
    */
}

// do all internal form actions and exit if one action request it (return the specific code)
// return 0 if nothing to do

byte  GenericForm::loopGF()
{

    byte ret = 0; // Nothing specific  

    while (ret == 0)
    {
        display();
        
        if (digitalRead(mBtn1) == HIGH)
        {
            ret = doBtn1Action();
        }
        else
        {
            // here ok with debugger 
            
            if (digitalRead(mBtn2) == HIGH)
            {
                ret = doBtn2Action();
            }
            else
            {   
                
                if (digitalRead(mBtn3) == HIGH)
                {
                    ret = doBtn3Action();
                }
                else
                {
                    
                    if (digitalRead(mBtn4) == HIGH)
                    {
                        ret = doBtn4Action();
                    }
                    
                }
                
            }
            
        }
        
    }

    return ret;
}



/* *********** ACCESSORS ****************** */

void GenericForm::setTitle(const char *aTitle)
{
    strncpy(mTitle, aTitle, FORM_MAX_TITLE);
    mTitle[strlen(aTitle)] = 0;
}
void GenericForm::setBtnText(byte aNbBtns, const char aBtnsText[][FORM_MAX_TEXT_BUTTON+1])
{
    
        if ((aNbBtns>0) && (aBtnsText[0] != nullptr)) {
            mBtn1Text = new char[strlen(aBtnsText[0])+1];
            strncpy(mBtn1Text,aBtnsText[0],FORM_MAX_TEXT_BUTTON);
            mBtn1Text[strlen(aBtnsText[0])] = 0;
        }
        if ((aNbBtns> 1) && (aBtnsText[1] != nullptr)) {
            mBtn2Text = new char[strlen(aBtnsText[1])+1];
            strncpy(mBtn2Text,aBtnsText[1],FORM_MAX_TEXT_BUTTON);
            mBtn2Text[strlen(aBtnsText[1])] = 0;

        }
        if ((aNbBtns> 2) && (aBtnsText[2] != nullptr)) {
            mBtn3Text = new char[strlen(aBtnsText[2])+1];
            strncpy(mBtn3Text,aBtnsText[2],FORM_MAX_TEXT_BUTTON);
            mBtn3Text[strlen(aBtnsText[2])] = 0;
        }
        if ((aNbBtns> 3) && (aBtnsText[3] != nullptr)) {
            mBtn4Text = new char[strlen(aBtnsText[3])+1];
            strncpy(mBtn4Text,aBtnsText[3],FORM_MAX_TEXT_BUTTON);
            mBtn4Text[strlen(aBtnsText[3])] = 0;
        }
}




void GenericForm::setBtnPins(byte aNbBtns, const byte aBtnsPin[]) 
{
    mBtn1 = aNbBtns > 0 ? aBtnsPin[0] : 0;
    mBtn2 = aNbBtns > 1 ? aBtnsPin[1] : 0;
    mBtn3 = aNbBtns > 2 ? aBtnsPin[2] : 0;
    mBtn4 = aNbBtns > 3 ? aBtnsPin[3] : 0;


}


/* **************** Protected methods *********************** */

// default display of button (call by draw)
//void GenericForm::drawBtn() {
//    int y =0, wBtn;
/*
    if (mNbBtns > 0)
    {
        wBtn = gU8g2.getDisplayWidth() / mNbBtns;
        y = gU8g2.getDisplayHeight() //- gU8g2.getMaxCharHeight();
        if (mBtn1Text != nullptr) {
            gU8g2.drawStr(0, y, mBtn1Text);
            if (mBtn2Text != nullptr)
            {
                gU8g2.drawStr(wBtn, y, mBtn2Text);
                if (mBtn3Text != nullptr)
                {
                    gU8g2.drawStr(wBtn * 2, y, mBtn3Text);
                    if (mBtn4Text != nullptr)
                    {
                        gU8g2.drawStr(wBtn * 3, y, mBtn4Text);
                    }
                }
            }
        }
    }
    */
// } 


// default display of title (call by draw)
void GenericForm::drawTitle() {
  //  gU8g2.drawStr(getCenterPos(mTitle), 8, mTitle);
}




// Specific draw for this form call in the display loop
//void GenericForm::draw()
//{
//    drawTitle();
    //gU8g2.drawStr(getCenterPos("GenericForm"), 20, "GenericForm");
    //gU8g2.drawFrame(2, 10 , 124, 42);
//    drawBtn();
//}

// return   other : to exit from form
//          0 : remains in internal loop

byte GenericForm::doBtn1Action()
{
    return 1;
}

// return 1 : to exit from form
byte GenericForm::doBtn2Action()
{
    return 2;
}

// return 1 : to exit from form
byte GenericForm::doBtn3Action()
{
    return 3;
}

// return 1 : to exit from form
byte GenericForm::doBtn4Action()
{
    return 4;
}

// return postion on x axis for centering <aText>
/*
int GenericForm::getCenterPos(const char * aText) {
    int pos = 0;
    // pos = (gU8g2.getDisplayWidth() - gU8g2.getStrWidth(aText)) / 2 ;
    pos = pos >= 0 ? pos : 0;
    return pos;

}
*/
// tools to move later 
/*
int freeRam ()
{
extern int __heap_start, *__brkval;
int v;
return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
*/