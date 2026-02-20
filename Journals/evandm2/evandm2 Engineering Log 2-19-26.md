## ECE445 Engineering Log #11

February 19, 2026\
Evan McGowan

One day until PCB review, really have to get moving.

### Mixer Module
I realized that the op-amp "mixer" I created doesn't really act as a mixer; it just adds the two signals together.
I have no idea how the element14 video managed to perform signal mixing this way, but we had to find an alternate method.
After a bunch of searching, I realized that the op-amp approach wasn't going to yield any results, and we had to either use a discrete chip or make a diode-based mixer. An op-amp is present in the final design anyways to ensure that the output signal is amplified before heading to the audio amp.
The diode mixer generates a range of spurious frequencies, but these can be easily filtered out, as we are only interested in producing a low-frequency signal, not a clear tone.
A simple RC low-pass filter with cutoff frequency 338Hz (1uF & 470Ohm) seemed to do the trick, creating a decent output tone when viewed in LTspice.

![LTspice circuit and output for the mixer module, with two input signals of 60kHz and 61kHz mixing to create a 1kHz tone.](/Journals/evandm2/mixer_output.png)

Some high-frequency ringing is still present, but the amplitude is much lower, and the speaker may not even pass these tones.
This module isn't based on a particular design; I modeled it based on what I learned in ECE453 and researched in PHYS401.

So, why not use a double-balanced mixer for greater rejection of input tones? Well, I figured that adding more diodes increases our voltage drop and thus power dissipation, making the circuit less efficient. It also simply shouldn't be necessary for our design, adding unnecessary complexity to something that we'd like to be simple. 
If it is, we will simply come back and adjust the design for our second PCB once we've learned what went wrong.

### Oscillator Module

Falstad's sine wave generator didn't seem to be doing the trick, so we modeled our oscillator after a standard relaxation oscillator.
This only produced a square wave, which presents problems for filtering out higher frequencies.
Regardless, an RC low-pass filter with a cutoff frequency of ~160Khz (1nF & 1kOhm) should remove the really high-frequency components. 
The mixer down-converts to such a low frequency that our 300Hz cutoff should take care of any higher values, and it appears to do so from our final result.
This will require some additional testing once we build our PCB to dial in those numbers, but we'll get there. Tolerances on the 22nF and 4.7nF capacitors also have to be very tiny, as a change of even 1nF puts us out of our expected range.
The 22nF is the important one for having careful tolerance, so we might need a slightly more expensive part for that.

![LTspice circuit and output for the oscillator module. Varying R1 from 0 Ohms to 1k Ohms creates a frequency range of 14kHz-101kHz.](/Journals/evandm2/oscillator_output.png)

I've linked a [Google sheet](https://docs.google.com/spreadsheets/d/19D7xuHpkfHNgXeAT1FNqbCoquvycCeivdWV6eoiyZKc/edit?usp=sharing) for showing my research on what values work.
Using the simple f = 1/(2pi*RC) doesn't seem to work here (maybe internal capacitances/resistance?), so I chose to experimentally calculate with the op-amp model we'd be using.
I anticipate some component adjustments will need to be made, but it's all part of the process.

These SPICE files have been added to the GitHub repository.

### PCB design

Everything for the schematic has effectively been finished by this point. We assigned the footprints for each component based on what the E-Shop had readily available, though we will need to buy multiple passives online to ensure we have the right values (and tolerances) for operation. It turns out that the MEMS microphone we bought has a standard footprint online, though the pad numbers don't match what we have on the schematic, so I'll need to adjust that. Bill started organizing each subsystem to get ready for the review tomorrow, and as long as we have things looking like they're in the right place, we should be good. Team contract will also be submitted tomorrow, finally.
