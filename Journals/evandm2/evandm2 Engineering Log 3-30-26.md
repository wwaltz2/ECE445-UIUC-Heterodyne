## ECE445 Engineering Log #19

March 30, 2026\
Evan McGowan

Catch-up from last week:

Soldered one of the microphone boards using the stencil, kind of annoying with the soldering equipment that's in the lab, but whatever. Tested it on our breadboard and thankfully it works as expected! I set the oscillator to 40kHz and used the CAL setting on Dr. O'Keefe's ultrasound calibrator (centers at 40kHz), and was able to hear a low-frequency tone, indicating that our oscillator, microphone, microphone amplifier, mixer, AND audio amplifier all work as expected!!!! Very big success here, really happy with this.

Updated the bill of materials to include extra resistors that Bill needed for the digital part, and sent PCB rev 4 to Gayatri. I have no reason to believe that we'll need another design after this, only things may be adding bodge wires, but I doubt that's necessary.

![The round 4 PCB.](/Journals/evandm2/pcb_round4.png)

I also started working on the progress report last week, and came in today to grab oscilloscope traces to put in the report. Everything on my end is going very well. I'm leaving the soldering work for PCB v2 up to Bill/Kyle, and I may do some for the final iteration, but I don't feel like doing that with all the work I've done so far. I know they can handle it.

Soldered the remaining 4 microphones onto our breakout boards. Only 3/5 are working right now, but I think this will be more than enough for the rest of our project as long as nothing gets blown up.

Assorted pictures that I grabbed earlier today:

![Breadboard oscillator response for R = 248 ohms.](/Journals/evandm2/breadboard_oscillator.png)
![Frequency vs resistance data grabbed from multimeter + scope traces.](/Journals/evandm2/f_vs_r.png)
![Mixer operating with 52.3kHz and 52kHz input signals.](/Journals/evandm2/breadboard_mixer.png)
![High-frequency voltage ripple seen on our mixer output due to poor input isolation.](/Journals/evandm2/mixer_ripple.png)

