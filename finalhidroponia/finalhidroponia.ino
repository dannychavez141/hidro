#include <EEPROM.h>
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include <UIPEthernet.h> // Librería Ethernet usada con el módulo ENC28J60
byte direccion_mac[]={0x74,0x69,0x69,0x2D,0x30,0x31 }; // Dirección MAC inventada
IPAddress direccion_ip_fija(192,168,1,6); // Dirección IP elegida para el módulo
IPAddress servidor_dns(8,8,8,8); // Servidor OpenNIC (de Alejandro Bonet, http://opennic.alargador.org)
IPAddress puerta_enlace(192,168,1,1); // Dirección IP del router
IPAddress mascara_red(255,255,255,0); // Máscara de la red
IPAddress server(192,168,1,35); // Dirección IP del servidor web (en la intranet)
//char url_servidor_web[]="hidroponia.unu.com"; // URL poético para un gestor de sueño (en Internet)
EthernetClient client;
byte estado_conexion;
const int llave1 = 3;
const int llave2 = 4;
const int llave3 = 5;
const int bomba = 6;
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
RTC_DS1307 RTC;
float contador=0;
int tiempo=0;
int hum1=0;
int tem1=0;
int h1llave=0;
int h2llave=0;
int h3llave=0;
int horau=0;
int minuu=0;
int seguu=0;
int c1=0;
int c2=0;
int c3=0;
int hora=0;
int minu=0;
int segu=0;
const int p1 = A2;
const int p2 = A1;
const int p3 =A0 ;
const int p4 =8 ;
const int p5 =7 ;
const int p6 =9 ;
int v1 = 0;
int v2 = 0;
int v3 = 0;
int v4 = 0;
int v5 = 0;
int v6 = 0;
int h1=0,h2=0,m1=0,m2=0;
int cambio=1;
int modo=1;
char estado='a';
void setup() {
  lcd.init();
  lcd.backlight();
Serial.begin(9600);
  //actualizarbd(0,6);
 // actualizarbd(1,0);
 // actualizarbd(2,18);
  //actualizarbd(3,0);
 // actualizarbd(4,30);
  h1=leerbd(0);
  m1=leerbd(1);
  h2=leerbd(2);
  m2=leerbd(3);
    tiempo=leerbd(4);
     pinMode(bomba, OUTPUT);
  pinMode(llave1, OUTPUT);
  pinMode(llave2, OUTPUT);
  pinMode(llave3, OUTPUT);
   digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
      Serial.println("Conectando con el servidor ...");
  Ethernet.begin(direccion_mac,direccion_ip_fija,servidor_dns,puerta_enlace,mascara_red);
  Serial.println(Ethernet.localIP());
}

void loop() {
menu();

}

void menu()
{switch (modo) {
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
}}
 void modo1(){
  valores();
  leer();
  mostrar();
  if(c1!=0){
    c1=c1+1;
    if(c1>20){
      digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
      h1llave=0;
     h2llave=0;
     h3llave=0;
     envio();
      c1=0;
      }
    }
   
   if(v2==1){digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
      h1llave=1;
     h2llave=0;
     h3llave=0;
      //envio();
      delay(1000);
    digitalWrite(llave1, HIGH);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, LOW);
      c1=1;
      horau=hora;
minuu=minu;
seguu=segu;
      }
   if(v3==1){digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
      h1llave=0;
     h2llave=1;
     h3llave=0;
      //envio();
      delay(1000);
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, HIGH);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, LOW);
       c1=1;
       horau=hora;
minuu=minu;
seguu=segu;
       }
   if(v5==1){digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
      h1llave=0;
     h2llave=0;
     h3llave=1;
     // envio();
      delay(1000);
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, HIGH);
      digitalWrite(bomba, LOW);
       c1=1;
       horau=hora;
