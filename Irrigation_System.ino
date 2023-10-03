// setup() function runs once when the Arduino board is powered on or reset, used for initialization tasks.
// loop()  continuously repeats the code inside it, allowing  Arduino to perform its intended tasks.
// pinMode() function is used to configure a specific digital pin on the Arduino  as either an input or an output.


const int sensor_pin = A0; // connect the soil moisture sensor to this analog pin
const int relay_pin = 2;   // connect the relay module to control the water pump to this digital pin

void setup() {
 // Serial.flush();
  digitalWrite(relay_pin,HIGH);  // initiliaze the water pump off
  Serial.begin(9600); // initialize the serial communication at a baud rate of 9600 bits per second ,determines the speed at which data is transmitted and received over the serial connection.
  pinMode(sensor_pin, INPUT); // set the sensor pin as an input for reading sensor data
  pinMode(relay_pin, OUTPUT); // set the relay pin as an output to control the water pump
  Serial.println("SET UP COMPLETE"); 
  delay(1000);
}

void loop() {
  //the microcontroller samples the voltage on the specified pin and converts it into a digital value between 0 and 1023 based on the 10-bit ADC.
  int sensor_data = analogRead(sensor_pin); // read the analog value from the soil moisture sensor
  float moisture_percentage = map(sensor_data, 666, 320, 0, 100); // scale or map a value from one range to another, used to convert a value to a percentage
  printMoisturePercentage(moisture_percentage);
  printAnalogValue(sensor_data);

  // categorize soil moisture levels based on sensor data
  if (sensor_data > 600) {
    Serial.println("NO MOISTURE, THE SOIL IS DRY");
    digitalWrite(relay_pin, LOW); 
    Serial.println("WATER PUMP ON");
  } else if (sensor_data >= 430 && sensor_data <= 600) {
    Serial.println("THERE IS SOME MOISTURE ..");
    digitalWrite(relay_pin, HIGH); 
    Serial.println("WATER PUMP OFF");
  } else if (sensor_data < 450) {
    Serial.println("SOIL IS WET");
    digitalWrite(relay_pin, HIGH); 
    Serial.println("WATER PUMP OFF");
  }

  delay(1000); // delay for readability
}
/*
void printMoisturePercentage(int sensor_data) {
  float moisture_percentage;
  moisture_percentage = 100.0 - ((sensor_data / 1023.0) * 100.0); // calculate the moisture percentage based on sensor data
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage, 2);
  Serial.println("%");
}*/
void printMoisturePercentage(float percentage){
  Serial.print("Moisture Percentage: ");
  Serial.println(percentage); 

}

void printAnalogValue(int sensor_data) {
  Serial.print("Sensor data: ");
  Serial.println(sensor_data); 
}
