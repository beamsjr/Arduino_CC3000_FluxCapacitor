
 
 void initFlux(){
   
    dataArray[0] = 0x01; //11111110
    dataArray[1] = 0x02; //11111100
    dataArray[2] = 0x04; //11111001
    dataArray[3] = 0x08; //11110011
    dataArray[4] = 0x10; //11111000
    dataArray[5] = 0x20; //11110000
    dataArray[6] = 0x40; //11100000
    dataArray[7] = 0x80; //11000000
    dataArray[8] = 0x100; //10000000
    dataArray[9] = 0x2FF ; //10000000
 }
 
 void fluxAllOn(){
        digitalWrite(latchPin, 0);
        shiftOut(dataPin, clockPin, MSBFIRST, dataArray[9]);
        shiftOut(dataPin, clockPin, MSBFIRST, dataArray[9]);
        shiftOut(dataPin, clockPin, MSBFIRST, dataArray[9]);
        digitalWrite(latchPin, 1);
 }
 int d=0;
  void fluxTheCapacitor(){
        if (lastFlux + fluxDelay < millis()){   
          d++;
          if (d == 9){ d = 0;}
          Serial.println(dataArray[d]);
          data = dataArray[d];
          digitalWrite(latchPin, 0);
          shiftOut(dataPin, clockPin, MSBFIRST, data);
          shiftOut(dataPin, clockPin, MSBFIRST, data);
          shiftOut(dataPin, clockPin, MSBFIRST, data);
          digitalWrite(latchPin, 1);
          lastFlux = millis();
      }

  }
