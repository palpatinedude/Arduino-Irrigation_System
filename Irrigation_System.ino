const int sensor_pin = A0;
const int relay_pin = 2; // Change this to the actual pin you've connected the relay module to
int moisture_threshold = 800; // Adjust this threshold as needed
int watering_duration = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
  Serial.println("Setup Complete");
  delay(1000);
}

void loop() {
  int sensor_data = analogRead(sensor_pin);

  printMoisturePercentage(sensor_data);
  printAnalogValue(sensor_data);

  // Categorize soil moisture levels based on sensor data
  if (sensor_data > 700) {
    Serial.println("No moisture, Soil is dry");
    digitalWrite(relay_pin, LOW); 
    Serial.println("Water pump ON");
  } else if (sensor_data >= 400 && sensor_data <= 700) {
    Serial.println("There is some moisture, Soil is medium");
    digitalWrite(relay_pin, HIGH); 
    Serial.println("Water pump OFF");
  } else if (sensor_data < 400) {
    Serial.println("Soil is wet");
    digitalWrite(relay_pin, HIGH); 
    Serial.println("Water pump OFF");
  }

  delay(1000); // Delay for readability
}

void printMoisturePercentage(int sensor_data) {
  float moisture_percentage;
  moisture_percentage = 100.0 - ((sensor_data / 1023.0) * 100.0);
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage, 2);
  Serial.println("%");
}

void printAnalogValue(int sensor_data) {
  Serial.print("Sensor Data: ");
  Serial.println(sensor_data);
}

