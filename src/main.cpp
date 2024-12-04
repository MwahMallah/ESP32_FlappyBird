#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

// Define the pin connections for ESP32
#define __CS    5   // Chip Select pin
#define __DC    2   // Data/Command pin
#define __RESET 4   // Reset pin

// Initialize the TFT display with the correct pins
TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC, __RESET);

void setup() {
  // Start the TFT display
  tft.begin();
  
  // Optional: Set up the display (e.g., fill the screen with a color)
  tft.fillScreen(BLACK);
  
  // Optional: Test the display by drawing something
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.setCursor(10, 10);
  tft.print("Hello, ESP32!");
}

void loop() {
  // Your code here (e.g., animation, graphics, etc.)
}