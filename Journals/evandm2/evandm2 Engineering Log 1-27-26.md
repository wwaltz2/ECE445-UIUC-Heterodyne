## ECE445 Engineering Log #2

January 27, 2026\
Evan McGowan

Today was a lot of R&D! Before lecture, we spent a lot of time updating our RFA to get it up to speed.
Many initial decisions made.

MCU has been decided to be the ATTiny85. It's the highest-spec of the series, and we really don't need anything greater. An ESP32 would be rather overkill, we are using the ATTiny primarily for processing the audio files. On that note, we needed to decide which format of storage to use. Using an ESP would allow us to store the audio onboard in RAM, but it won't be necessary to change anything. The current idea is to use flash storage, which should be flashable the same way we do the ATTiny. TBD if we can use an Arduino to flash, that method will be determined and we need to talk to a TA to see if that's allowed.

We learned today that a transducer includes microphones! Looking for ultrasonic transducers yields more results than we would have otherwise. Results around the web seem to vary on which transducers are 
The PiPistrell is open-source, we'll take a look at what microphone is installed.

I initially thought of making a mixer and oscillator circuit myself, but the Magenta Bat4 includes the SA612A, which apparently works up to 500MHz. I guess they work well at low frequencies too! The amplifier portion will have to be done by hand as circuits like this can be very dependent on use. A bunch of research is in order, but much of it should be simpler than working at very high frequencies. Standard op-amps weren't very difficult to find, and the TLV9052 was present on the Bat4, which likely places it as a good option.
