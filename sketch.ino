#include <Arduino.h>
#include <Wire.h>
#include "SSD1306Wire.h"
#include <DHTesp.h>
#include <Adafruit_BMP085.h>

#define DHT_PIN 15
#define I2C_SDA 21
#define I2C_SCL 22
#define LDR_PIN 34


DHTesp dht;
Adafruit_BMP085 bmp;

SSD1306Wire display(0x3C, I2C_SDA, I2C_SCL);

const unsigned char icon_temp[] PROGMEM = {
  0x60, 0x06,
  0x60, 0x06,
  0x60, 0x06,
  0x60, 0x06,
  0x60, 0x06,
  0x60, 0x06,
  0x60, 0x06,
  0x60, 0x06,
  0x60, 0x06,
  0x60, 0x06,
  0xE0, 0x07,
  0xF0, 0x0F,
  0xF0, 0x0F,
  0xE0, 0x07,
  0xC0, 0x03,
  0x80, 0x01
};


const unsigned char icon_umidade[] PROGMEM = {
  0x80, 0x01,
  0xC0, 0x03,
  0xE0, 0x07,
  0xF0, 0x0F,
  0xF0, 0x0F,
  0xF8, 0x1F,
  0xF8, 0x1F,
  0xFC, 0x3F,
  0xFC, 0x3F,
  0xFC, 0x3F,
  0xF8, 0x1F,
  0xF8, 0x1F,
  0xF0, 0x0F,
  0xE0, 0x07,
  0xC0, 0x03,
  0x80, 0x01
};

const unsigned char icon_pressao[] PROGMEM = {
  0x00, 0x00,
  0x00, 0x00,
  0xF8, 0x1F,
  0xFC, 0x3F,
  0x00, 0x18,
  0x00, 0x0C,
  0x00, 0x06,
  0x00, 0x03,
  0x80, 0x01,
  0xC0, 0x00,
  0x60, 0x00,
  0x30, 0x00,
  0x18, 0x00,
  0xFC, 0x3F,
  0xF8, 0x1F,
  0x00, 0x00
};


const unsigned char icon_luz[] PROGMEM = {
  0x80, 0x01,
  0x80, 0x01,
  0x88, 0x11,
  0x98, 0x19,
  0xF0, 0x07,
  0xFC, 0x3F,
  0xFC, 0x3F,
  0xFE, 0x7F,
  0xFE, 0x7F,
  0xFC, 0x3F,
  0xFC, 0x3F,
  0xF0, 0x07,
  0x98, 0x19,
  0x88, 0x11,
  0x80, 0x01,
  0x80, 0x01
};

void setup() {

  Serial.begin(115200);

  dht.setup(DHT_PIN, DHTesp::DHT22);

  if (!bmp.begin()) {

    Serial.println("ERRO: BMP180 nao encontrado!");

  } else {

    Serial.println("BMP180 OK!");

  }

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

  Serial.println("Estacao climatica iniciada!");
}

void loop() {
  TempAndHumidity data = dht.getTempAndHumidity();

  float temp = data.temperature;
  float hum = data.humidity;

  float bmpTemp = bmp.readTemperature();
  float pressure = bmp.readPressure();


  int ldrValor = analogRead(LDR_PIN);

  int ldr = map(ldrValor, 0, 4095, 0, 100);

  ldr = constrain(ldr, 0, 100);

  Serial.println("-----------------------------");

  Serial.print("Temperatura DHT22: ");
  Serial.print(temp);
  Serial.println(" C");

  Serial.print("Umidade: ");
  Serial.print(hum);
  Serial.println(" %");

  Serial.print("Temperatura BMP180: ");
  Serial.print(bmpTemp);
  Serial.println(" C");

  Serial.print("Pressao: ");
  Serial.print(pressure);
  Serial.println(" Pa");

  Serial.print("Luz (LDR): ");
  Serial.print(ldr);
  Serial.println(" %");

  display.clear();
  display.drawXbm(
    0,
    0,
    16,
    16,
    icon_temp
  );

  display.drawString(
    22,
    3,
    "Temp: " + String(temp, 1) + " C"
  );

  display.drawXbm(
    0,
    16,
    16,
    16,
    icon_umidade
  );

  display.drawString(
    22,
    19,
    "Umid: " + String(hum, 1) + " %"
  );

  display.drawXbm(
    0,
    32,
    16,
    16,
    icon_pressao
  );

  display.drawString(
    22,
    35,
    "Press: " + String(pressure / 100.0, 0) + " hPa"
  );

  display.drawXbm(
    0,
    48,
    16,
    16,
    icon_luz
  );

  display.drawString(
    22,
    51,
    "Luz: " + String(ldr) + "%"
  );

  display.display();

  delay(2000);
}