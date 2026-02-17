## ECE445 Engineering Log #6

February 13, 2026\
Evan McGowan

Friday! I'm glad we did a lot of the proposal work yesterday because I really lack the time today.
Gayatri gave us a bunch of feedback on components, some of which we don't think are particularly necessary. One such example is the directionality of the signal.
Regardless of if we use a directional microphone or not, the microphone will only receive sound from the hole it's pointed through, as the microphone is contained inside the device.
The purpose of the detector is also to determine which bats are around, not necessarily where they are. Plus, we're capturing the echolocation signals. The device is incapable of tracking the bat's location.

This lends itself to the ethics concerns a bit as well, as we really still don't believe there are any. Unless someone is trying to transmit secret messages over the 15kHz-100kHz range, we're not really doing anything else.
It's important to note that this device is *just* a receiver, not a transmitter. If we were sending energy out, then I would believe some ethical concerns could surface as a result. This is also a very low-power device.

The battery life tolerance analysis should be adequate as well. The analysis example linked is simply a slightly different version of it, tracking maximum power draw from an array of LEDs.

Bill changed some of the block design too, making it slightly higher-level (removing 3.5mm audio jack as its own block, for example). Voltage levels were fixed, and some wire traces are now accurately drawn.

### SNR concerns

Another high-level concern Gayatri had was in the device's Signal-to-Noise Ratio, meant to quantify how amplified the signal is compared to the present background noise.
The plan is to pre-amplify the incoming ultrasonic signal and pass it through a passive high-pass filter with a bandwidth of 15kHz to suppress the baseband frequencies.
The signal is then mixed with our local oscillator to convert down to baseband, then amplified (somehow limit bandwidth?) to receive our output signal.
Using a multi-stage LC filter (design maybe something like https://k7mem.com/Fil_LC.html) should allow us to really filter out the baseband frequencies to achieve good SNR.
The battery-backed design may pose some problems in producing a high SNR, and to be safe, we're targeting 25dB as not to overpromise. I do believe that we should be able to reach higher levels.
I'm not very sure how to quantify the SNR we can get without starting the PCB design and solving the basic equations, which we plan to start at the beginning of next week, so hopefully one of these upcoming logs will contain those calculations.
That's it for today!
