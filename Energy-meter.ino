


String num1;//danielraj
String num2;//praveen
String num3;//customer
String num4;//customer2



#include "mb_getdata.h"
#include "push_data_int.h"
#include "values.h"

#include <EEPROM.h>

#include <ArduinoJson.h>

int a, b, c;
const int X = 40001;

#define MAX485_DE 5
#define MAX485_RE_NEG 4
#define RX_PIN 16
#define TX_PIN 17
#define relay1 23
#define relay2 22
#define LED 25

bool st = false;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(LED, OUTPUT);

  modbus_init(MAX485_RE_NEG, MAX485_DE, RX_PIN, TX_PIN);
  Serial.begin(9600);
  

  }

void loop() {
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  digitalWrite(LED,LOW);

  //String fgh = get_data();
  

 // Serial.println();
  //Serial.println(fgh);
 

  // get modbus values
  Serial.println("Frequency\n");
  Frequency = modbus_read((43110 - X), 2);
  delay(250);
  Serial.println("wattsrphase\n");
  wattsrphase = modbus_read((43054- X), 2);
  delay(250);
  Serial.println("wattsyphase\n");
   wattsyphase = modbus_read((43056- X), 2);
   delay(250);
   Serial.println("wattsbphase\n");
   wattsbphase = modbus_read((43058 - X), 2);
   delay(250);
   Serial.println("wattstot\n");
   wattstot = modbus_read((43060 - X), 2);
   delay(250);
   Serial.println("kwh\n");
   kwh = modbus_read((42700 - X), 2);
   delay(250);
   Serial.println("currentrphase\n");
   currentrphase = modbus_read((43000 - X), 2);
   delay(250);
   Serial.println("currentyphase\n");
   currentyphase = modbus_read((43002 - X), 2);
   delay(250);
   Serial.println("currentbphase\n");
   currentbphase = modbus_read((43004 - X), 2);
   delay(250);
   Serial.println("currenttotal\n");
   currenttotal = modbus_read((43010 - X), 2);
   delay(250);
   Serial.println("PFAverage\n");
   PFAverage = modbus_read((43084 - X), 2);
   delay(250);
   Serial.println("vrphase\n");
   vrphase = modbus_read((43020 - X), 2);
   delay(250);
   Serial.println("vyphase\n");
   vyphase = modbus_read((43022 - X), 2);
   delay(250);
   Serial.println("vbphase\n");
   vbphase = modbus_read((43024 - X), 2);
   delay(250);
  
  String str_values =
    String(vrphase) + "," + String(vyphase) + "," + String(vbphase) + "," + String(currentrphase)+ "," + String(currentyphase)+ "," + String(currentbphase)+ "," + String(Frequency)+ "," + String(PFAverage)+ "," + String(kwh)+ "," + String(wattsrphase)+ "," + String(wattsyphase)+ "," + String(wattsbphase);

  Serial.println(str_values);
  
  
}
//101 102 105 106 107 108 117 119 125 126 127 128 129 130 131 133 134 135 136 137 138 139 140 141 142 143 144 145 111 116
