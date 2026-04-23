## ECE445 Engineering Log #21

April 22, 2026\
Evan McGowan

Even more catching up! Most of the days in April were nothing and then I got smacked with a bunch of work to do, mainly because I was waiting on the Molex connectors. Didn't want to solder wires to the PCB when we could get our connectors in there nice and snug, which ended up putting us a few days back. USPS also delivered to the wrong address, making us lose another day. Such is life.

Chassis revisions #2 and #3 have been made, with the main differences being that the switch and button have a better-defined hole. The barrel jack on the edge of our PCB hits the side of the case, so for fitting it into our final design, we're gonna have to solder the battery holder wires directly to those spots. 

Bill did a ton of crimping this afternoon, and I got every connector onto the board. Every single component is now on the board which, in theory, means everything should be working! Right?
I wish. 

Bill flashed the MCU successfully but the external flash memory we have isn't being recognized by the Arduino that we're using for flashing. I have no idea why this is, especially since I've been way less involved with the software part, but all of the connections continuity test just fine on our board. The digital audio output is not working, even after we swapped the unflashed memory with a pre-flashed IC that Bill took care of the day before and confirmed was working. The issue seems to be on the PCB side of things, and my suspicion that swapping out the flash with a pre-flashed chip would make no difference was confirmed.

The microphone works just great but is lacking greatly in the amplification department, may need to up the feedback resistance to increase this. It's at 33k/3.3k, so just a gain of 10. The oscillator is 4.5V peak-to-peak where I'm getting some hundreds of millivolts out of the amplified microphone signal. This may be interfering with the mixing process, as I'm not getting any results from that either. The oscillator signal makes its way through, but no mixing seems to occur. Given that our final demo will probably be on Monday, this gives us four days to fix these two issues...they could be big, or could be solved super quickly. I don't know!

Oh yeah, the power switch doesn't turn the device off. I clearly overlooked some part of the design that's allowing current to flow. Hopefully it's as simple as having a diode with the wrong polarity. We also have our mock presentation tomorrow, gotta work on the slides for that.
