## ECE445 Engineering Log #15

March 3, 2026\
Evan McGowan

Today started out with the design review, which I believe we did really well on. Only points to note are that we forgot to add the demo module as a high-level requirement (Prof. Fliflet said it would be a better requirement than battery life, which I can definitely see), and something else that I honestly forgot. Gayatri will send out an email with notes covering everything.

After our review, I spent the morning troubleshooting the oscillator module. The GBP (gain-bandwidth product) of the op-amp we were using seemed limited, so I swapped the LM348N for the MC34074P. Slew rate might have been the real culprit or a combination of the two, but I'm unsure, and it doesn't particularly matter now that it's working.
The oscillator works perfectly now! Adding a high-impedance stage (unity gain non-inverting) by using another one of the op-amps greatly decreased the effect of the rest of the circuit on the oscillator, so we are now using all four onboard op-amps.
As for what I mean when I say the oscillator works perfectly, the amplitude no longer decreases drastically upon reaching higher frequencies, and I didn't have to adjust the capacitance & resistance to different values to get the desired behavior. The 26.7nF and 100-1100 ohm range puts us from 14kHz-109kHz, just as expected!

After 454 lecture, I came back to lab to put the rest together and have our quick meeting with Gayatri. I got the go-ahead for making multiple PCBs, so the mic module was to be modeled later. Everything is now wired according to the diagram we have, but I can't get the mixer to operate properly on our breadboard. I had it working once, but I have no idea how. I get a very weird output that looks like multiple high-frequency sinusoids superposed on each other instead of a low-frequency sinusoid. I'm really hoping we can use the single unbalanced diode mixer in the end, as it'd make the design so much easier to implement. The LTspice simulations still work perfectly fine, and I've set them up on the board exactly as they are in simulation, but no luck yet. Definitely have some additional work to do here.
One more thing here--I set up the MAX9814 Adafruit microphone, which seems to work pretty well for low frequencies, but does pretty poorly once you get above 15kHz.

Bill has started preliminary work on the MCU, pretty much leaving that to him and Kyle. Kyle's also set up Autodesk Inventor (back to high school freshman year!) to model our board. I'll have him mess around with that for a while and try out different designs once we have a general shape figured out. The main work to do now is in storing audio in the flash memory and retrieving it, and that's totally out of my wheelhouse, so I'll be staying pretty hands-off with that.

This evening, I finished up the PCB. An electronic switch between the analog and flash audio has been implemented, and the mic has been separated into its own board. I redid the top half of the PCB to put the analog circuitry in a better spot, and it ended up looking pretty nice. I'll relax on the analog part of things for a couple of days since I've been doing so much work. We should be in a good spot for the breadboard demo on 3/9 as long as they get the digital portion of our design working.

![Second round PCB for our Heterodyne Bat Detector project.](/Journals/evandm2/pcb_round2.png)
