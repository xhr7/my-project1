#include "WiFi.h"
String networkSSID = "";
int strengthSignal = -9999;

void setup() {
 Serial.begin(115200);
  WiFi.mode(WIFI_STA);//WIFI_STA is a constant indicating the station mode
   WiFi.disconnect(); 
      delay(100);
      
}

void loop() {
 int n = WiFi.scanNetworks();
    Serial.println("Scan performed");
    if (n == 0) {
        Serial.println("No network found");
    } else {
        networkSSID = "";
        strengthSignal= -9999;
        Serial.print(n);
        Serial.println(" networks found\n");
        for (int i = 0; i < n; ++i) {
        //print on serial monitor each of the networks found
          Serial.print("SSID: ");
          Serial.println(WiFi.SSID(i)); //network name (ssid)
          Serial.print("SIGNAL: ");
          Serial.print(WiFi.RSSI(i)); //signal strength
          Serial.print("\t\tCHANNEL: ");
          Serial.print((int)WiFi.channel(i));
          Serial.print("\t\tMAC: ");
          Serial.print(WiFi.BSSIDstr(i));
          Serial.println("\n\n");
          
 
          if(abs(WiFi.RSSI(i)) < abs(strengthSignal))
          {
             strengthSignal = WiFi.RSSI(i);
             networkSSID = WiFi.SSID(i);
             Serial.print("NETWORK WITH THE BEST SIGNAL FOUND: ( ");
             Serial.print(networkSSID);
             Serial.print(" ) - SIGNAL : ( ");
             Serial.print(strengthSignal );
             Serial.println(" )");
          }                        
         
          delay(10);
        }
    }
    Serial.println("\n------------------------------------------------------------------------------------\n");

// interval of 5 seconds to perform a new scan
    delay(5000);
}
