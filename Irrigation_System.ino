// setup() function runs once when the Arduino board is powered on or reset, used for initialization tasks.
// loop()  continuously repeats the code inside it, allowing  Arduino to perform its intended tasks.
// pinMode() function is used to configure a specific digital pin on the Arduino  as either an input or an output.


const int sensor_pin = A0; // connect the soil moisture sensor to this analog pin
const int relay_pin = 2;   // connect the relay module to control the water pump to this digital pin
int moisture_threshold = 800; // set the threshold value for soil moisture 
int watering_duration = 1000; // set the duration for which the water pump runs 

void setup() {
  Serial.begin(9600); // initialize the serial communication at a baud rate of 9600 bits per second ,determines the speed at which data is transmitted and received over the serial connection.
  pinMode(sensor_pin, INPUT); // set the sensor pin as an input for reading sensor data
  pinMode(relay_pin, OUTPUT); // set the relay pin as an output to control the water pump
  Serial.println("Setup complete"); 
  delay(1000);
}

void loop() {
  //the microcontroller samples the voltage on the specified pin and converts it into a digital value between 0 and 1023 based on the 10-bit ADC.
  int sensor_data = analogRead(sensor_pin); // read the analog value from the soil moisture sensor

  printMoisturePercentage(sensor_data);
  printAnalogValue(sensor_data);

  // categorize soil moisture levels based on sensor data
  if (sensor_data > 700) {
    Serial.println("No moisture, soil is dry");
    digitalWrite(relay_pin, LOW); 
    Serial.println("Water pump ON");
  } else if (sensor_data >= 400 && sensor_data <= 700) {
    Serial.println("There is some moisture, soil is medium");
    digitalWrite(relay_pin, HIGH); 
    Serial.println("Water pump OFF");
  } else if (sensor_data < 400) {
    Serial.println("Soil is wet");
    digitalWrite(relay_pin, HIGH); 
    Serial.println("Water pump OFF");
  }

  delay(1000); // delay for readability
}

void printMoisturePercentage(int sensor_data) {
  float moisture_percentage;
  moisture_percentage = 100.0 - ((sensor_data / 1023.0) * 100.0); // calculate the moisture percentage based on sensor data
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage, 2);
  Serial.println("%");
}

void printAnalogValue(int sensor_data) {
  Serial.print("Sensor data: ");
  Serial.println(sensor_data); 
}



