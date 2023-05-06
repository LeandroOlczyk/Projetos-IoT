
#include "DigiKeyboard.h"
void setup() {
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("cmd"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print(F("start notepad"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  
  DigiKeyboard.sendKeyStroke(KEY_N, MOD_CONTROL_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  DigiKeyboard.println(F("Ola meu jovem..."));
  
  DigiKeyboard.println();
  DigiKeyboard.delay(1000);
  DigiKeyboard.println(F("O dispositivo que voce conectou esta manipulando seu teclado..."));
  DigiKeyboard.delay(3000);
  DigiKeyboard.println(F("Voce nao deveria plugar dispositivos desconhecidos em seu computador!"));
  
  DigiKeyboard.println();
  DigiKeyboard.delay(5000);
  DigiKeyboard.println(F("Recomendo que siga a LGPD para que nao arrume problemas!."));
  DigiKeyboard.delay(2000);
  

  DigiKeyboard.println();
  DigiKeyboard.println(F("Para que se lembre deste aviso, irei salvar ele pra voce!"));
  DigiKeyboard.delay(6000);

  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);

 DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(2000);
  DigiKeyboard.print(F("Aviso-Hacker"));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1500);
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){ /*empty*/ }
}