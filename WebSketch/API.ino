void api(Adafruit_CC3000_ClientRef client) 
{  
    matched = false;
    String answer = "";
    char c;
    String requestParts[3];
    String urlParts[4];
      
    // Check if there is data available to read
    while (client.available()) {
      fluxTheCapacitor();
        // Get the server answer
         c = client.read();
        delay(1);
        answer = answer + c;
        
        // Check if we are receveing useful data and process it
        if ((c == '/' || c == '\r') && matched == false) {
          if (answer.startsWith("GET")){
          splitString(answer, ' ', requestParts);
          splitString(requestParts[1], '/', urlParts);
          Serial.println("Request Type: " + requestParts[0]);
          Serial.println("Method: " + urlParts[0]);
          Serial.println("Value: " + urlParts[1]);
          
           if (urlParts[0] == "delay" && urlParts[1].length() > 0) {
             fluxDelay = urlParts[1].toInt();
             send_http_headers(client);
             matched = true;
              client.print(F("{\""));
               client.print(urlParts[0]);
               client.print(F("\": "));
               client.print(urlParts[1]);
               client.println(F("\", \"}"));
           }
     }
    }
  }
}

