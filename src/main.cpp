#include <Arduino.h>
#include "avr8-stub.h"
#include <U8g2lib.h>
#include <GenericForm.h>

int i;  

U8G2_SH1106_128X64_NONAME_1_HW_I2C gU8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

GenericForm myGForm;


void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  debug_init();
  gU8g2.begin();
  myGForm.initForm();
 breakpoint();
  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  breakpoint();
  digitalWrite(5, HIGH);
  myGForm.setTitle("test 1");
  myGForm.display();
	delay(200);
  i++;
	digitalWrite(5, LOW);
	delay(500);

}