minuu=minu;
seguu=segu;
}
       if(v4==1){digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
    
      envio(); 
      h1llave=0;
     h2llave=0;
     h3llave=0;
       c1=0;}
   if(v6==1){modo=2;
   h1=leerbd(0);
  m1=leerbd(1);}
  return;
  }
  void modo2(){
  leer();
   mostrar();
   
   if(v2==1){}
   if(v5==1){if(cambio==1){cambio=2;}else{cambio=1;}}
   if(v2==1){if(cambio==1){cambio=2;}else{cambio=1;}}
   if(v1==1){modo=1;
    actualizarbd(0,h1);
  actualizarbd(1,m1);
  h2=leerbd(2);
  m2=leerbd(3);
  }
   if(v6==1){actualizarbd(0,h1);
  actualizarbd(1,m1);
  modo=3; 
 
  
}
 lcd.clear();
lcd.setCursor(0,0);
  lcd.print("C.H.INICIO:");
  lcd.print(" MD:");
    lcd.print(modo);
lcd.setCursor(0,1);
  lcd.print(h1);
  lcd.print(":");
   lcd.print(m1);
  lcd.print("/");
    if(cambio==1)
    {lcd.print("C.Hora");
    if(v3==1){
    if(h1<23){h1=h1+1;}else{h1=0;}
   }
    if(v4==1){
      if(h1>=1){h1=h1-1;}else{h1=23;}}
      }else{
        lcd.print("C.Minu");
         if(v3==1){if(m1<59){m1=m1+1;}else{m1=0;}}
   
    if(v4==1){if(m1>=1){m1=m1-1;}else{m1=59;}}
   }
 
  return;
  }
  void modo3(){
  leer();
   mostrar();
   
 
   if(v2==1){}
   if(v5==1){if(cambio==1){cambio=2;}else{cambio=1;}}
   if(v2==1){if(cambio==1){cambio=2;}else{cambio=1;}}
   if(v1==1){modo=2;
    actualizarbd(2,h2);
  actualizarbd(3,m2);
  }
   if(v6==1){modo=4;
    actualizarbd(2,h2);
  actualizarbd(3,m2); 
  tiempo=leerbd(4);}
 lcd.clear();
lcd.setCursor(0,0);
  lcd.print("C.H.FINAL:");
  lcd.print(" MD:");
    lcd.print(modo);
lcd.setCursor(0,1);
  lcd.print(h2);
  lcd.print(":");
   lcd.print(m2);
  lcd.print(" / ");
    if(cambio==1)
    {lcd.print("C.Hora");
    if(v3==1){
    if(h2<23){h2=h2+1;}else{h2=0;}}
    if(v4==1){
      if(h2>=1){h2=h2-1;}else{h2=23;}}
      }else{
        lcd.print("C.Minu");
         if(v3==1){if(m2<59){m2=m2+1;}else{m2=0;}}
    if(v4==1){if(m2>=1){m2=m2-1;}else{m2=59;}}
   }
 
  return;
  }
  void modo4(){
  leer();
   mostrar();

   if(v2==1){}
   if(v1==1){modo=3;
    actualizarbd(4,tiempo);
  }
   if(v6==1){modo=5;
     actualizarbd(4,tiempo);
     }
 lcd.clear();
lcd.setCursor(0,0);
  lcd.print("ENTRE TIEMPO");
  lcd.setCursor(0,1);
  lcd.print("DE RIEGO:");
lcd.setCursor(0,2);
  lcd.print(tiempo);
  lcd.print(" ");
    lcd.print("Minutos");
    if(v3==1){
    if(tiempo<179){tiempo=tiempo+1;}else{tiempo=0;}}
    if(v4==1){
      if(tiempo>=1){tiempo=tiempo-1;}else{tiempo=179;}}
      
   
 
  return;
  }
  void modo5(){
  lcd.clear();
lcd.setCursor(0,0);
  lcd.print("H.INICIO:");
  lcd.print(h1);
  lcd.print(":");
   lcd.print(m1);
   lcd.print(":");
   lcd.print("0");
lcd.setCursor(0,1);
  lcd.print("H.FINAL:");
  lcd.print(h2);
  lcd.print(":");
   lcd.print(m2);
   lcd.print(":");
   lcd.print("0");
   lcd.setCursor(0,2);
  lcd.print("Entre tiempo:");
  lcd.print(tiempo);
  lcd.print("Min");
  lcd.setCursor(0,3);
  lcd.print("Prox riego en:");
  lcd.print(tiempo-contador);
  lcd.print("Min");
   delay(2000);
   modo=1;
 
  return;
  }

