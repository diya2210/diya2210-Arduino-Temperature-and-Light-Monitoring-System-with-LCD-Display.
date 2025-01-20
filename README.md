# diya2210-Arduino-Temperature-and-Light-Monitoring-System-with-LCD-Display.
This project includes :-
Measuring temperature using a TMP36 temperature sensor.
Detecting light levels with a photoresistor (LDR).
Displaying temperature readings on an LCD screen.
Controlling an LED or buzzer based on the sensor readings
Initialization:
The LiquidCrystal object lcd_1 is initialized with the pin numbers connected to the LCD.
Various constants and variables are declared for controlling the LED, thresholds, and timing.

setup() Function:
Configures the LCD and initializes the pins for the temperature sensor, LED, and buzzer.
Sets up the serial communication for debugging or monitoring via the serial monitor.

loop() Function:
Reads the analog value from the temperature sensor connected to pin A0.
Converts the analog reading to voltage and then to temperature in Celsius.
Reads the brightness value from the photoresistor connected to pin A1.
Clears the LCD and displays the current temperature.
Checks if the brightness exceeds brightnessThreshold or if the temperature exceeds temperatureThreshold1 or is below temperatureThreshold2. If any condition is met, a tone is generated on the buzzer; otherwise, the buzzer is turned off.
Blinks the LED connected to pin 10 on and off every second.
