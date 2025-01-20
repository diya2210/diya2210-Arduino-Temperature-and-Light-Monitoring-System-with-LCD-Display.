#include <LiquidCrystal.h> // Include the LiquidCrystal library for controlling the LCD

// Initialize the LCD object (pins: RS, E, D4, D5, D6, D7)
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Constants for pin numbers and thresholds
const int ledPin = 10; // Pin number for the LED
const int brightnessThreshold = 600; // Threshold for brightness from the photoresistor
const float temperatureThreshold1 = 25.0; // Upper threshold for temperature in Celsius
const float temperatureThreshold2 = 0.0; // Lower threshold for temperature in Celsius

// Variables for LED state and timing
int ledState = LOW; // Current state of the LED (LOW = off, HIGH = on)
const long interval = 1000; // Interval at which to blink the LED (milliseconds)

void setup() {
    lcd_1.begin(16, 2); // Set up the LCD with 16 columns and 2 rows
    pinMode(A0, INPUT); // Set A0 as input for the temperature sensor (TMP36)
    pinMode(ledPin, OUTPUT); // Set the LED pin as output
    Serial.begin(9600); // Initialize serial communication at 9600 baud rate
    pinMode(9, OUTPUT); // Set pin 9 as output for the buzzer
    pinMode(10, OUTPUT); // Set pin 10 as output for the LED
}

void loop() {
    // Read and convert the analog value from the temperature sensor (TMP36)
    int sensorValue = analogRead(A0); // Read the analog value from A0
    float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog value to voltage
    float temperatureC = (voltage - 0.5) * 100.0; // Convert the voltage to temperature in Celsius

    // Read the brightness value from the photoresistor
    int sensorReading = analogRead(A1); // Read the analog value from A1

    // Clear the LCD and display the temperature
    lcd_1.clear(); // Clear the LCD screen
    lcd_1.setCursor(0, 0); // Set the cursor to the first row, first column
    lcd_1.print("Temp (C):"); // Print "Temp (C):" on the LCD
    lcd_1.setCursor(0, 1); // Set the cursor to the second row, first column
    lcd_1.print(temperatureC); // Display the temperature on the LCD
    delay(1000); // Wait for 1 second before refreshing the display

    // Check if the brightness or temperature exceeds or falls below the thresholds
    if (sensorReading > brightnessThreshold || temperatureC > temperatureThreshold1 || temperatureC < temperatureThreshold2) {
        // Generate a tone on the buzzer if any condition is met
        tone(9, 440 * pow(2.0, (constrain(int(map(sensorReading, 0, 1023, 36, 84)), 35, 127) - 57) / 12.0), 1000);
    } else {
        // Turn off the buzzer if none of the conditions are met
        noTone(9);
    }
    delay(1000); // Wait for 1 second

    // Blink the LED on and off every second
    digitalWrite(10, HIGH); // Turn the LED on
    delay(1000); // Wait for 1 second
    digitalWrite(10, LOW); // Turn the LED off
    delay(1000); // Wait for 1 second
}
