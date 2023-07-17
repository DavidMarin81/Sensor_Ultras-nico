//Librerias para el bluetooth
#include <SoftwareSerial.h>
SoftwareSerial BT1(10, 11); // RX | TX (Conectar el RX del BT en el 11, conectar TX del BT en el 10)

//Se asignan los valores del sensor ultrasónico
int TRIG = 7;
int ECO = 9;
int DURACION;
int DISTANCIA;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);

  Serial.begin(9600);       // En el monitor serial, poner 9600 baudios
  BT1.begin(9600); 
  Serial.println("Listo");  // Se imprime en el Serial
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(250);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH); //Devuelve un valor en microsegundos
  DISTANCIA = DURACION / 58.2;   // 58.2 es el valor por el que se divide para que de la distancia en cms. 
                                 // Lo da las especificaciones
  Serial.println(DISTANCIA);     // Imprime en el Serial la distancia que va recogiendo
  delay(50);                    // Tiempo de espera para imprimir en el serial

  if(DISTANCIA <= 105 && DISTANCIA > 20){  // Si el sensor está fuera de rango, devuelve valores negativos
    Serial.println("Detectando movimiento");
      BT1.write('1');
      delay(5000);
    } else {
      BT1.write('2');
      delay(250);
    }
}
