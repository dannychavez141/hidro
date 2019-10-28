#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <SoftwareSerial.h>
SoftwareSerial SerialESP8266(2, 3); // RX, TX
//String server = "192.168.1.35";
String server = "pagina.com";
//variables para enviar al servidor
String cadena = "";
const int llave1 = A0;
const int llave2 = A1;
const int llave3 = A2;
const int bomba = A3;
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
#include <Keypad.h>
DHT dht(DHTPIN, DHTTYPE);
RTC_DS1307 RTC;
float contador = 0;
int tiempo = 0;
int hum1 = 0;
int tem1 = 0;
int horau = 0;
int minuu = 0;
int seguu = 0;
int c1 = 0;
int c2 = 0;
int c3 = 0;
int hora = 0;
int minu = 0;
int segu = 0;
const byte rowsCount = 4;
const byte columsCount = 4;
char key = "";
char keys[rowsCount][columsCount] = {
  { '1', '4', '7', '*' },
  { '2', '5', '8', '0' },
  { '3', '6', '9', '#' },
  { 'A', 'B', 'C', 'D' }
};
char dato = "";
const byte rowPins[rowsCount] = { 9, 10, 11, 12 };
const byte columnPins[columsCount] = { 5, 6, 7, 8 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
int h1 = 0, h2 = 0, m1 = 0, m2 = 0;
int cambio = 1;
int modo = 1;
char estado = 'a';
void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  //actualizarbd(0,6);
  // actualizarbd(1,0);
  // actualizarbd(2,18);
  //actualizarbd(3,0);
  // actualizarbd(4,30);
  h1 = leerbd(0);
  m1 = leerbd(1);
  h2 = leerbd(2);
  m2 = leerbd(3);
  tiempo = leerbd(4);
  pinMode(bomba, OUTPUT);
  pinMode(llave1, OUTPUT);
  pinMode(llave2, OUTPUT);
  pinMode(llave3, OUTPUT);
  digitalWrite(llave1, LOW);
  digitalWrite(llave2, LOW);
  digitalWrite(llave3, LOW);
  digitalWrite(bomba, HIGH);
  Serial.println("Conectando con el servidor ...");
  SerialESP8266.begin(9600);
iniciar();
}

void loop() {
  menu();

}

