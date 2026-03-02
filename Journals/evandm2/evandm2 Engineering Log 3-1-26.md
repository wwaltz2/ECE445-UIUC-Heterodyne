## ECE445 Engineering Log #13

March 1, 2026\
Evan McGowan

Quick note: realized that the MISO and MOSI lines on our PCB were backwards, so I swapped them to be correct. Our PCB will need this modification made to it before we can test anything on the MCU side. The analog portion is unaffected.

Spent from 6-9PM in the lab today to begin constructing our breadboard for demo next week. We have all of the major parts we need already for this, the microphone + amp module we procured from the lab cabinet will need to be looked into further, though. I spent the beginning making sure our voltage regulator worked, then set up the MCU and audio amplifier minus the buttons (reset & audio enable). Our LM3940IT regulator seems to function at 6V properly, converting down to a clean 3.3V.

The next while was spent setting up the oscillator module, as its operation is essential to the function of the rest of the circuit. I had some initial problems, but it turned out that one of the chips we found in the self-service had a busted op-amp. Swapping it out yielded a rounded square wave, which an LC low-pass filter was placed on just to remove the frequencies above 100kHz.

![Circuit diagram of our oscillator module for the heterodyne bat detector.](/Journals/evandm2/spice_oscillator.png)

| Resistance (Ω) | Frequency (kHz) |
| ------------- | ------------- |
1.17k | 8.5
1.07k | 9.6
0.89k | 11.1
0.75k | 12.2
0.53k | 14.5
0.47k | 15.4
0.41k | 17.3
0.29k | 20.4
0.24k | 22.0
0.16k | 28.1
0.11k | 36.5
0.1k | 38.3

Values within 20Ω and 100Hz.

This range of frequencies is not even close to our expected values, which are plotted below. I didn't check the capacitors or resistors for their true values, but something else may be going on here. Breadboard capacitance was also unaccounted for.

[plot of stuff]

The magnitude of the output signal begins to reduce drastically upon reaching 22kHz or so. My first thought is that the op-amp doesn't have the same wide frequency response that we should be able to get out of the TLV9054. The unity gain bandwidth is stated to be 1MHz, and figure 7 in [this datasheet](https://www.ivytechengineering.com/info/stores/linear/files/lm348.pdf) indicates a dropoff of 20dB/decade. The UGB of the TLV9054 is 5MHz, so we'll see how this works out for us.
After testing this down the road, we may choose to forgo an oscillator module and procure an adjustable oscillator IC that can perform this task with greater certainty. This will be discussed with Gayatri, as it would decrease the complexity of the project a bit. The good news is that the current draw of the circuit (regulator, LED, power to MCU & flash, one op-amp) is only 20mA!
