// MIC
const int ledpin=13; // ledpin and soundpin are not changed throughout the process
const int soundpin=0;
const int thresholdDown=325; // sets threshold value for sound sensor
const int thresholdUp=360; // sets threshold value for sound sensor

// POTI
const int potPin = 16; //pin A0 to read analog input
int potiMic; //save analog value
int potiSound = 0;  
int howLoud;

void setup() {
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  pinMode(soundpin,INPUT);
}

void loop() {

 // poti_sound_reactivity
      potiSound = analogRead(potPin);    // read the value from the sensor
      howLoud = map(potiSound, 0, 1024, 0, 255);

  // MIC 
      int micInput; // variable here seems to be more dynamic
      micInput=analogRead(0)+howLoud*3;   //connect mic sensor to Analog 0
      Serial.println(micInput,DEC);//print the sound micInputue to serial

  if (micInput < thresholdDown || micInput > thresholdUp) {
    digitalWrite(ledpin,HIGH); //turns led on
    //delay(100);
}
  else {
      digitalWrite(ledpin,LOW);
       }


  delay(100);
}
