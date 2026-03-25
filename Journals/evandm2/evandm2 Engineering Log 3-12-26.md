## ECE445 Engineering Log #16

March 12, 2026\
Evan McGowan

This log is being written after Spring Break, but has been added at this point in the chronology as not to clog up a singular entry after break.

Last log concluded with the second PCB revision going off to JLCPCB for approval. Now that we have a decently solid PCB under our belt, Bill has begun the firmware adventure. His logs will undoubtedly be more detailed than mine are, but many late hours were spent with a SparkFun RedBoard trying to break open the flash, having to rewrite some of the basic protocols. He was eventually successful with writing to our THT flash chip and reading back bytes, and uploaded a three-second soundbyte to the chip. The next step is to interface with our microcontroller and have the speaker play the audio!

I also bought a couple of USBasp programmers, and Bill contacted Dr. O'Keefe to get some sample bat calls. The third PCB has been sent in with some layout adjustments and a second ISP header. I forgot if anything else was changed.

Breadboard demo seems like it went well, but grades take forever to come out. I really wanted to show the flash and MCU handshake, but it just didn't get finished in time.
