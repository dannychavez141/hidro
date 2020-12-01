#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11
#include <Keypad.h>
int rep = 0;
LiquidCrystal_I2C lcd(0x3F, 20, 4);
const int llave1 = 11;
const int llave2 = 12;
const int llave3 = 13;
const int bomba = 10;
DHT dht(DHTPIN, DHTTYPE);
RTC_DS3231 RTC;
float contador = 0;
int tiempo = 0;
int duracion = 0;
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
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
char dato = 'A';
const byte rowPins[rowsCount] = { 9, 8, 7, 6 };
const byte columnPins[columsCount] = { 5, 4, 3, 2 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
int h1 = 0, h2 = 0, m1 = 0, m2 = 0;
int cambio = 1;
char modo = 'A';
char estado = 'a';
int tmuestra = 1000;
unsigned long tAhoraM = 0;
unsigned long tRiego = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  RTC.begin();
  //RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
  dht.begin();
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
  duracion = leerbd(5);
  pinMode(bomba, OUTPUT);
  pinMode(llave1, OUTPUT);
  pinMode(llave2, OUTPUT);
  pinMode(llave3, OUTPUT);

  digitalWrite(llave1, LOW);
  digitalWrite(llave2, LOW);
  digitalWrite(llave3, LOW);
  digitalWrite(bomba, HIGH);

}

