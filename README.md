Arduino-Irrigation_System
=========================

WATER PLANTS ACCORDING TO THE LEVEL OF MOISTURE IN THE SOIL

About:
------
This system operates by constantly monitoring the moisture level in the soil where a plant is situated. It accomplishes this by employing a soil moisture sensor connected to an Arduino microcontroller. The system categorizes soil moisture levels as either dry, moderately moist, or wet based on sensor data. When the soil is recognized as dry, the system activates a water pump through a relay module, delivering water to the plant.

Components:
-----------
1. Arduino UNO Rev3
2. Soil Moisture Sensor
3. Water Pump
4. Relay Module 5V 1 channel - low trigger
5. Tube
6. 9V battery
7. Jumper Wires (Male to Female)
8. Screwdriver

Wiring:
-------
- Sensor to Arduino:  
  - VCC to 3.3V  
  - GND to GND  
  - A0 to A0  

- Relay to Arduino:  
  - VCC to 5V  
  - GND to GND  
  - IN to D2  

- Relay to Water Pump:  
  - COM terminal of the relay connects with the (+) terminal of the battery  
  - NO terminal of the relay connects with the red wire of the water pump  
  - Connect the water pump's (-) terminal to the (-) terminal of the battery