void menu()
{ switch (modo) {
    case 1:
      modo1();
      break;
    case 2:
      modo2();
      break;
    case 3:
      modo3();
      break;
    case 4:
      modo4();
      break;
    case 5:
      modo5();
      break;
    default:
      // statements
      break;
  }
}
void modo1() {
  teclado();
  valores();
  if (c1 != 0) {
    c1 = c1 + 1;
    if (c1 > 20) {
      digitalWrite(llave1, LOW);
      digitalWrite(llave2, LOW);
      digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
    
      envio(0, 0, 0);
      c1 = 0;
    }
  }

  if (dato == 1) {
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
    digitalWrite(bomba, HIGH);
  
    envio(1, 0, 0);
    delay(1000);
    digitalWrite(llave1, HIGH);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
    digitalWrite(bomba, LOW);
    c1 = 1;
    horau = hora;
    minuu = minu;
    seguu = segu;
  }
  if (dato == 1) {
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
    digitalWrite(bomba, HIGH);
   
    envio(0, 1, 0);
    delay(1000);
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, HIGH);
    digitalWrite(llave3, LOW);
    digitalWrite(bomba, LOW);
    c1 = 1;
    horau = hora;
    minuu = minu;
    seguu = segu;
  }
  if (dato == 1) {
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
    digitalWrite(bomba, HIGH);
    envio(0, 0, 1);
    delay(1000);
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, HIGH);
    digitalWrite(bomba, LOW);
    c1 = 1;
    horau = hora;
    minuu = minu;
    seguu = segu;
  }
  if (dato == 1) {
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
    digitalWrite(bomba, HIGH);

    envio(0, 0, 0);
    c1 = 0;
  }
  if (dato == 1) {
    modo = 2;
    h1 = leerbd(0);
    m1 = leerbd(1);
  }
  return;
}
void modo2() {
 
teclado();
  if (dato == 1) {}
  if (dato == 1) {
    if (cambio == 1) {
      cambio = 2;
    } else {
      cambio = 1;
    }
  }
  if (dato == 1) {
    if (cambio == 1) {
      cambio = 2;
    } else {
      cambio = 1;
    }
  }
  if (dato == 1) {
    modo = 1;
    actualizarbd(0, h1);
    actualizarbd(1, m1);
    h2 = leerbd(2);
    m2 = leerbd(3);
  }
  if (dato == 1) {
    actualizarbd(0, h1);
    actualizarbd(1, m1);
    modo = 3;


  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("C.H.INICIO:");
  lcd.print(" MD:");
  lcd.print(modo);
  lcd.setCursor(0, 1);
  lcd.print(h1);
  lcd.print(":");
  lcd.print(m1);
  lcd.print("/");
  if (cambio == 1)
  { lcd.print("C.Hora");
    if (dato == 1) {
      if (h1 < 23) {
        h1 = h1 + 1;
      } else {
        h1 = 0;
      }
    }
    if (dato == 1) {
      if (h1 >= 1) {
        h1 = h1 - 1;
      } else {
        h1 = 23;
      }
    }
  } else {
    lcd.print("C.Minu");
    if (dato == 1) {
      if (m1 < 59) {
        m1 = m1 + 1;
      } else {
        m1 = 0;
      }
    }

    if (dato == 1) {
      if (m1 >= 1) {
        m1 = m1 - 1;
      } else {
        m1 = 59;
      }
    }
  }

  return;
}
void modo3() {
 
teclado();

  if (dato == 1) {}
  if (dato == 1) {
    if (cambio == 1) {
      cambio = 2;
    } else {
      cambio = 1;
    }
  }
  if (dato == 1) {
    if (cambio == 1) {
      cambio = 2;
    } else {
      cambio = 1;
    }
  }
  if (dato == 1) {
    modo = 2;
    actualizarbd(2, h2);
    actualizarbd(3, m2);
  }
  if (dato == 1) {
    modo = 4;
    actualizarbd(2, h2);
    actualizarbd(3, m2);
    tiempo = leerbd(4);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("C.H.FINAL:");
  lcd.print(" MD:");
  lcd.print(modo);
  lcd.setCursor(0, 1);
  lcd.print(h2);
  lcd.print(":");
  lcd.print(m2);
  lcd.print(" / ");
  if (cambio == 1)
  { lcd.print("C.Hora");
    if (dato == 1) {
      if (h2 < 23) {
        h2 = h2 + 1;
      } else {
        h2 = 0;
      }
    }
    if (dato == 1) {
      if (h2 >= 1) {
        h2 = h2 - 1;
      } else {
        h2 = 23;
      }
    }
  } else {
    lcd.print("C.Minu");
    if (dato == 1) {
      if (m2 < 59) {
        m2 = m2 + 1;
      } else {
        m2 = 0;
      }
    }
    if (dato == 1) {
      if (m2 >= 1) {
        m2 = m2 - 1;
      } else {
        m2 = 59;
      }
    }
  }

  return;
}
void modo4() {
  teclado();
  if (dato == 1) {}
  if (dato == 1) {
    modo = 3;
    actualizarbd(4, tiempo);
  }
  if (dato == 1) {
    modo = 5;
    actualizarbd(4, tiempo);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ENTRE TIEMPO");
  lcd.setCursor(0, 1);
  lcd.print("DE RIEGO:");
  lcd.setCursor(0, 2);
  lcd.print(tiempo);
  lcd.print(" ");
  lcd.print("Minutos");
  if (dato == 1) {
    if (tiempo < 179) {
      tiempo = tiempo + 1;
    } else {
      tiempo = 0;
    }
  }
  if (dato == 1) {
    if (tiempo >= 1) {
      tiempo = tiempo - 1;
    } else {
      tiempo = 179;
    }
  }



  return;
}
void modo5() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("H.INICIO:");
  lcd.print(h1);
  lcd.print(":");
  lcd.print(m1);
  lcd.print(":");
  lcd.print("0");
  lcd.setCursor(0, 1);
  lcd.print("H.FINAL:");
  lcd.print(h2);
  lcd.print(":");
  lcd.print(m2);
  lcd.print(":");
  lcd.print("0");
  lcd.setCursor(0, 2);
  lcd.print("Entre tiempo:");
  lcd.print(tiempo);
  lcd.print("Min");
  lcd.setCursor(0, 3);
  lcd.print("Prox riego en:");
  lcd.print(tiempo - contador);
  lcd.print("Min");
  delay(2000);
  modo = 1;

  return;
}


void valores() {
  hum1 = dht.readHumidity();
  tem1 = dht.readTemperature();
  DateTime now = RTC.now();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("|Hum:");
  lcd.print(hum1);
  lcd.print("%|");
  lcd.print("Tem:");
  lcd.print(tem1);
  lcd.print("C|");
  lcd.setCursor(0, 1);
  lcd.print(now.day(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.year() - 2000);
  lcd.print("|");
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  lcd.print(now.second(), DEC);
  lcd.setCursor(0, 2);
  lcd.print("PROx RIEGO:");
  lcd.print(tiempo - contador);
  lcd.print("Min");
  lcd.setCursor(0, 3);
  lcd.print("Ult riego:");
  lcd.print(horau);
  lcd.print(":");
  lcd.print(minuu);
  lcd.print(":");
  lcd.print(seguu);

  hora = (now.hour());
  minu = (now.minute());
  segu = (now.second());
  Serial.print(hora);
  Serial.print(':');
  Serial.print(minu);
  Serial.print(':');
  Serial.println(segu);
  if (segu == 0) {
    contador = contador + 1;
  }
  if (hora > h1 && hora < h2) {
    int evalua = tiempo - contador;
    if (evalua < -1) {
      contador = 0;
    }
    if (estado == 'a') {

      if (evalua == 0 && segu == 0) {
        digitalWrite(llave1, LOW);
        digitalWrite(llave2, LOW);
        digitalWrite(llave3, LOW);
        digitalWrite(bomba, HIGH);
        envio(1, 0, 0);
        delay(1000);
        digitalWrite(llave1, HIGH);
        digitalWrite(llave2, LOW);
        digitalWrite(llave3, LOW);
        digitalWrite(bomba, LOW);
        c1 = -50;
        estado = 'b';
      }
    }
    if (estado == 'b') {
      if (evalua == 0 && segu == 10) {

        delay(1000);
        digitalWrite(llave1, LOW);
        digitalWrite(llave2, LOW);
        digitalWrite(llave3, LOW);
        digitalWrite(bomba, HIGH);

        envio(0, 1, 0);
        delay(1000);
        digitalWrite(llave1, LOW);
        digitalWrite(llave2, HIGH);
        digitalWrite(llave3, LOW);
        digitalWrite(bomba, LOW);
        c1 = -50;
        estado = 'c';
      }
    }
    if (estado == 'c') {
      if (evalua == 0 && segu == 21) {
        delay(1000);
        digitalWrite(llave1, LOW);
        digitalWrite(llave2, LOW);
        digitalWrite(llave3, LOW);
        digitalWrite(bomba, HIGH);

        envio(0, 0, 1);
        delay(1000);
        digitalWrite(llave1, LOW);
        digitalWrite(llave2, LOW);
        digitalWrite(llave3, HIGH);
        digitalWrite(bomba, LOW);
        c1 = -50;
        estado = 'd';
      }
    }
    if (estado == 'd') {
      if (evalua == -0 && segu == 32) {
        digitalWrite(llave1, LOW);
        digitalWrite(llave2, LOW);
        digitalWrite(llave3, LOW);
        digitalWrite(bomba, HIGH);
        envio(0, 0, 0);
        delay(1000);
        horau = hora;
        minuu = minu;
        seguu = segu;
        c1 = 0;
        estado = 'a';
        contador = 0;
      }

    }
  }

}
void envio(int v1, int v2, int v3) {
  //Nos conectamos con el servidor:

  SerialESP8266.println("AT+CIPSTART=\"TCP\",\"" + server + "\",80");
  if ( SerialESP8266.find("OK"))
  {
    cadena = "";
    Serial.println();
    Serial.println();
    Serial.println("ESP8266 conectado con el servidor...");

    //Armamos el encabezado de la peticion http
    String peticionHTTP = "GET /hidro/subir.php?h=";
    peticionHTTP = peticionHTTP + String(hum1) + "&t=";
    peticionHTTP = peticionHTTP + String(tem1) + "&h1=";
    peticionHTTP = peticionHTTP + String(v1) + "&h2=";
    peticionHTTP = peticionHTTP + String(v2) + "&h3=";
    peticionHTTP = peticionHTTP + String(v3) + " HTTP/1.1\r\n";
    //peticionHTTP=peticionHTTP+" HTTP/1.1\r\n";
    peticionHTTP = peticionHTTP + "Host: " + server + "\r\n";
    peticionHTTP = peticionHTTP + "Connetion: close\r\n\r\n";

    //Enviamos el tamaño en caracteres de la peticion http:
    SerialESP8266.print("AT+CIPSEND=");
    SerialESP8266.println(peticionHTTP.length());

    //esperamos a ">" para enviar la petcion  http
    if (SerialESP8266.find(">")) // ">" indica que podemos enviar la peticion http
    {
      Serial.println("Enviando HTTP . . .");
      SerialESP8266.println(peticionHTTP);
      if ( SerialESP8266.find("SEND OK"))
      {
        Serial.println("Peticion HTTP enviada:");
        Serial.println();
        Serial.println(peticionHTTP);
        Serial.println("Esperando respuesta...");

        boolean fin_respuesta = false;
        long tiempo_inicio = millis();
        cadena = "";

        while (fin_respuesta == false)
        {
          while (SerialESP8266.available() > 0)
          {
            char c = SerialESP8266.read();
              Serial.write(c);
              cadena.concat(c);  //guardamos la respuesta en el string "cadena"
            

          }
          //finalizamos si la respuesta es mayor a 500 caracteres
          if (cadena.length() > 100) //Pueden aumentar si tenen suficiente espacio en la memoria
          {
            Serial.println("La respuesta a excedido el tamaño maximo");

            SerialESP8266.println("AT+CIPCLOSE");
            if ( SerialESP8266.find("OK"))
              Serial.println("Conexion finalizada");
            fin_respuesta = true;
          }
          if ((millis() - tiempo_inicio) > 1000) //Finalizamos si ya han transcurrido 10 seg
          { Serial.println();
            Serial.println("Tiempo de espera agotado");
            SerialESP8266.println("AT+CIPCLOSE");
            if ( SerialESP8266.find("OK"))
              Serial.println("Conexion finalizada");
            fin_respuesta = true;
          }
          if (cadena.indexOf("CLOSED") > 0) //si recibimos un CLOSED significa que ha finalizado la respuesta
          {
            Serial.println();
            Serial.println("Cadena recibida correctamente, conexion finalizada");
            fin_respuesta = true;
          }
        }
      }
      else
      {
        Serial.println("No se ha podido enviar HTTP.....");
        
      }
    }
  }
  else
  {
    Serial.println("No se ha podido conectarse con el servidor");
  }


  //-------------------------------------------------------------------------------

  cadena = "";
  delay(1000); //pausa de 10seg antes de conectarse nuevamente al servidor (opcional)

}
void iniciar() {
  SerialESP8266.setTimeout(2000);

  //Verificamos si el ESP8266 responde
  SerialESP8266.println("AT");
  if (SerialESP8266.find("OK"))
    Serial.println("Respuesta AT correcto");
  else
    Serial.println("Error en ESP8266");

  //-----Configuración de red-------//Podemos comentar si el ESP ya está configurado

  //ESP8266 en modo estación (nos conectaremos a una red existente)
  SerialESP8266.println("AT+CWMODE=1");
  if (SerialESP8266.find("OK"))
    Serial.println("ESP8266 en modo Estacion");

  //Nos conectamos a una red wifi
  SerialESP8266.println("AT+CWJAP=\"Fdavila\",\"acm1ptbt\"");
  Serial.println("Conectandose a la red ...");
  SerialESP8266.setTimeout(10000); //Aumentar si demora la conexion
  if (SerialESP8266.find("OK"))
    Serial.println("WIFI conectado");
  else
    Serial.println("Error al conectarse en la red");
  SerialESP8266.setTimeout(2000);
  //Desabilitamos las conexiones multiples
  SerialESP8266.println("AT+CIPMUX=0");
  if (SerialESP8266.find("OK"))
    Serial.println("Multiconexiones deshabilitadas");


  delay(1000);
}

void teclado() {
  key = keypad.getKey();

  if (key) {
    Serial.println(key);
    dato=key;
  }
}
void actualizarbd(int id, int valor) {
  EEPROM.write(id, valor);

}
int leerbd(int id) {
  int val = (int)EEPROM.read(id);
  return val;
}
