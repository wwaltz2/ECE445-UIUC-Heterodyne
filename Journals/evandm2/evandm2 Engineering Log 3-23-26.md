## ECE445 Engineering Log #17

March 23, 2026\
Evan McGowan

Bill went into the lab today and was successful in getting our audio sample to play through the speaker! Turns out MISO and MOSI were flipped on some schematic he saw, or something like that. Either way, it is technically functional now. It's incredibly quiet, and the volume knob for the potentiometer blows it out immediately, which seems very wrong. Work to be done tomorrow there, as we'll be doing our redesign tomorrow afternoon while we meet with Gayatri.

Bill and I also discussed whether we should use THT flash memory, since we are already using a THT MCU (the ATTiny85). I'd like to not have a header for the flash memory at all, and have it programmed off-board with some intermediate devboard. However, I have no idea if that's sufficient for the project scope, as one of the guidelines for PCB approval is whether we have programming headers on our PCB or not. For our cases, flash is going to be a one-time thing, so I feel that flashing off-board is reasonable for our project scope. Will have to discuss this with Gayatri, though. It adds size and a tiny bit of cost to our design, but may be unavoidable. Also, the devboard usually outputs 5V and the logic level of the flash is 3v3, so voltage divider resistors are necessary as well...It'd be nice if we didn't have to worry about this, but per Bill's suggestion, we're keeping them on the board and we can choose not to populate those footprints if we find it to be unnecessary.
