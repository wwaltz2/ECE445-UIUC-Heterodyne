## ECE445 Engineering Log #23

April 26, 2026\
Evan McGowan

We're basically done! Everything is pretty much fixed.

I realized that our switch (the TS5A3159 SPDT) was being fed with 3v3 for the supply voltage, which means that the switching inputs could only go up to that value. I soldered on a new one, as I think the old one got busted, and fed it with 6V.

The last issue to solve was the mixer output. As discussed in the previous log, the output had to be grounded the same way that the audio amplifier was. This required a level shift. After consulting some sources, I learned that we can just use a capacitor for DC blocking, which makes perfect sense! Only the AC signal will pass through, and this shifts our signal from 5-6V down to 0-1V. This made our analog output operational over the whole tuning range for volume, the same as the digital audio. 

Now that we could tune over our whole volume dial instead of the digital working fine and analog only working for a tiny range of the potentiometer output, I needed to test the range of the microphone. Using our calibrator, I was able to hear the output from a distance of 10ft. To properly test how this compares to the Magenta Bat4, we'll need to repair one of Dr. O'Keefe's units and run the same distance test, seeing how loud the output is.

Other than that, the only things to do are finish up the presentation, start the final report, print out requirements for demo, and put the device in the chassis. Almost there!
