## ECE445 Engineering Log #1
January 23, 2026
Evan McGowan

Today’s focus was on the meeting.
We met with Joy O’Keefe, a bat biologist who’s been researching bats and their behavior for a while, coming to UIUC in 2020. Her goal for the project is to make an affordable bat detector that can be used on bat walks, an outreach event she holds a few times a year to make people more aware of those that cohabit Illinois. Current devices mostly stem from the UK and with tariffs/whatnot, it’s much harder for her to get her hands on them. Being able to make them on campus would greatly increase her ability to get detectors to groups for festivals, walks, etc.

We learned of a few different types of bat detectors (time expansion, FFT, heterodyne, zero-crossing, etc. consult Bill’s log) and multiple companies/open-source options for making this happen, especially the PiPistrell. We set a budget per device of around 50 USD, which should be very achievable. Heterodyne seems to be the way to go, it’ll be interesting to take apart the devices she donated for R&D purposes. I’d like to explore FFT functionality too.

Necessary features include tuning from 15kHz-100kHz, a speaker and (preferably good) microphone, and a tiny light to illuminate the dial/adjuster of choice. Volume too, can’t forget that. And batteries!! Low power consumption is ideal regardless of what power implementation we choose.
Features that would be nice to have: rechargeable batteries (USB-C), microSD storage for recording, 3.5mm audio jack, playback of pre-recorded bat tones through speaker to identify, weather-proofing.

Next steps are to draft up the idea for posting on the board, do some disassembly, and a bunch of research!
