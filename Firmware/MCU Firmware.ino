//Sketch for MCU-Flash Audio Player
//Cycling through 5 on-board audio files
//new file on each button press

// #define MOSI PIN_PB0
// #define MISO PIN_PB1
// #define SCK PIN_PB2
// #define RST PIN_PB5

// might be unneccessary ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#include <Adafruit_TinyFlash.h>

#define AUDIO_EN PIN_PB3
#define MCU_OUT PIN_PB4

// #if(F_CPU == 16000000L) // from Adafruit_TinyFlash TrinketPlayer.ino - this is for 8MHz, we want 16MHz?
// #error "Clock Speed Error" // what is the clock speed of our MCU?
// #endif

// /////////////////////////////////////
Adafruit_TinyFlash flash; // from Adafruit_TinyFlash TrinketPlayer.ino
uint16_t           sample_rate, delay_count;
uint32_t           samples;
volatile uint32_t  index = 0L;
// /////////////////////////////////////

uint8_t audio_index;
uint8_t file[4] = {0, 0x020000, 0x040000, 0x060000};

void setup() {
    uint8_t data[6];
    uint32_t bytes;

    if(!(bytes = flash.begin())) {
        //some sort of error message
    }
    
    flash.beginRead(0);
    for(uint8_t i=0; i<6; i++) data[i] = flash.readNextByte(); // bytes 0-1 = sample rate
                                                               // bytes 2-5 = number of samples // how does this apply to several different samples?
    sample_rate = ((uint16_t)data[0] <<  8) |  (uint16_t)data[1];
    samples     = ((uint32_t)data[2] << 24) | ((uint32_t)data[3] << 16) | ((uint32_t)data[4] <<  8) |  (uint32_t)data[5];

    //Phase Locked Loop Control and Status Register = PLLCSR
    //PLLE = Phase Locked Loop Enable
    PLLCSR |= _BV(PLLE);
    delayMicroseconds(100);
    while(!(PLLCSR & _BV(PLOCK))); // PLOCK = ????
    PLLCSR |= _BV(PCKE);

    //setting up timer for PWM output
    TIMSK  = 0;
    TCCR1  = _BV(CS10); 
    GTCCR  = _BV(PWM1B) | _BV(COM1B1);
    OCR1C  = 255;
    OCR1B  = 127;

    pinMode(AUDIO_EN, INPUT); //necessary?
    // enable internal pullup
    digitalWrite(AUDIO_EN, HIGH);
    pinMode(MCU_OUT, OUTPUT); //make sure pin PB4 is pin 4?

    audio_index = 0;
}

void loop() {


    if (digitalRead(AUDIO_EN)==LOW){
        digitalWrite(AUDIO_EN, LOW); // is this terrible form

        //do sound play
        flash.beginRead(file[audio_index]+6);
        

        digitalWrite(AUDIO_EN, HIGH);
        audio_index++;
        audio_index = audio_index % 4; // or however many files we got
    } else {
        digitalWrite(AUDIO_EN, HIGH);
    }

}

ISR(TIMER0_COMPA_vect){
    OCR1B = flash.readNextByte();
    if(++index >= samples) {
        index = 0;
        flash.endRead();
        flash.beginRead(6);
    }
}