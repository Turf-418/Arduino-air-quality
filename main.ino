#include "thingProperties.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>
#include "Adafruit_CCS811.h"
#include "DHT.h"
#include "Adafruit_PM25AQI.h"
#include <Multichannel_Gas_GMXXX.h>
#include <Arduino.h>
#include "wiring_private.h"
#include <WiFiNINA.h>

#define DHTPIN 2
#define DHTTYPE DHT11 

Adafruit_PM25AQI aqi = Adafruit_PM25AQI();
GAS_GMXXX<TwoWire> gas;
Adafruit_CCS811 ccs;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  gas.begin();
  dht.begin();
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }

  while(!ccs.available());
  
  Serial.begin(115200);
  while (!Serial) delay(10);

  Serial.println("Adafruit PMSA003I Air Quality Sensor");
  
  delay(1000);

  /*Serial1.begin(9600);

  if (! aqi.begin_UART(&Serial1)) { 
    Serial.println("Could not find PM 2.5 sensor!");
    while (1) delay(10);
  }

  Serial.println("PM25 found!");*/
}

void loop() {
 
  MiCS();
  CCS811_sensor();
  Temperatura();
  //pms();
  
  ArduinoCloud.update();
  
  delay(1000);
}

void pms() {
  PM25_AQI_Data data;
  
  if (! aqi.read(&data)) {
    Serial.println("Could not read from AQI");
    delay(500);  // try again in a bit!
    return;
  }
  Serial.println("AQI reading success");
  
  pm1 = data.pm10_env;
  pm2 = data.pm25_env;
  pm10 = data.pm100_env;
  
  /*Serial.println();
  Serial.println(F("---------------------------------------"));
  Serial.println(F("Concentration Units (standard)"));
  Serial.println(F("---------------------------------------"));*/
  Serial.print(F("PM 1.0: ")); Serial.print(data.pm10_standard);
  Serial.print(F("\t\tPM 2.5: ")); Serial.print(data.pm25_standard);
  Serial.print(F("\t\tPM 10: ")); Serial.println(data.pm100_standard);
 /*Serial.println(F("Concentration Units (environmental)"));
  Serial.println(F("---------------------------------------"));*/
  Serial.print(F("PM 1.0: ")); Serial.print(data.pm10_env);
  Serial.print(F("\t\tPM 2.5: ")); Serial.print(data.pm25_env);
  Serial.print(F("\t\tPM 10: ")); Serial.println(data.pm100_env);
 /*Serial.println(F("---------------------------------------"));
  Serial.print(F("Particles > 0.3um / 0.1L air:")); Serial.println(data.particles_03um);
  Serial.print(F("Particles > 0.5um / 0.1L air:")); Serial.println(data.particles_05um);
  Serial.print(F("Particles > 1.0um / 0.1L air:")); Serial.println(data.particles_10um);
  Serial.print(F("Particles > 2.5um / 0.1L air:")); Serial.println(data.particles_25um);
  Serial.print(F("Particles > 5.0um / 0.1L air:")); Serial.println(data.particles_50um);
  Serial.print(F("Particles > 10 um / 0.1L air:")); Serial.println(data.particles_100um);
  Serial.println(F("---------------------------------------"));*/
}

void Temperatura(){
  umidita = dht.readHumidity();
  temperatura = dht.readTemperature();

  if (isnan(umidita) || isnan(temperatura) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
}

void MiCS(){
  
  monossido_di_carbonio = gas.getGM702B();
  if (monossido_di_carbonio > 999) monossido_di_carbonio = 999;
  
  etanolo= gas.getGM302B();
  if (etanolo > 999) etanolo = 999;
  
  diossido_di_azoto = gas.getGM102B();
  if (diossido_di_azoto > 999) diossido_di_azoto = 999;
  
  voc = gas.getGM502B();
  if (voc > 999) voc= 999;
}

void CCS811_sensor() {
  if(ccs.available()){
    if(!ccs.readData()){
      anidride_carbonica =  ccs.geteCO2();
      tvoc = ccs.getTVOC();
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
}