# clean-image

A short C++ program stolen from code for Computer Vision. The goal was to
clean up a picture of a signature by grayscaling it and then flushing very
light-colored pixels to be white, so it would blend in with a white
background.

The results are in `signatures.jpg` and `signatures_cleaned.jpg` in the
Sponsorship folder, though you need to convert to `ppm` and from `pgm` to
use the program.

Of course, you can probably figure out how to do this with an image editing
program such as [LunaPic](http://www.lunapic.com/).


