#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#include <ESP8266WiFi.h> // To disable wifi for ESP8266

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_OFF); // Disable wifi for ESP8266
  
  Wire.begin(2,0);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.dim(true); //(optional) dim the display  
  
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text

  display.clearDisplay(); 
  display.setCursor(30, 15);     // Start at top-left corner
  display.write("Booting...");
  display.display(); 
}

void loop() {
  while(Serial.available()) {
    display.clearDisplay(); 
    display.setCursor(0, 0); // Start at top-left corner of display

    String input = Serial.readString();
    split(input,"|");

    delay(1000);
    }
}

void split(String str, String delimeter) {
  String strs[20];
  int StringCount = 0;

    while (str.length() > 0) {
      int index = str.indexOf(delimeter);
      if (index == -1){ // No delimeter found (array size 1)
        strs[StringCount++] = str;
        break;
      }
      else {
        strs[StringCount++] = str.substring(0, index);
        str = str.substring(index+1);
        str.trim();
      }
    }

    // Display each element of the array on the display
    for (int i = 0; i <= StringCount; i++) {
      display.println(strs[i]);
      display.display();
    }
}
