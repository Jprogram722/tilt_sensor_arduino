// Name: Jared Park
// A-number: A00426228
// Class: Expirimental Physics 1
// Assignment: Position indicator

int const trPin = A0; // sets the tilt sensor to analog pin A0
int const tlPin = A5; // sets the tilt sensor to analog pin A0
int const gPin = 2; // sets the pin connected to the green light to digital pin 2
int const yPin = 4; // sets the pin connected to the yellow light to digital pin 2
int const rPin = 8; // sets the pin connected to the red light to digital pin 2
int const pPin = 12; // sets the pin connected to the piezo to digital pin 2
int trVal; // creates a variable to measure the right side of the tilt sensor
int tlVal; // creates a variable to measure the right side of the tilt sensor


void setup() {
  pinMode(gPin , OUTPUT); // sets the pin connected to the green light to output voltage when called apon
  pinMode(yPin , OUTPUT); // sets the pin connected to the yellow light to output voltage when called apon
  pinMode(rPin , OUTPUT); // sets the pin connected to the red light to output voltage when called apon
  pinMode(pPin , OUTPUT); // sets the pin connected to the piezo to output voltage when called apon
  Serial.begin(9600); // begins reading data and 9600 bits per second
}

void loop() {
  tilt(); // calls on the tilt method
  GandYLEDsON(); // calls on the  GandYLightsON function 

}

// this method reads in the tilt sensor values
void tilt() {
  trVal = analogRead(trPin); // sets trVal to read values read by the right side of the tilt sensor
  tlVal = analogRead(tlPin); // sets tlVal to read values read by the left side of the tilt sensor
  Serial.print("Tilt Sensor Right Value " + String(trVal)); // Prints "Tilt Sensor Right Value" on the serial monitor then prints the value of trVal
  Serial.print(" "); // prints a spce of the serial monitor
  Serial.print("Tilt Sensor Left Value " + String(tlVal)); // Prints "Tilt Sensor Left Value" on the serial monitor then prints the value of tlVal
  Serial.println(" "); // moves text to the next line
}

// this method controls the LED's and piezo
void GandYLEDsON(){
  
  // this if loop activates if the values read in by the tilts sensors right side is greater than 800
  if (trVal > 800){
    
    // this if loop activates if the values read in by the tilts sensors left side is greater than 800
    if(tlVal > 800){
      digitalWrite(gPin , HIGH); // turns on green LED
      digitalWrite(yPin , LOW); // turns off yellow LED
      digitalWrite(rPin , LOW); // turns off red LED
      noTone(pPin); // tells piezo to make no noise
    }
    
    // this if loop activates if the values read in by the tilts sensors left side is less than 100
    if(tlVal < 100) {
      digitalWrite(gPin , LOW); // turns off green LED
      digitalWrite(yPin , HIGH); // turns on yellow LED
      digitalWrite(rPin , LOW); // turns off red LED
      noTone(pPin); // tells piezo to make no noise
    }
  }

  // this if loop activates if the values read in by the tilts sensors right side is less than 100
  if(trVal < 100) {
    
    //// this if loop activates if the values read in by the tilts sensors left side is greater than 800
    if(tlVal > 800) {
      digitalWrite(gPin , LOW); // turns off green LED
      digitalWrite(yPin , LOW); // turns off yellow LED
      digitalWrite(rPin , HIGH); // turns on red LED
      noTone(pPin); // tells piezo to make no noise
    }
    
    // this if loop activates if the values read in by the tilts sensors left side is less than 100
    if(tlVal < 100) {
      digitalWrite(gPin , LOW); // turns off green LED
      digitalWrite(yPin , LOW); // turns off yellow LED
      digitalWrite(rPin , LOW); // turns off red LED
      tone(pPin , 500); // tells piezo to make a buzzing noise with frequency of 500 Hz
    }
  }
}
