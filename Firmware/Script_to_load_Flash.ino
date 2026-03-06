// load one bat call + bat breed and frequency into 2 blocks of flash memory
// will load 4 different MOVs at a time


#include <Adafruit_TinyFlash.h>
#include <SPI.h>

// #define LED A0

// // Blink LED (not pin 13) to indicate flash error
// void error(uint32_t d) {
//   for(;;) {
//     digitalWrite(LED, HIGH);
//     delay(d);
//     digitalWrite(LED, LOW);
//     delay(d);
//   }
// }

void setup() {
    Adafruit_TinyFlash flash;
    uint8_t            buffer[256];
    int                c, index      = 0;
    uint32_t           capacity, address = 0;
    Serial.begin(57600);
    Serial.println("HELLO");
    capacity = flash.begin(); //load the total flash memory capacity
    Serial.println(capacity);  
    while(!Serial.find("ERASE"));
    if(!flash.eraseChip()) {
        Serial.println("ERROR");
    }
    Serial.println("READY");


    for(uint8_t i = 0; i<4; i++){
        uint32_t address = 0x020000*i;
        uint32_t bytesExpected = 0x20000, bytesReceived = 0;
        index = 0;

        for(;;) {
            // Buffer data until a full page is ready or last packet arrives.
            if((c = Serial.read()) >= 0) {
            buffer[index++] = c;

            // Bytes 3-6 indicate number of samples to follow
            if(++bytesReceived == 6) {
                bytesExpected = (((uint32_t)buffer[2] << 24) |
                                ((uint32_t)buffer[3] << 16) |
                                ((uint32_t)buffer[4] <<  8) |
                                            buffer[5]      ) + 6;
            }

            if((index >= sizeof(buffer)) || (bytesReceived >= bytesExpected)) {
                if(flash.writePage(address, buffer)) {
                digitalWrite(LED, HIGH);
                Serial.print('.');
                } else {
                Serial.print('X');
                }
                address += sizeof(buffer);
                digitalWrite(LED, LOW);
                if((address >= capacity) || (bytesReceived >= bytesExpected)) break;
                index = 0;
            }
            }
        }
    }
}

void loop() { }

