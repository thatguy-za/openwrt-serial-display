# openwrt-serial-display

In my quest to build the ultimate travel router (check out the write up [here](https://tristam.ie/2023/582/)!), I wanted to add a 0.91′ oled display to a Raspberry Pi that’s running OpenWrt. Unfortunately the Adafruit SSD1306 python library requires the RPi.GPIO library which doesn’t work with OpenWrt so we need to get creative!

This project focuses on using an ESP8266 microcontroller to add an i2c displaly to a Paspberry Pi via serial. For more info on this part of the project, check out my write up [here](https://tristam.ie/2023/671/).