void mostrar(){Serial.print("Valor p1:");
  Serial.println(v1);
   Serial.print("Valor p2:");
  Serial.println(v2);
   Serial.print("Valor p3:");
  Serial.println(v3);
   Serial.print("Valor p4:");
  Serial.println(v4);
   Serial.print("Valor p5:");
  Serial.println(v5);
   Serial.print("Valor p6:");
  Serial.println(v6);}
void leer(){
   v1 = 0;
   v2 = 0;
   v3 = 0;
   v4 = 0;
   v5 = 0;
   v6 = 0; 
   
   v1 = digitalRead(p1);
   v2 = digitalRead(p2);
   v3 = digitalRead(p3);
   v4 = digitalRead(p4);
   v5 = digitalRead(p5);
   v6 = digitalRead(p6); 
   delay(500);
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
    lcd.print(tiempo-contador);
    lcd.print("Min"); 
    lcd.setCursor(0, 3);
    lcd.print("Ult riego:");
    lcd.print(horau);
    lcd.print(":");
    lcd.print(minuu);
    lcd.print(":");
    lcd.print(seguu); 
    
hora=(now.hour());
minu=(now.minute());
segu=(now.second());
Serial.print(hora);
Serial.print(':');
Serial.print(minu);
Serial.print(':');
Serial.println(segu);  
if(segu==0){
contador=contador+1;
}
if(hora>h1 && hora<h2){
int evalua=tiempo-contador;
  if(evalua<0){contador=0;}
  if(estado=='a'){
    
  if(evalua==0 && segu==0){
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
      h1llave=1;
     h2llave=0;
     h3llave=0;
      envio();
      delay(1000);
    digitalWrite(llave1, HIGH);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, LOW);
     c1=-50;
     estado='b';
     }
      
      }
    if(estado=='b'){
  if(evalua==0 && segu==10){
   
    delay(1500);
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
     h1llave=0;
     h2llave=1;
     h3llave=0; 
    envio();
    delay(1000);
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, HIGH);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, LOW);
       c1=-50;
  estado='c';
  } 
  }
  if(estado=='c'){
  if(evalua==0 && segu==21){
    delay(1500);
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
      h1llave=0;
     h2llave=0;
     h3llave=1; 
      envio();
      delay(1000);
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, HIGH);
      digitalWrite(bomba, LOW);
       c1=-50;
  estado='d';}
  }
    if(estado=='d'){
  if(evalua==-0 && segu==32){
    digitalWrite(llave1, LOW);
    digitalWrite(llave2, LOW);
    digitalWrite(llave3, LOW);
      digitalWrite(bomba, HIGH);
      h1llave=0;
      h2llave=0;
      h3llave=0;
       envio();
      delay(1000);
     horau=hora;
minuu=minu;
seguu=segu;
       c1=0;
     estado='a'; 
     contador=0;
     } 
     
  } 
  }
  
}
void envio(){
  if (client.connect(server, 80)>0) {  // Conexion con el servidor
    client.print("GET /hidro/subir.php?h="); // Enviamos los datos por GET
    client.print(hum1);
    client.print("&t="); // Enviamos los datos por GET temperatura
    client.print(tem1);
    client.print("&h1="); // Enviamos los datos por GET estado 1
   client.print(h1llave);
   client.print("&h2="); // Enviamos los datos por GET estado 1
   client.print(h2llave);
   client.print("&h3="); // Enviamos los datos por GET estado 1
   client.print(h3llave);   
    client.println(" HTTP/1.0");
    client.println("User-Agent: Arduino 1.0");
    client.println();
    Serial.println("Conectado");
  } else {
    Serial.println("Fallo en la conexion");
  }
  }
void actualizarbd(int id,int valor) {
  EEPROM.write(id, valor);
  
}
int leerbd(int id){
int val = (int)EEPROM.read(id);
return val;}
