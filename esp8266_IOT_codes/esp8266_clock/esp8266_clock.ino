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
    
    //#DO NOT USE THE SAME API-KEY as below
    http.begin("http://api.timezonedb.com/v2.1/get-time-zone?key=********API-KEY*********&format=json&by=zone&zone=Asia/Kolkata");  //Enter your API 
    
    int httpCode = http.GET(); //pass a get request                                                                  
     
    if (httpCode > 0) 
    {
      //Check the returning code
      
/*Phrasing Data using the JSON librarey */ //Use https://arduinojson.org/assistant/ to get the phrasing values for your JSON string 
     
      // Settig the size of the documents size to the reponse JSON
      const size_t capacity =JSON_OBJECT_SIZE(13) + 250;
     //Creating the JSON document file
      DynamicJsonDocument doc(capacity);
      
      //Get the JSON data and store it in doc
      deserializeJson(doc,http.getString());
      
      // Extracting the required data using the right key
      String currentDateTime = doc["formatted"]; // String content example"2019-07-03T12:07Z"

      //conversion, just taking the time part
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
