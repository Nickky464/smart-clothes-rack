#include <Arduino.h>
#include <ESP8266WiFi.h>

// wifi connection

int ledpin = 2; // ledpin
int rainpin = 5; // rainsensor pin D1
int rain_relay_1 = 14; // rain relay D5
int rain_state = 0; //rain state


void setup()
{
  Serial.begin(9600);
  Serial.println();

  // led set
  pinMode(ledpin, OUTPUT);
  pinMode(rain_relay_1, OUTPUT);
  pinMode(rainpin, INPUT);

}

void loop() 
{
  rain_state = digitalRead(rainpin);
  Serial.print("rain_state = ");
  Serial.println(rain_state);
  if (rain_state == 1) {
    digitalWrite(rain_relay_1,LOW);
  } else {
    digitalWrite(rain_relay_1,HIGH);
  }
  delay(100);
}