## ECE445 Engineering Log #24

April 27, 2026\
Evan McGowan

Reworked our RV table for demo on Wednesday, such that we can actually test things. We had stuff about mixing from 15-100kHz, but we can't do that without using a waveform generator, which isn't necessary for the demo. I confirmed with Gayatri that this was okay to adjust, so that's good. Meeting with Dr. O'Keefe tomorrow to show her our product!

Barrel jack has been removed so the PCB can fit in our case. Otherwise, it'd be sticking out the side very weirdly. Important change for a future iteration of the device; horizontal space was limited, but we have plenty of vertical space.

I also finally looked at why our PCB was always on when the batteries were connected! Turns out that the 6V trace to the rest of the circuit (aside from the 3V3 line) is connected before the switch, so the op-amp and audio amplifier are always on. Oops. Now that it's fixed, we should be perfect for the demo on Wednesday if we get the Bat4 working to compare ranges.
