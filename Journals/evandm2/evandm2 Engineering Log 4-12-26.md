## ECE445 Engineering Log #20

April 12, 2026\
Evan McGowan

More catching up. Keep forgetting to write logs, oops.

Bill soldered part of the round 2 PCB without using the stencil, which is suicide in my opinion with those tools. Unsurprisingly, it did not work. Attempted to reflow with no luck, don't think it got hot enough. This was right before the progress demo, so we were hoping to have something on our PCB to show there. We didn't, but the demo went alright. Prof. Fliflet recommended testing the device by using the calibrator in the hallway to see how far away we can still get a signal from, which would definitely be a good idea. He also recommended having a fuse on the device, which seemed unnecessary for our use case, especially since round 4's PCBs have already been ordered.

This afternoon, I went into the lab with my soldering equipment and got everything on the board except the headers (and thus the things attached to those, like the microphone, speaker, switches, potentiometers, etc.) and powered it on to see that the oscillator module is fully functional! Tunes from 15kHz to 115kHz. The microphone isn't in yet, but the mixer doesn't seem to be working, and I currently have no idea why. Need to do some extra troubleshooting, but at least part of the device works now. The digital section isn't implemented yet, so still some work to do there. No audio output without bodge wires either so far, and we don't have a volume knob anyway.

In the near future, we will be printing a chassis prototype and iterating from there. Bill will finish up the code, and I need to buy the Molex headers for use on our PCB. Good progress, but getting a little too close for comfort. I'm sure most groups are, to be fair.