void loop() {
  menu();
}
void eleccion(char dato) {
  if (dato == 'A' || dato == 'B' || dato == 'C' || dato == 'D'  ) {
    temp = "0";
    modo = dato;

  } else if ( dato == '*')
  { cambio = 1;
    temp = "0";
  } else if ( dato == '#')
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
  if (millis() > tAhoraM + tmuestra) {
    tAhoraM = millis();
    valores();
    if (c1 != 0) {
      c1 = c1 + 1;
      if (c1 > duracion) {
        cerrarllaves();
        c1=0;
      }
    }
  }


  if (dato == '1') {
    cerrarllaves();
    delay(1000);
    abrirllave1();
    c1 = 1;
    dato = ' ';
  }
  if (dato == '2') {
    cerrarllaves();
    delay(1000);
    abrirllave2();
    c1 = 1;
    dato = ' ';
  }
  if (dato == '3') {
    cerrarllaves();

    delay(1000);
    abrirllave3();
    c1 = 1;
    dato = ' ';
  }
  if (dato == '4') {
    cerrarllaves();
 dato = ' ';
  }
  if (modo != 'A') {
    temp = "0";
    h1 = leerbd(0);
    m1 = leerbd(1);
    h2 = leerbd(2);
    m2 = leerbd(3);
    tiempo = leerbd(4);
    duracion = leerbd(5);
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
    duracion = leerbd(5);
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
    {
      lcd.setCursor(0, 2);
      lcd.print("Cambiando Hora");
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
      lcd.setCursor(0, 2);
      lcd.print("Cambiando Minutos");
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
    duracion = leerbd(5);
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
    { lcd.setCursor(0, 2);
      lcd.print("Cambiando Hora");

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
      lcd.setCursor(0, 2);
      lcd.print("Cambiando Minutos");
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
    actualizarbd(5, duracion);
    h1 = leerbd(0);
    m1 = leerbd(1);
    h2 = leerbd(2);
    m2 = leerbd(3);
    tiempo = leerbd(4);
    duracion = leerbd(5);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  if (cambio == 1)
  {
    lcd.print("ENTRE TIEMPO:*");
  } else {
    lcd.print("ENTRE TIEMPO:");
  }

  lcd.setCursor(0, 1);
  lcd.print(tiempo);
  lcd.print(" Minu");
  lcd.setCursor(0, 2);
  if (cambio == 1)
  {
    lcd.print("DURACION:");
  } else {
    lcd.print("DURACION:*");
  }
  lcd.setCursor(0, 3);
  lcd.print(duracion);
  lcd.print(" Segu");
  if (modo == 'D') {
    if (cambio == 1)
    {
      if (temp == "0") {
        temp = tiempo;
      }
      Serial.println(temp);
      tiempo = temp.toInt();
      if (tiempo > 240) {
        tiempo = 0;
        Serial.println("entre aca");
        temp = "0";
      }
    } else {
      if (temp == "0") {
        temp = duracion;
      }
      Serial.println(temp);
      duracion = temp.toInt();
      if (duracion > 240) {
        duracion = 0;
        Serial.println("entre aca");
        temp = "0";
      }
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
 if (cambio == 1)
    { lcd.setCursor(0, 0);
  lcd.print("|Hum=");
  lcd.print(hum1);
  lcd.print("%|");
  lcd.print("Tem=");
  lcd.print(tem1);
  lcd.print("*C|");
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
  lcd.print("PROX RIEGO=");
  lcd.print(tiempo - contador);
  lcd.print("Min");
  lcd.setCursor(0, 3);
  lcd.print("ULT.RIEGO=");
  lcd.print(horau);
  lcd.print(":");
  lcd.print(minuu);
  lcd.print(":");
  lcd.print(seguu);
    }else{
     lcd.setCursor(0, 0);
  lcd.print("H.INICIO=");
  lcd.print(h1);
  lcd.print(":");
  lcd.print(m1);
  lcd.setCursor(0, 1);
  lcd.print("H.FIN=");
  lcd.print(h2);
  lcd.print(":");
  lcd.print(m2);
  lcd.setCursor(0, 2);
  lcd.print("RIEGO ENTRE=");
  lcd.print(tiempo);
  lcd.print("Min");
  lcd.setCursor(0, 3);
  lcd.print("DUR.RIEGO=");
  lcd.print(duracion);
  lcd.print("Seg");
  
      }
  hora = (now.hour());
  minu = (now.minute());
  segu = (now.second());
  if (segu == 0) {
    if (rep == 0) {
      contador = contador + 1;
      rep = 1;
    }
  }
  if (segu != 0) {
    rep = 0;
  }
  if (hora >= h1 && hora <= h2) {
    int evalua = tiempo - contador;
    if (evalua <= 0) {
      contador = 0;
      Serial.println("AUTOMATICO");
      Serial.println("LLAVE 1");
      abrirllave1();
      tRiego = millis();
      estado = 'b';
    }
    Serial.print("Estado:");
    Serial.println(estado);
    Serial.print(millis());
    Serial.print("/");
    Serial.println(tRiego + (duracion * 1000));

    if (estado == 'b') {
      if (millis() >= (tRiego + (duracion * 1000))) {
        Serial.println("LLAVE 2");
        cerrarllaves();
        delay(1000);
        abrirllave2();
        tRiego = millis();
        estado = 'c';
      }
    }
    if (estado == 'c') {
      if (millis() >= (tRiego + (duracion * 1000))) {
        Serial.println("LLAVE 3");
        cerrarllaves();
        delay(1000);
        abrirllave3();
        tRiego = millis();
        estado = 'd';
      }
    }
    if (estado == 'd') {
      if (millis() >= (tRiego + (duracion * 1000))) {
        Serial.println("CERRADO");
        cerrarllaves();
        tRiego = millis();
        estado = 'a';
      }
    }
  }


}
void abrirllave1() {
  Serial.println("abierto 1");
  digitalWrite(llave1, HIGH);
  digitalWrite(llave2, LOW);
  digitalWrite(llave3, LOW);
  digitalWrite(bomba, LOW);
  horau = hora;
  minuu = minu;
  seguu = segu;
};
void abrirllave2() {
Serial.println("abierto 2");
  digitalWrite(llave1, LOW);
  digitalWrite(llave2, HIGH);
  digitalWrite(llave3, LOW);
  digitalWrite(bomba, LOW);
  horau = hora;
  minuu = minu;
  seguu = segu;

};
void abrirllave3() {
  Serial.println("abierto 3");
  digitalWrite(llave1, LOW);
  digitalWrite(llave2, LOW);
  digitalWrite(llave3, HIGH);
  digitalWrite(bomba, LOW);
  horau = hora;
  minuu = minu;
  seguu = segu;

};
void cerrarllaves() {
  Serial.println("cerrado");
  digitalWrite(llave1, LOW);
  digitalWrite(llave2, LOW);
  digitalWrite(llave3, LOW);
  digitalWrite(bomba, HIGH);

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
