## ECE445 Engineering Log #16

March 24, 2026\
Evan McGowan

Senior design escapades have continued, and this entry also accounts for things that went on yesterday.

Bill is working on the logic to choose between digital audio playback and microphone audio, which seems rather annoying to implement with the limited I/O we have on the ATTiny85. His journal entry will most likely be more detailed on this than mine will, as I am entrusting him with that part of the process. This logic has been added to the schematic, and our PCB has been redesigned to allow for this additional logic. He has also made audio playback fully functional on our flash memory module.

Kyle has been working on the chassis design, but there isn't a ton to do there until we finalize our PCB design and have all our knobs in the right place and whatnot. He's got it easy!!

As the analog "guru" or whatever you would say, I've finally fixed up that portion of our project. The oscillator has always worked just fine, but getting it to mix with an input waveform has been problematic in the past for unknown reasons. There isn't a ton to comment on here, as the design I proposed initially was the one we should have been using this whole time. And it started working for no apparent reason...but now we can successfully mix down to baseband frequencies and hear it!!

Our audio amplifier also never drew all that much current, but a simple fix (I had put a wire in the wrong place...of course) means that we now draw over 100mA of current, and our speaker is more than capable of blasting audio, which is excellent news. I need to take a look at the adjustable gain stage tomorrow, as I didn't have time to do that today. That will likely be the final change before our PCB is shipped off.
