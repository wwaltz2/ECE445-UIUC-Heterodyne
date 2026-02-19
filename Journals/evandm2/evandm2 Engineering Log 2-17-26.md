## ECE445 Engineering Log #9

February 17, 2026\
Evan McGowan

Had our weekly meeting with Gayatri today, progress seems to be fine. We were warned about aspects of the project that might come under greater scrutiny, which was helpful.
Examples included the battery life being a high-level requirement, ethical concerns and whether there really were any, and such. We all still believe that the project doesn't harbor any major concerns.
Additional work into creating the modules began today, and I imported a TLV9052 model into LTspice to see if I could get any meaningful results out of it.
Op-amp oscillator module research hasn't been very lucrative, falstad and various online resources have been used but not to much avail.
A sine wave generator (linked in the next log) seems promising, but I cannot for the life of me get the oscillator to function one bit.
It also doesn't help that we're powering the op-amp with +6V and ground, so something needs to be figured out there.

Bill started on the audio amplifier module but I haven't gotten around to checking it yet.
[This paper](https://invensense.tdk.com/wp-content/uploads/2015/02/Op-Amps-for-MEMS-Microphone-Preamp-Circuits.pdf) was used to set up our initial circuit, a very simple design.
Adding filter stages is tempting, and I may mess around with this tomorrow. Really need to get moving for PCB review on Friday.
