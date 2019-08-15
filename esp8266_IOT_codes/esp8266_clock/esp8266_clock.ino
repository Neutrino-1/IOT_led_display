#include <ESP8266WiFi.h> //ESP8266 Library
#include <ESP8266HTTPClient.h> //ESP8266 Library
#include <ArduinoJson.h> //For phrasing JSON file download from https://github.com/bblanchon/ArduinoJson
 
const char* ssid = "Name of the Wifi"; //Enter your Wi-Fi SSID
const char* password = "Wifi Password"; //Enter you Wi-Fi Password

String currentTime;
//change the offset of GMT according to your country
String payload; //To store the JSON object as string

void setup () {
 
  Serial.begin(115200); //initialise serial monitor to send data to Arduino
  WiFi.begin(ssid, password); //connect to the network specified above
  while (WiFi.status() != WL_CONNECTED) { //Wait till Wi-Fi is connected
    delay(2000);
  }
}
 
void loop() {
 if (WiFi.status() == WL_CONNECTED) 
 { 
  //If Wi-Fi connected successfully 
  
    HTTPClient http;  //start a HTTPClinet as http 
    
    //####DO NOT USE THE SAME API as below
    http.begin("http://api.timezonedb.com/v2.1/get-time-zone?key=********API-KEY*********&format=json&by=zone&zone=Asia/Kolkata");  //Enter your API 
    
    int httpCode = http.GET(); //pass a get request                                                                  
     
    if (httpCode > 0) 
    {
      //Check the returning code
      
/*Phrasing Data using the JSON librarey */ //Use https://arduinojson.org/assistant/ to get the phrasing values for your JSON string 

      const size_t capacity =JSON_OBJECT_SIZE(13) + 250;
      DynamicJsonDocument doc(capacity);

      //const char* json = "{\"status\":\"OK\",\"message\":\"\",\"countryCode\":\"IN\",\"countryName\":\"India\",\"zoneName\":\"Asia/Kolkata\",\"abbreviation\":\"IST\",\"gmtOffset\":19800,\"dst\":\"0\",\"zoneStart\":-764145000,\"zoneEnd\":null,\"nextAbbreviation\":null,\"timestamp\":1563199871,\"formatted\":\"2019-07-15 14:11:11\"}";

      deserializeJson(doc,http.getString());
      
      String currentDateTime = doc["formatted"]; // "2019-07-03T12:07Z"

      //conversion
      String local_time =  currentDateTime.substring(11,16);    
    if(!currentTime.equals(local_time))
    {
   // Serial.print(local_time.substring(0,2)+":"+local_time.substring(2,5)); //send this to arduino if you are using page function
    Serial.print(local_time);//send this to arduino if you are using scroll function
    }
    currentTime = local_time;
    }
    http.end();   //Close http connection
     
 }
     delay(15000);  //send values to Arduino every 30 sec.
}
