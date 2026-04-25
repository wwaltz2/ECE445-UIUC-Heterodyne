## ECE445 Engineering Log #22

April 23, 2026\
Evan McGowan

Excellent troubleshooting progress today. Still a lot to do before I'm comfortable, but did a ton. Gayatri said there's a good chance that if we can explain *why* things are going wrong in our circuit, we will do just fine in the demo. We'll have a working breadboard, at least. Everything on there has been tested...but the analog audio output leaves some to be desired as I'll discuss below.

On the analog side:
Determined that our oscillator and microphone were fully functional, with the microphone being able to peak at 6V. However, still having trouble getting output to the speaker and even into the audio amplifier. Until I had a realization out of nowhere! What if it's because our bias voltage was too high?

Our op-amps are biased around 3.3V to allow for relative positive and negative voltages, but this means we have a different ground reference between the op-amps and the audio amplifier. The LM386N-1 audio amplifier has an expected maximum input of +/- 0.4V, and we're feeding it with 2-4V. This seemingly explains why the speaker would only play audio through a very small range of our 10k potentiometer, as it was dropping to acceptable input voltages for a tiny resistance range. I tested that this was the case by using a waveform generator set to 1Vpp (frequency 300Hz, not super important), to provide an input to the audio amplifier. It worked for an offset of 0V, but going up to 3.0V yielded no audio output at all. I tried using a simple voltage divider to bring the voltage swing down, but I wasn't very successful. Might look into making a 3v3 to ground level shifter. I don't know if this is even possible or viable. More research to do!

I also determined that the device doesn't turn off. If the switch is off while the barrel jack is unplugged, the device is off. But if it's plugged in and turned on, it cannot be turned back off. The 6V test point that we have onboard goes from 6V to around 2.7V. (Just about 3.3V difference...) I have no leads as to why this might be happening, as there shouldn't be another path for current to flow. Making the switch on the Vreg ENABLE pin may have been a better call, especially because the audio amplifier doesn't turn off either. It's connected directly to 6V. Another thing to fix for future use.

Our digital audio is biased around that zero-voltage point (aka our true ground, board ground), which means that it should operate just fine. The CANS switch, which controls when audio is switched from analog to digital, was changing by 0 to 0.01V instead of 0 to 3.3V. It was always held low, so the audio output never switched. Removing a resistor, R25, on the 5V to 3.3V voltage divider Bill used for ensuring that the flash memory (which has a maximum input voltage of 3.6V) meant that the button no longer had a constant path to ground, and CANS is now operational. The flash also seems to be communicating with the MCU just fine, which is a relief. It wasn't flashing on-board, which might be due to those resistors. Hard to tell now, though. The audio output from the MCU looks the way it should on an oscilloscope, but passing through the resistors on the way to the CANS-controlled electrical switch is causing some other issues, like pulling the output to 5.3V, above where the digital logic should ever be operating. Definitely need to do some work there, really hard to tell what's going on. Might desolder the switch and make some manual connections to confirm. The switch could be on the wrong way, it was hard to see where the dot on the IC was.

We also did our mock presentation and got some great feedback.

* Add figures to all diagrams
* Talk a bit more
* Fewer words in each slide, no bullet points with full sentences
* Dumb down diagrams heavily. No schematics
* Fewer words on the flowchart, make it horizontal
* Table of contents
* Nothing about tariffs or overseas shipping, lol
* Future directions and improvements
* Software tests/verification
* One slide each for oscillator and mixer verification
* For me specifically: prepare for question about how op-amp oscillator works

Update later in the evening: I went back to the lab for a couple of hours to continue troubleshooting. I removed the IC that switches between digital and analog audio, seems that it was defective or something. The analog part was interfering with the digital audio output, so once it was removed, I was able to hardwire the digital audio to our audio amplifier and hear the bat call that Bill uploaded to the flash memory successfully. Shorting R24 and removing R25 (resistors that were meant to be voltage dividers) made the digital audio output possible in the first place, so that's good to note.

The mixer was still not working, but I investigated the PCB and found that the traces to a capacitor were wired incorrectly. After severing some traces and putting down bodge wires, the mixer works! I verified its operation with the waveform generator and oscillator set to 40kHz, yielding this:
![Mixer output on our PCB.](/Journals/evandm2/PCB_mixer.png)
Time-domain response and FFT are shown, indicating a separation of 20dB from the mixed-down frequency and the 40kHz input signals. Isolation could be further improved by using a higher-order low-pass filter, but we did not include this in our design, believing it would be good enough as the higher-frequency signals can't be heard anyway. This does worsen battery life, though.

Things that are left to fix:

- Power never truly turning off without hard disconnect
- Mixer level shift, analog audio might not pass into amplifier
- Analog/digital switch soldering + troubleshooting
- Load more bat calls onto device (not particularly necessary though)
