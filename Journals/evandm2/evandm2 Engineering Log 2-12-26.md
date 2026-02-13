## ECE445 Engineering Log #5

February 12, 2026\
Evan McGowan

The project proposal is due tomorrow at midnight, so I really wanted to get it out of the way if possible. Spent a lot of time today looking at datasheets and working on the bill of materials.
Multiple components that the E-Shop provides are now discontinued, and our ability to make a lasting product dwindles with that. The good thing is that our design doesn't look to be crazy expensive to manufacture, I'm guessing around $20.
Revised some subsystems, Bill will finish up the block diagram hopefully by tonight.


### The mixer problem
The SA612A mixer is a phenomenal mixer for the job, used by multiple hobbyists (and officially in the Magenta Bat4) to get the job of heterodyning done. Unfortunately, this component is now obsolete.
Worse yet, there are no good alternatives on the market. The NE602 is another good mixer that is out of stock, and the MC1496 requires a high input voltage in order to mix, making it less suitable for battery operation.
This leaves us with one other option: making our own oscillator and mixer. This is something I've only worked with in ECE453, and I've never had to understand op-amps well in design cases.
It should be an interesting challenge. Complete, open-source designs do exist online to make your own heterodyne module, but I'm extremely hesitant to copy from them.
This is a design that, ideally, is suitable to be sold as a standalone product, and making our own design would really help that case.
I remember a professor mentioning something during lecture about an excellent project that was ruined by lack of transparency.
The op-amp used in the Bat4, the TLV9052, should be adequate for our purposes. If it worked for them at 100kHz, it'll work for us. 

Tolerance analysis was kind of weird for this project, as it's hard to quantify the device functionality in ways other than length of operation.
I suppose something could be done about the frequency tolerance of the oscillator itself, but it doesn't feel important to do that. The battery life should be way more than enough to sustain a single bat walk.
Given that we'd need to draw over 500mA per hour to fail this requirement, which is absurd for something that uses low-power components, it should be trivial as the calculations have suggested.
