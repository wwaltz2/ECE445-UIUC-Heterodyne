## ECE445 Engineering Log #9

February 18, 2026\
Evan McGowan

We met up today to continue working on the schematic and to start the team contract. This was pretty easy to write, not too much to talk about here. The bulk is in continuing schematic design.

Bill had the idea yesterday to create a positive and negative bias for the circuit by simply using +3V3 as our ground reference, allowing us to set the op-amp maximums as +2.7V and -3.3V.
This allows us to produce a sine wave, but the oscillator design we've found (can be found on https://falstad.com/circuit, as an example circuit) doesn't work for me in LTspice.
I'm inclined to find another source as a result, and [this TI example circuit](https://www.ti.com/lit/wp/snoa839/snoa839.pdf?ts=1771335803606) seems like it may work well, but requires two resistors to be adjusted.
The goal is to utilize the last two onboard op-amps and use one potentiometer to tune the frequency from 15kHz to 100kHz, this is our last major hurdle. Additional work needs to be done here.

I tried adjusting the pre-amp to have a better frequency response (steeper rolloff at 3dB frequency), but didn't have much luck in adding additional phases without really messing up the module's phase response.
I've been convinced that it should work just fine for a first iteration, and if something goes wrong in our testing, we can always go back to the drawing board and look further into adding phases.
Now that I think about it, our current design has the filter before the amplifier, which is the opposite of what we intended to do. That will need to be fixed.
*reason for this is that every operation will add its own noise; amplifying THEN filtering allows us to remove some of that extra noise, in theory.

The audio amplifier has been set up according to the data sheet, with a trimpot in-circuit allowing us to adjust the gain anywhere from 20 to 200 (26dB-46dB). This could be a useful debugging tool, so I'm including it just in case.

Lastly, the microcontroller now has two jumpers on the extra I/O pins in case we need to utilize the CS and WP pins on the flash memory chip. Once again, mainly for debugging, which I expect we'll need to do with the first iteration.
Multiple testpoints have been added through the analog circuitry (though we have to be careful with which parts we probe, given that we have two ground references) for the same purpose.

I had an op-amp mixer set up and ran it through LTspice before realizing that it was just a summing circuit, and that creating an actual mixer might be slightly more involved.
Hopefully, only one op-amp is needed for this, and if not, some transistors may need to be used to make a Gilbert cell or something. If only the SA612A was in stock, then we would have a lot less work to do here.
I suppose it adds to the project's complexity and isn't insurmountable. This has become more of an analog design project than a microcontroller one, which I personally have no problem with.

One other thing I want to mention before I end this log is that I'm a bit worried about what's considered copying of work.
Many of the circuits throughout our design process (mixer, oscillator, inverting amp, etc.) are simple enough that they are indistinguishable from already-existing circuits that are being sold in market products.
This is something I'd like to talk to the TA or a professor about, as it's something that Dr. O'Keefe would consider having produced, and if it becomes a market product, we'll be under heavier scrutiny.
Need to determine how we protect against accusations of stealing and whatnot, as I have no idea what to do there.
