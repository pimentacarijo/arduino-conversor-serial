//Retransmissor Serial
//O Arduino vai estabelecer a comunicação serial entre o computador e o módulo GSM
//Nesse caso, o computador é conectato ao Hardware UART (serial)
//E o módulo GSM é conectato ao Software UART (serial)
 
#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(2, 3);
 
void setup()
// Recomendo que utilize o mesmo baud rate para as duas portas seriais
{ 
  mySerial.begin(9600);               // baud rate - velocidade da serial do módulo GSM
  Serial.begin(9600);                 // baud rate - velocidade da serial do Arduino-Computador
  delay(1000);                        // espera 1 segundo para garantir que o chip da serial tenha tempo de inicializar
}
 
void loop()
{
  if (mySerial.available())           // Tem algo na serial do módulo GSM?
    Serial.write(mySerial.read());    // Se tem, então envia para a serial do Arduino-Computador
  if (Serial.available())             // Tem algo na serial do Arduino-Computador?
    mySerial.write(Serial.read());    // Se tem, então envia para a serial do módulo GSM
}
