#include <EtherCard.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 4);
static byte mymac[] = {0xDD, 0xDD, 0xDD, 0x00, 0x01, 0x05};
static byte myip[] = {192, 168, 1, 25};
byte Ethernet::buffer[1000];
const int llave1 = 4;
const int llave2 = 5;
const int llave3 = 6;
const int bomba = 7;
const int ledPin = 2;
char* Estadollave1 = "OFF";
char* Estadollave2 = "OFF";
char* Estadollave3 = "OFF";
char modo = '0';
#include "DHT.h"
#define DHTPIN 2
#define hidro1 A0
#define hidro2 A1
#define hidro3 A2
#define DHTTYPE DHT11
DHT dht1(DHTPIN, DHTTYPE);
RTC_DS1307 RTC;
int t;
long hum1 = 0;
long tem1 = 0;
long hu1 = 0;
long hu2 = 0;
long hu3 = 0;
int contador = 0;
void setup() {
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  dht1.begin();
  RTC.begin();
  //RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
  pinMode(hidro1, INPUT);
  pinMode(hidro2, INPUT);
  pinMode(hidro3, INPUT);
  pinMode(bomba, OUTPUT);
  pinMode(llave1, OUTPUT);
  pinMode(llave2, OUTPUT);
  pinMode(llave3, OUTPUT);
  Serial.println("Test del Modulo  ENC28J60");

  if (!ether.begin(sizeof Ethernet::buffer, mymac, 10))
    Serial.println( "No se ha podido acceder a la controlador Ethernet");
  else
    Serial.println("Controlador Ethernet inicializado");

  if (!ether.staticSetup(myip))
    Serial.println("No se pudo establecer la dirección IP");
  digitalWrite(bomba, HIGH);
  Serial.println();
  mostrarhumedad();

}




void loop() {
  pagina();
  mostrarhumedad();
  delay(100);



}
void mostrarhumedad() {
  if (modo == '0') {
    DateTime now = RTC.now();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("|Hsue1|");
    lcd.print("Hsue2|");
    lcd.print("Hsue3|");
    lcd.setCursor(0, 1);
    lcd.print("|");
    lcd.print(hu1);
    lcd.print("%");
    lcd.print("|");
    lcd.print(hu2);
    lcd.print("%");
    lcd.print("|");
    lcd.print(hu3);
    lcd.print("%");
    lcd.print("|");
    contador = contador + 100;
    if (contador >= 2000)
    { modo = '1';
      contador = 0;
    }
  }
  if (modo == '1') {
    DateTime now = RTC.now();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("fecha:");
    lcd.print(now.day(), DEC);
    lcd.print("/");
    lcd.print(now.month(), DEC);
    lcd.print("/");
    lcd.print(now.year() - 2000);
    lcd.setCursor(0, 1);
    lcd.print("hora:");
    lcd.print(now.hour(), DEC);
    lcd.print(":");
    lcd.print(now.minute(), DEC);
    lcd.print(":");
    lcd.print(now.second(), DEC);
    if (contador >= 2000)
    { modo = '2';
      contador = 0;
    }
  }
  if (modo == '2') {
    DateTime now = RTC.now();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("humedad:");
    lcd.print(hum1);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temperatura:");
    lcd.print(tem1);
    lcd.print((char)223);
    lcd.print("C");
    if (contador >= 2000)
    { modo = '0';
      contador = 0;
    }
  }

}
void ambiente() {
  hum1 = dht1.readHumidity();
  tem1 = dht1.readTemperature();
  hu1 = map(analogRead(hidro1), 0, 1023, 100, 0);
  hu2 = map(analogRead(hidro2), 0, 1023, 100, 0);
  hu3  = map(analogRead(hidro3), 0, 1023, 100, 0);




}

static word homePage() {

  BufferFiller bfill = ether.tcpOffset();
  bfill.emit_p(PSTR("<!DOCTYPE html>\n"
                    "<html><head><title>Hidroponia Unu</title>"
                    "<meta http-equiv='refresh' target='_blank' content='5;url=http://192.168.1.46:81/webservice/rreporte.php?hum=$L&&temp=$L&&hsuelo1=$L&&hsuelo2=$L&&hsuelo3=$L'>"
                    "<meta charset='utf-8'></head><body style='background-color:green;'>"
                    "<center>"
                    "<h1>Area de control hidroponia unu 2019</h1>"
                    "Tiempo transcurrido : $L segundos"
                    "<br>Llave 1: $S<a href=\"/?llave1=ON\"><input type=\"button\" value=\"ON\"></a><a href=\"/?llave1=OFF\"><input type=\"button\" value=\"OFF\"></a> <br>"
                    "<br>Llave 2: $S<a href=\"/?llave2=ON\"><input type=\"button\" value=\"ON\"></a><a href=\"/?llave2=OFF\"><input type=\"button\" value=\"OFF\"></a> <br>"
                    "<br>Llave 3: $S<a href=\"/?llave3=ON\"><input type=\"button\" value=\"ON\"></a><a href=\"/?llave3=OFF\"><input type=\"button\" value=\"OFF\"></a> <br><br><br><br>"
                    "<a href='http://192.168.1.46:81/hidroponiamovil/'>volver al sistema de reportes</a><center/>"
                    "</body></html>"
                   ), hum1, tem1, hu1, hu2, hu3, millis() / 1000, Estadollave1, Estadollave2, Estadollave3);

  return bfill.position();
}
void pagina() {
  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);

  if (Estadollave1 == "ON" || Estadollave2 == "ON" || Estadollave3 == "ON") {
    digitalWrite(bomba, LOW);
  } else {
    digitalWrite(bomba, HIGH);
  }

  if (pos) {

    if (strstr((char *)Ethernet::buffer + pos, "GET /?llave1=ON") != 0) {
      Serial.println("Comando ON recivido");
      digitalWrite(llave1, HIGH);
      Estadollave1 = "ON";
    }

    if (strstr((char *)Ethernet::buffer + pos, "GET /?llave1=OFF") != 0) {

      digitalWrite(llave1, LOW);
      Estadollave1 = "OFF";
    }
    if (strstr((char *)Ethernet::buffer + pos, "GET /?llave2=ON") != 0) {

      digitalWrite(llave2, HIGH);
      Estadollave2 = "ON";
    }

    if (strstr((char *)Ethernet::buffer + pos, "GET /?llave2=OFF") != 0) {

      digitalWrite(llave2, LOW);
      Estadollave2 = "OFF";
    }
    if (strstr((char *)Ethernet::buffer + pos, "GET /?llave3=ON") != 0) {

      digitalWrite(llave3, HIGH);
      Estadollave3 = "ON";
    }
    if (strstr((char *)Ethernet::buffer + pos, "GET /?llave3=OFF") != 0) {

      digitalWrite(llave3, LOW);
      Estadollave3 = "OFF";
    }  ambiente();
    ether.httpServerReply(homePage()); // se envia página Web
  }
}
