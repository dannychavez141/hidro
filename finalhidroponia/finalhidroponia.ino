#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>
#include <EtherCard.h>
static byte mymac[] = {0xDD, 0xDD, 0xDD, 0x00, 0x01, 0x05};
static byte myip[] = {192, 168, 1, 177};
static byte mask[] = { 255, 255, 255, 0 };
static byte gwip[] = { 192, 168, 1, 1 };
static byte dnsip[] = { 200, 48, 225, 136 };
byte Ethernet::buffer[1000];
char* esllave1 = "OFF";
char* esllave2 = "OFF";
char* esllave3 = "OFF";
int rep=0;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
String server = "192.168.1.35";
//String server = "pagina.com";
//variables para enviar al servidor
String cadena = "";
const int llave1 = 38;
const int llave2 = 39;
const int llave3 = 40;
const int bomba = 41;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int led4 = 6;
#include "DHT.h"
#define DHTPIN 30
#define DHTTYPE DHT11
#include <Keypad.h>
DHT dht(DHTPIN, DHTTYPE);
RTC_DS1307 RTC;
float contador = 0;
int tiempo = 0;
int hum1 = 0;
int tem1 = 0;
char temp2 = "";
char c = "";
int horau = 0;
int minuu = 0;
int seguu = 0;
int c1 = 0;
int c2 = 0;
int c3 = 0;
int hora = 0;
int minu = 0;
int segu = 0;
String temp = "";
const byte rowsCount = 4;
const byte columsCount = 4;
char key = "";
char keys[rowsCount][columsCount] = {
  { '1', '4', '7', '*' },
  { '2', '5', '8', '0' },
  { '3', '6', '9', '#' },
  { 'A', 'B', 'C', 'D' }
};
char dato = 'A';
const byte rowPins[rowsCount] = { 46, 47, 48, 49 };
const byte columnPins[columsCount] = { 42, 43, 44, 45 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
int h1 = 0, h2 = 0, m1 = 0, m2 = 0;
int cambio = 1;
char modo = 'A';
char estado = 'a';
void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  RTC.begin();
  //RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
 // actualizarbd(0, 6);
  //actualizarbd(1, 0);
  //actualizarbd(2, 18);
  //actualizarbd(3, 0);
  //actualizarbd(4, 30);
  h1 = leerbd(0);
  m1 = leerbd(1);
  h2 = leerbd(2);
  m2 = leerbd(3);
  tiempo = leerbd(4);
  pinMode(bomba, OUTPUT);
  pinMode(llave1, OUTPUT);
  pinMode(llave2, OUTPUT);
  pinMode(llave3, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(llave1, HIGH);
  digitalWrite(llave2, HIGH);
  digitalWrite(llave3, HIGH);
  digitalWrite(bomba, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  Serial2.begin(9600);
  Serial.println("Test del Modulo  ENC28J60");

  if (!ether.begin(sizeof Ethernet::buffer, mymac, 53))
    Serial.println( "No se ha podido acceder a la controlador Ethernet");
  else
    Serial.println("Controlador Ethernet inicializado");

  if (!ether.staticSetup(myip, gwip, dnsip, mask))
    Serial.println("No se pudo establecer la dirección IP");

  Serial.println();

  ether.printIp("IP:  ", ether.myip);
  ether.printIp("GW:  ", ether.gwip);
  ether.printIp("DNS: ", ether.dnsip);
  //iniciar();
}

static word homePage() {
  BufferFiller bfill = ether.tcpOffset();
  bfill.emit_p(PSTR("<!DOCTYPE html>"
                    "<html><head><title>HIDROPONIA UNU</title></head>"
                    "<body>"
                    "<div style='text-align:center;'>"
                    "<h1>SISTEMA DE RIEGO HIDROPONIA UNU</h1>"
                    "<br /><br />Estado esllave1: $S<br />"
                    "<a href=\"/?esllave1=ON\"><input type=\"button\" value=\"ON\"></a>"
                    "<a href=\"/?esllave1=OFF\"><input type=\"button\" value=\"OFF\"></a>"
                    "<br /><br />Estado esllave2: $S<br />"
                    "<a href=\"/?esllave2=ON\"><input type=\"button\" value=\"ON\"></a>"
                    "<a href=\"/?esllave2=OFF\"><input type=\"button\" value=\"OFF\"></a>"
                    "<br /><br />Estado esllave3: $S<br />"
                    "<a href=\"/?esllave3=ON\"><input type=\"button\" value=\"ON\"></a>"
                    "<a href=\"/?esllave3=OFF\"><input type=\"button\" value=\"OFF\"></a>"
                    "<br /><br />"
                    "<a href='http://192.168.1.35/hidro/' target='_blank'>Sistema hidroponia</a>"
                    "</body></html>"
                   ), esllave1, esllave2, esllave3);

  return bfill.position();
}
void loop() {
  menu();
  pagina();
}
void pagina() {
  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);

  if (pos) {

    if (strstr((char *)Ethernet::buffer + pos, "GET /?esllave1=ON") != 0) {
      Serial.println("Comando ON recivido");
      abrirllave1();
     
    }

    if (strstr((char *)Ethernet::buffer + pos, "GET /?esllave1=OFF") != 0) {
      Serial.println("Comando OFF recivido");
      cerrarllaves();


    }
    if (strstr((char *)Ethernet::buffer + pos, "GET /?esllave2=ON") != 0) {
      Serial.println("Comando ON recivido");
      abrirllave2();
     

    }

    if (strstr((char *)Ethernet::buffer + pos, "GET /?esllave2=OFF") != 0) {
      Serial.println("Comando OFF recivido");
      cerrarllaves();


    }
    if (strstr((char *)Ethernet::buffer + pos, "GET /?esllave3=ON") != 0) {
      Serial.println("Comando ON recivido");
      abrirllave3();
     

    }

    if (strstr((char *)Ethernet::buffer + pos, "GET /?esllave3=OFF") != 0) {
      Serial.println("Comando OFF recivido");
      cerrarllaves();
    }
    ether.httpServerReply(homePage()); // se envia página Web
  }
}
void eleccion(char dato) {
  if (dato == 'A' || dato == 'B' || dato == 'C' || dato == 'D'  ) {
    temp = "0";
    modo = dato;

  } else if ( dato == '#')
  { cambio = 1;
    temp = "0";
  } else if ( dato == '*')
  { cambio = 2;
    temp = "0";
  }
  else {
    temp = temp + dato;
  }

}

void menu()
{ switch (modo) {
    case 'A':
      modo1();
      break;
    case 'B':
      modo2();
      break;
    case 'C':
      modo3();
      break;
    case 'D':
      modo4();
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
    if (c1 > 100) {
      cerrarllaves();
     
    }
  }

  if (dato == '1') {
    cerrarllaves();
    delay(1000);
    abrirllave1();
    
    dato = "";
  }
  if (dato == '2') {
    cerrarllaves();
    delay(1000);
    abrirllave2();
   
    
    dato = "";
  }
  if (dato == '3') {
    cerrarllaves();

    delay(1000);
    abrirllave3();
    
    dato = "";
  }
  if (dato == '4') {
    cerrarllaves();
   
  }
  if (modo != 'A') {
    temp = "0";
    h1 = leerbd(0);
    m1 = leerbd(1);
    h2 = leerbd(2);
    m2 = leerbd(3);
    tiempo = leerbd(4);

  }
  return;
}
void modo2() {
  teclado();
  if (modo != 'B') {
    temp = "0";
    actualizarbd(0, h1);
    actualizarbd(1, m1);
    h1 = leerbd(0);
    m1 = leerbd(1);
    h2 = leerbd(2);
    m2 = leerbd(3);
    tiempo = leerbd(4);

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
  if (modo == 'B') {
    if (cambio == 1)
    { lcd.print("C.Hora");
      if (temp == "0") {
        temp = h1;
      }
      Serial.println(temp);
      h1 = temp.toInt();
      if (h1 > 23) {
        h1 = 0;
        Serial.println("entre aca");
        temp = '0';
      }


    } else {
      lcd.print("C.Minu");
      if (temp == "0") {
        temp = m1;
      }
      Serial.println(temp);
      m1 = temp.toInt();
      if (m1 > 59) {
        m1 = 0;
        Serial.println("entre aca");
        temp = "0";
      }

    }
  }
  delay(200);
  return;

}
void modo3() {

  teclado();

  if (modo != 'C') {
    temp = "0";
    actualizarbd(2, h2);
    actualizarbd(3, m2);
    h1 = leerbd(0);
    m1 = leerbd(1);
    h2 = leerbd(2);
    m2 = leerbd(3);
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
  if (modo == 'C') {
    if (cambio == 1)
    { lcd.print("C.Hora");

      if (temp == "0") {
        temp = h2;
      }
      Serial.println(temp);
      h2 = temp.toInt();
      if (h2 > 23) {
        h2 = 0;
        Serial.println("entre aca");
        temp = "0";
      }
    } else {
      lcd.print("C.Minu");
      if (temp == "0") {
        temp = m2;
      }
      Serial.println(temp);
      m2 = temp.toInt();
      if (m2 > 59) {
        m2 = 0;
        Serial.println("entre aca");
        temp = "0";
      }
    }
  }

  delay(200);
  return;
}
void modo4() {
  teclado();
  if (modo != 'D') {
    temp = "0";
    Serial.print("entre aca:");
    Serial.println(temp);
    actualizarbd(4, tiempo);
    h1 = leerbd(0);
    m1 = leerbd(1);
    h2 = leerbd(2);
    m2 = leerbd(3);
    tiempo = leerbd(4);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ENTRE TIEMPO");
  lcd.setCursor(0, 1);
  lcd.print(tiempo);

  lcd.print(" Minu");
  if (modo == 'D') {
    if (temp == "0") {
      temp = tiempo;
    }
    Serial.println(temp);
    tiempo = temp.toInt();
    if (tiempo > 180) {
      tiempo = 0;
      Serial.println("entre aca");
      temp = "0";
    }
  }
  delay(200);


  return;
}

void iniciar() {
  Serial2.setTimeout(2000);

  //Verificamos si el ESP8266 responde
  Serial2.println("AT");
  if (Serial2.find("OK"))
    Serial.println("Respuesta AT correcto");
  else
    Serial.println("Error en ESP8266");

  //-----Configuración de red-------//Podemos comentar si el ESP ya está configurado

  //ESP8266 en modo estación (nos conectaremos a una red existente)
  Serial2.println("AT+CWMODE=1");
  if (Serial2.find("OK"))
    Serial.println("ESP8266 en modo Estacion");

  //Nos conectamos a una red wifi
  Serial2.println("AT+CWJAP=\"Fdavila\",\"acm1ptbt\"");
  Serial.println("Conectandose a la red ...");
  Serial2.setTimeout(10000); //Aumentar si demora la conexion
  if (Serial2.find("OK"))
    Serial.println("WIFI conectado");
  else
    Serial.println("Error al conectarse en la red");
  Serial2.setTimeout(2000);
  //Desabilitamos las conexiones multiples
  Serial2.println("AT+CIPMUX=0");
  if (Serial2.find("OK"))
    Serial.println("Multiconexiones deshabilitadas");


  delay(1000);
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
  if (segu == 0) {
    if(rep==0){
    contador = contador + 1;
    rep=1;}
  }
   if (segu != 0) {
    rep=0;
  }
  
  if (hora > h1 && hora < h2) {
    int evalua = tiempo - contador;
    if (evalua < -1) {
      contador = 0;
    }
    if (estado == 'a') {

      if (evalua == 0 && segu == 0) {
        cerrarllaves();
        delay(1000);
        abrirllave1();
        c1 = -50;
        estado = 'b';
      }
    }
    if (estado == 'b') {
      if (evalua == 0 && segu == 10) {
        cerrarllaves();
        delay(1000);

        abrirllave2();
        delay(1000);

        c1 = -50;
        estado = 'c';
      }
    }
    if (estado == 'c') {
      if (evalua == 0 && segu == 21) {
        delay(1000);
        cerrarllaves();


        delay(1000);
        abrirllave3();
        c1 = -50;
        estado = 'd';
      }
    }
    if (estado == 'd') {
      if (evalua == -0 && segu == 32) {
        delay(1000);
        horau = hora;
        minuu = minu;
        seguu = segu;
        cerrarllaves();
       
        estado = 'a';
        contador = 0;
      }

    }
  }

}
void abrirllave1() {
  envio(1, 0, 0);
  digitalWrite(llave1, LOW);
  digitalWrite(llave2, HIGH);
  digitalWrite(llave3, HIGH);
  digitalWrite(bomba, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  esllave1 = "ON";
  esllave2 = "OFF";
  esllave3 = "OFF";
  horau = hora;
    minuu = minu;
    seguu = segu;
  c1 = 1;
};
void abrirllave2() {
  envio(0, 1, 0);
  digitalWrite(llave1, HIGH);
  digitalWrite(llave2, LOW);
  digitalWrite(llave3, HIGH);
  digitalWrite(bomba, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  horau = hora;
    minuu = minu;
    seguu = segu;
  esllave1 = "OFF";
  esllave2 = "ON";
  esllave3 = "OFF";
  c1 = 1;
};
void abrirllave3() {
  envio(0, 0, 1);
  digitalWrite(llave1, HIGH);
  digitalWrite(llave2, HIGH);
  digitalWrite(llave3, LOW);
  digitalWrite(bomba, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  esllave1 = "OFF";
  esllave2 = "OFF";
  esllave3 = "ON";
  horau = hora;
    minuu = minu;
    seguu = segu;
  c1 = 1;

};
void cerrarllaves() {
  digitalWrite(llave1, HIGH);
  digitalWrite(llave2, HIGH);
  digitalWrite(llave3, HIGH);
  digitalWrite(bomba, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  esllave1 = "OFF";
  esllave2 = "OFF";
  esllave3 = "OFF";
  c1 = 0;
};
void envio(int v1, int v2, int v3) {
  //Nos conectamos con el servidor:

  Serial2.println("AT+CIPSTART=\"TCP\",\"" + server + "\",80");
  if ( Serial2.find("OK"))
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
    peticionHTTP = peticionHTTP + "Host: " + server + "\r\n";
    peticionHTTP = peticionHTTP + "Connetion: close\r\n\r\n";

    //Enviamos el tamaño en caracteres de la peticion http:
    Serial2.print("AT+CIPSEND=");
    Serial2.println(peticionHTTP.length());

    //esperamos a ">" para enviar la petcion  http
    if (Serial2.find(">")) // ">" indica que podemos enviar la peticion http
    {
      Serial.println("Enviando HTTP . . .");
      Serial2.println(peticionHTTP);
      if ( Serial2.find("SEND OK"))
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
          while (Serial2.available() > 0)
          {
            c = Serial2.read();
            if (c == '#') {
              temp2 = c;

            }
            if (temp2 == '#') {
              Serial.write(c);
              cadena.concat(c);  //guardamos la respuesta en el string "cadena"
            }

          }
          //finalizamos si la respuesta es mayor a 500 caracteres
          if (cadena.length() > 100) //Pueden aumentar si tenen suficiente espacio en la memoria
          {
            Serial.println("La respuesta a excedido el tamaño maximo");

            Serial2.println("AT+CIPCLOSE");
            if ( Serial2.find("OK"))
              Serial.println("Conexion finalizada");
            fin_respuesta = true;
          }
          if ((millis() - tiempo_inicio) > 1000) //Finalizamos si ya han transcurrido 10 seg
          { Serial.println();
            Serial.println("Tiempo de espera agotado");
            Serial2.println("AT+CIPCLOSE");
            if ( Serial2.find("OK"))
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

void teclado() {
  key = keypad.getKey();

  if (key) {
    Serial.println(key);
    dato = key;
    eleccion(dato);
  }
}
void actualizarbd(int id, int valor) {
  EEPROM.write(id, valor);

}
int leerbd(int id) {
  int val = (int)EEPROM.read(id);
  return val;
}
