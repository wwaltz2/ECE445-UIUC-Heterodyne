## ECE445 Engineering Log #7

February 14, 2026\
Evan McGowan

Parts ordering is due by tomorrow evening, it seems. This is a good opportunity to explain the reasoning behind the components we've chosen for our design thus far.
Let's break it down by module, aided by Bill's block diagram.
![Diagram of our basic device design for the heterodyne bat detector.](/Journals/evandm2/block_diagram.png)

### Bat Call Demo Module

In order to play pre-recorded audio, we need an IC that can receive that audio and play it upon request. This is the main purpose of our microcontroller for the project. No fancy extra requirements like WiFi/Bluetooth/etc are necessary for the device's operation, as it is mainly an analog device. The ATTiny85 was chosen as our microcontroller of choice due to its strong support and low cost. Low power consumption gives us better battery life for our design, which we will be trying to maximize as much as possible.

The device's internal flash of 8kB doesn't provide us enough space to store our audio, so external memory is required. Flash memory was chosen over EEPROM so we can program the flash directly from our microcontroller. We settled on the W25X40CL flash memory chip, which has 4Mb (Megabits) of storage and uses SPI for data transfer. Using audio with a bitrate of 320kbps allows us 12.5s of audio. We will likely use a lower bitrate, possibly dependent on the microcontroller's transfer speed. To be determined. For prototyping (as the W25X40CL is not through-hole), we settled on the SST25VF080B chip, with the only important changes being that the clock rate is half as fast, and its use of an 8-pin DIP package for easy prototyping.


### Power Supply

Many battery-powered bat detectors on the market use disposable batteries, and our device is no exception. Rechargeability was not a focus of our design, so we chose to stick with 4 AA batteries. This provides us with a hefty amount of input voltage and the ability to run our device at high load for more than one bat walk (1-2 hours). The limiting component in our design is the audio amplifier (discussed later), which does not provide consistent operation below 4.5V, so using three batteries was out of the question. A 9V battery stepping down to 3.3V for the microcontroller and other components would waste much more power, so we settled on our four 1.5V batteries. According to the Duracell MN1500's datasheet, we can source up to 500mA from the batteries for two hours without dropping below our total voltage of 4.5V, adequate for our use case. We won't be sourcing this much power anyway, so the battery life *should* last much longer.

A voltage regulator is necessary to drop our device from 6V to 3.3V for steady operation of multiple components, and the AP2212K does this for us, sourcing up to 600mA. Not really much to say here, both our surface-mount and through-hole regulators were chosen for their availability in the E-Shop. For prototyping, we settled on the LM3940IT, which has an operation range of 4.5-5.5V, but for mere prototyping, it should hopefully be okay to overrun it with 6V for testing purposes. Worst case, we hook our regulator up to a power supply that supplies 5V if the thing blows up.


### Audio Output

The audio amplifier we chose is the LM386N-1, once again chosen for its E-Shop availability and reliability, as shown in multiple hobbyist bat detectors. The device operates on 4V-12V for amplification, so it will be hooked up directly to the battery source, perhaps with a current limiting resistor in series to ensure that the battery doesn't burn out too fast. It provides voltage gains in a range of 20-200, plenty for amplifying our down-converted audio signal. The gain is adjustable via a resistor, so a potentiometer may be placed in-circuit to act as a volume dial.

The Taoglas SPKM.23.8.A, with its terrible datasheet and all, is a fine speaker for our use case. There isn't too much to say about it, but its impedance of 8 Ohms may require some extra matching to take place. Maybe I'll put that ECE453 impedance matching knowledge to use after all.

### Heterodyne Module

The big module, there is much to write about here. WIP
