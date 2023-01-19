
#include <SoftwareSerial.h>
SoftwareSerial BT1(10, 11); // RX | TX (Conectar el RX del BT en el 11, conectar TX del BT en el 10)
char estado;
int rele = 5;

void setup()
  { 
    Serial.begin(9600);       // En el monitor serial, poner 9600 baudios
    Serial.println("Listo");
    BT1.begin(9600); 
    pinMode(rele, OUTPUT);
  }
 
void loop()
  {  
    estado = BT1.read();
    if (estado == '1'){
      Serial.println("Movimiento detectado");
      digitalWrite(rele, HIGH);
    } else if (estado == '2'){
      digitalWrite(rele, LOW);
    }
  }
