#include <ESP8266WiFi.h> //ESP8266 Library
#include <ESP8266HTTPClient.h> //ESP8266 Library
#include <ArduinoJson.h> //For phrasing JSON file download from https://github.com/bblanchon/ArduinoJson
 
const char* ssid = "NO INTERNET"; //Enter your Wi-Fi SSID
const char* password = "Asdf@qwe!"; //Enter you Wi-Fi Password

String currentTime;
//change the offset of GMT according to your country
String GMT_hr = 5; 
String GMT_min = 50;
String payload; //To store the JSON object as string

void setup () {
 
  Serial.begin(115200); //initialise serial monitor to send data to Arduino
  WiFi.begin(ssid, password); //connect to the network specified above
  while (WiFi.status() != WL_CONNECTED) { //Wait till Wi-Fi is connected
    delay(2000);
    Serial.print(".."); //Print Connecting.. till connection is established  
  }
}
 
void loop() {
 if (WiFi.status() == WL_CONNECTED) 
 { 
  //If Wi-Fi connected successfully 
  
    HTTPClient http;  //start a HTTPClinet as http 
    
    //####DO NOT USE THE SAME API as below
    http.begin("http://worldclockapi.com/api/json/utc/now");  //Enter your API 
    
    int httpCode = http.GET(); //pass a get request                                                                  
     
    if (httpCode > 0) 
    {
      //Check the returning code

/*Phrasing Data using the JSON librarey */ //Use https://arduinojson.org/assistant/ to get the phrasing values for your JSON string 

      const size_t capacity = JSON_OBJECT_SIZE(9) + 230;
      DynamicJsonDocument doc(capacity);

      const char* json = "{\"$id\":\"1\",\"currentDateTime\":\"2019-07-03T12:07Z\",\"utcOffset\":\"00:00:00\",\"isDayLightSavingsTime\":false,\"dayOfTheWeek\":\"Wednesday\",\"timeZoneName\":\"UTC\",\"currentFileTime\":132066292579572500,\"ordinalDate\":\"2019-184\",\"serviceResponse\":null}";

      deserializeJson(doc,json);

      const char* currentDateTime = doc["currentDateTime"]; // "2019-07-03T12:07Z"

      //conversion
    String local_time =  currentDateTime.substring(14,16); 
    int local_time_m = local_time.toInt()+GMT_min;
    local_time = currentDateTime.substring(11,13); 
    int local_time_h = local_time.toInt()+GMT_hr+(local_time_m/60);
    local_time_m %= 60;
    local_time = String(local_time_h)+":"+String(local_time_m);
    //local_time = String(local_time_h)+"::"+String(local_time_m); //use this line and comment the above one if your using page function in arduino
      //Print the variables thorugh serial monitor
    if(currentTime.equals(local_time))
    {
    Serial.print(local_time); //send the location details to Arduino
    }
    currentTime = local_time;
    }
    http.end();   //Close http connection
 }
    delay(3000);    //send values to Arduino every 30 sec.
}
