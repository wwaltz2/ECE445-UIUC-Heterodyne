// Audio playback sketch for Adafruit Trinket.  Requires 3.3V
// Trinket board and Winbond W25Q80BV serial flash loaded with
// audio data.  PWM output on pin 4; add ~25 KHz low-pass filter
// prior to amplification.  Uses ATtiny-specific registers;
// WILL NOT RUN ON OTHER ARDUINOS.

#include <Adafruit_TinyFlash.h>

#if(F_CPU == 16000000L)
#error "Compile for 8 MHz Trinket"
#endif

Adafruit_TinyFlash flash;
uint16_t           sample_rate = 16000; //16kHz
uint16_t           delay_count;
volatile uint32_t  samples;
uint32_t           audioIndex[5];
uint8_t            data[4];
uint8_t            audioNum;
volatile uint32_t  index = 0L;
volatile bool      waiting = true;

void setup() {
  uint32_t bytes;
  audioNum = 0;
  
  audioIndex[0] = 0;
  audioIndex[1] = 134942;
  audioIndex[2] = 412466;
  audioIndex[3] = 670244;
  audioIndex[4] = 959050;

  

  // digitalWrite(3,HIGH);
  if(!(bytes = flash.begin())) {     // Flash init error?
    for(;; PORTB ^= 2, delay(250));  // Blink PB1 every halfsecond
  }
  // delay(2000);

  PLLCSR |= _BV(PLLE);               // Enable 64 MHz PLL
  delayMicroseconds(100);            // Stabilize
  while(!(PLLCSR & _BV(PLOCK)));     // Wait for it...
  PLLCSR |= _BV(PCKE);               // Timer1 source = PLL

  // Set up Timer/Counter1 for PWM output
  TIMSK  = 0;                        // Timer interrupts OFF
  TCCR1  = _BV(CS10);                // 1:1 prescale
  GTCCR  = _BV(PWM1B) | _BV(COM1B1); // PWM B, clear on match
  OCR1C  = 255;                      // Full 8-bit PWM cycle
  OCR1B  = 127;                      // 50% duty at start
  // digitalWrite(3,LOW);


  pinMode(4, OUTPUT);                // Enable PWM output pin

  TCCR0A = _BV(WGM01) | _BV(WGM00);  // Mode 7 (fast PWM)
  if(sample_rate >= 31250) {
    TCCR0B = _BV(WGM02) | _BV(CS00); // 1:1 prescale
    OCR0A  = ((F_CPU + (sample_rate / 2)) / sample_rate) - 1;
  } else {                           // Good down to about 3900 Hz
    TCCR0B = _BV(WGM02) | _BV(CS01); // 1:8 prescale
    OCR0A  = (((F_CPU / 8L) + (sample_rate / 2)) / sample_rate) - 1;
  }
  TIMSK = _BV(OCIE0A); // Enable compare match, disable overflow
  pinMode(3, INPUT); 
  cli();

}

void loop() {
  if(waiting){
    if(digitalRead(3) == LOW){
      cli();
      waiting = false;
      if(audioNum>3) audioNum = 1;
      samples = audioIndex[audioNum+1] - audioIndex[audioNum];
      pinMode(3, OUTPUT); 
      flash.beginRead(audioIndex[audioNum]);

      audioNum++; 
      sei();
    }
  }
}

ISR(TIMER0_COMPA_vect) {
  if(waiting) return;
  OCR1B = flash.readNextByte();      // Read flash, write PWM reg.
  if(++index >= samples) {           // End of audio data?
    index = 0;                      
    flash.endRead();
    cli(); 

    pinMode(3, INPUT);

    waiting = true;
  }
}

