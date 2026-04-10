// Winbond serial flash loader.  Runs on normal Arduino (e.g. Uno,
// NOT Trinket), works with 'AudioXfer' Processing code on host PC.

#include <SPIMemory.h>
// #include <SPI.h>

#define LED A0

// Blink LED (not pin 13) to indicate flash error
void error(uint32_t d) {
  for(;;) {
    digitalWrite(LED, HIGH);
    delay(d);
    digitalWrite(LED, LOW);
    delay(d);
  }
}

bool FlashWrite(SPIFlash &flash, uint32_t address, uint8_t data){
  if (flash.writeByte(address, data)) {
    //Serial.print(data);
    //Serial.print(" has been written to address ");
    //Serial.println(address);
    // delay(10);
    uint8_t test = flash.readByte(address);

    if(test != data){
      Serial.print(address);
      Serial.println(" FAILED VERIFY");
      return false;
    }
    return true;
  } else {
    Serial.print(address);
    Serial.println(" FAILED");
    return false;
  }
}

void myPageRead(uint32_t pagenum, SPIFlash &flash){

  Serial.print("Reading page starting at 0x");
  Serial.println(pagenum, HEX);

  for(int i = 0; i < 256; i++) {
    uint8_t value = flash.readByte(pagenum*256 + i);

    Serial.print(value, HEX);
    Serial.print(" ");

    if((i % 16) == 15) Serial.println(); // newline every 16 bytes
  }
}


void setup() {
  SPIFlash flash(10);                   
  //uint8_t            buffer[256];
  int                c, index      = 0;
  uint32_t           capacity =  1048576,
                     address       = 6,
                     bytesExpected = 591704,
                     bytesReceived = 0;


  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.begin(57600);
  Serial.println("HELLO");      // ACK to host

  // capacity = flash.begin();
  flash.begin();
  // Serial.println(capacity);     // Chip size to host
  // if(!capacity) error(250);     // Fast blink

  while(!Serial.find("ERASE")); // Wait for ERASE command from host
  // while(!flash.eraseChip());
  if(!flash.eraseChip()) {
    Serial.println("ERROR");
    error(500);                 // Slow blink
  }

/////////////////////////////////////////////////
  //write sample rate and guess expected bytes
  //hardcode sample rate and expected bytes on mcu floride
  // FlashWrite(flash, 0,62);
  // delay(300);
  // FlashWrite(flash, 1,128);
  // delay(300);
  // FlashWrite(flash, 2,0);
  // delay(300);
  // FlashWrite(flash, 3, 2); //0010
  // delay(300);
  // FlashWrite(flash, 4, 171); //10101011
  // delay(300);
  // FlashWrite(flash, 5, 152); //10011000

  // myPageRead(0, flash);

  /////////////////////////////////////////////////////
  Serial.println("READY");      // ACK to host

  for(;;) {
    if ((c = Serial.read()) >= 0) {
      if(FlashWrite(flash, address, c)){
        // digitalWrite(LED, HIGH);
        Serial.println('.');
        bytesReceived++;
        address++;
      }else{
        Serial.println('x');
        break;
      }
      // digitalWrite(LED, LOW);
      if((bytesReceived >= bytesExpected) || (address >= capacity)){
        break;
      }
      //delay(300); //do i still need this i forget
    }
    // if((c = Serial.read()) >= 0) {
    //   buffer[index++] = c;

    //   // Bytes 3-6 indicate number of samples to follow
    //   if(++bytesReceived == 6) {
    //     bytesExpected = (((uint32_t)buffer[2] << 24) |
    //                      ((uint32_t)buffer[3] << 16) |
    //                      ((uint32_t)buffer[4] <<  8) |
    //                                 buffer[5]      ) + 6;
    //   }

    //   if((index >= sizeof(buffer)) || (bytesReceived >= bytesExpected)) {
    //     if(flash.writePage(address, buffer)) {
    //       digitalWrite(LED, HIGH);
    //       Serial.print('.');
    //     } else {
    //       Serial.print('X');
    //     }
    //     address += sizeof(buffer);
    //     digitalWrite(LED, LOW);
    //     if((address >= capacity) || (bytesReceived >= bytesExpected)) break;
    //     index = 0;
    //   }
    // }
  }
  digitalWrite(LED,HIGH);
  delay(5000); //can i make this shorter
  myPageRead(10, flash);
  Serial.println("END_PAGE");
  delay(250);
  digitalWrite(LED,LOW);
}

void loop() { }

