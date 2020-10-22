#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 30
#define DHTTYPE DHT11
#include <Keypad.h>
String esllave1 = "OFF";
String esllave2 = "OFF";
String esllave3 = "OFF";
int rep=0;
LiquidCrystal_I2C lcd(0x27, 20, 4);
const int llave1 = 38;
const int llave2 = 39;
const int llave3 = 40;
const int bomba = 41;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int led4 = 6;
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

  //actualizarbd(0, 6);
  //actualizarbd(1, 0);
  //actualizarbd(2, 18);
 // actualizarbd(3, 0);
 // actualizarbd(4, 30);

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

}

void loop() {
  menu();
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
    if (evalua < 0) {
      contador = 0;
    }
    if (estado == 'a') {

      if (evalua == 0 && segu == 0) {
        cerrarllaves();
        delay(1000);
        abrirllave1();
        c1 = 1;
        estado = 'b';
      }
    }
    if (estado == 'b') {
      if (evalua == 0 && segu == 10) {
        cerrarllaves();
        delay(1000);

        abrirllave2();
        delay(1000);

        c1 = 1;
        estado = 'c';
      }
    }
    if (estado == 'c') {
      if (evalua == 0 && segu == 21) {
        delay(1000);
        cerrarllaves();


        delay(1000);
        abrirllave3();
        c1 = 1;
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
