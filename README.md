# Dog AAC Board

## Description
A custom-built augmentative and alternative communication (AAC) board for dogs.

## Background
In late 2019, speech pathologist Christina Hunger (hungerforwords.com) went viral for her dog Stella's use of an AAC board. I had tried to build a similar keyboard for my dog two years earlier, but was unable to figure out how to teach the meaning of the buttons, and had shelved the project. After seeing [this video](https://www.instagram.com/tv/CGsS6CwhN0N/?utm_source=ig_web_copy_link) in particular, I was inspired to try again, now with the understanding that **consistent, constant modeling the use of the board** as we speak to our dog allows them to learn it naturally. 

## Design Considerations
I wanted a board that had a single speaker and a single power source, rather than relying on individual commercial buttons that each have to contain batteries, a microphone, and a tiny speaker. 
The audio from a single, larger speaker is much clearer and louder than the self-contained buttons can ever be. The individual buttons are also about $5-$6 apiece. I knew I wanted at least 36, which meant I was already in the $200 range even before the board itself or the batteries. At that price I could simply build my own system that would serve my purposes better.
I chose dimensions for my board that would allow it to be wall-mounted in a central hallway in my home. I made the board as large as I could fit (and that my dog could reach) so that I would have room to expand to as many as 80 buttons, since my dog already understood more than 300 spoken words. My board -- 31" W x 34" H button area, plus another 7" for a handle -- is quite large and a little cumbersome. Consider the spaces you have available where you and your dog will both be able to easily interact with the board, then size accordingly.

### Advantages vs. commercial buttons
* Single power source -- no hassling with batteries in each of 30+ buttons
* Large, clear speaker with adjustable volume
* Each button has a unique physical shape -- should be easier for everyone to learn
* No 'erase' button that can be [hit accidentally](https://www.instagram.com/p/B4vTTyXhjwK/)
* Less expensive (for >45 buttons)

### Disadvantages
* DIY build, requiring tools and many components
* Electronic expertise (wiring an arduino-like microcontroller, soldering pins, uploading firmware)
* Consumes power constantly, not merely when button pressed, so wireless time is limited to ~10 hours
* More up-front work, even if adding buttons over time
* More expensive (for <45 buttons)

## Components
**1/4" x 4' x 4' Birch Plywood** -- Sometimes called a *handy panel* or *project panel*, this is the foundation of the AAC board. [Menards #1254046](https://www.menards.com/main/building-materials/panel-products/handi-panels/4-x-4-birch-plywood-handi-panel/1254046/p-1444441905350-c-13337.htm) ($26.69)

**3/8" x 36" Square Dowel (x8)** -- These are the mounting point and fulcrum for the buttons. One is required for each row of buttons. [Menards #2152154](https://www.menards.com/main/doors-windows-millwork/dowels-wooden-pins-plugs/madison-mill-poplar-square-dowels/444864/p-1444438755016.htm) ($10.64 @ $1.33 ea.)

**#6 x 5/8" Wood Screws (x32)** -- Used for mounting the dowels to the plywood. Four per dowel. [Menards #2346267](https://www.menards.com/main/hardware/fasteners-connectors/screws/wood-screws/spax-reg-6-x-5-8-combo-drive-zinc-pan-head-wood-screw-50-count/4111010350162/p-1444423026591-c-8940.htm) ($2.22 for 50)

**#6 x 3/4" Pocket Hole Screws (x160)** -- Used for mounting the buttons to the dowels. Two per button. Pocket hole screws have an attractive cylindrical head and a portion of smooth (unthreaded) shank near the head. This smooth shank is important for allowing the button to rock freely without catching on threads. Most are square/Robertson drive. [Menards #2529956](https://www.menards.com/main/tools/power-tools-accessories/pocket-hole-jigs/kreg-reg-6-square-drive-zinc-fine-pan-head-pocket-hole-screws-100-count/sps-f075-100/p-1444437284600-c-10090.htm) ($10.64 for 200)

**Laminate Flooring Spacers (x80)** -- These spacers are rectangular, one half 2mm thick and the other half 5mm thick. These function as paddles when attached to the dowel. Wedge-shaped spacers would also work, but those usually are ridged and would be slightly less attractive. [Home Depot # 100052808](https://www.homedepot.com/p/SimpleSolutions-Laminate-Installation-Spacers-48-Pack-45176/100052808) ($24.54 for 96)

**Geometric Connecting Shapes** -- Colorful flat plastic shapes to make the faces of the buttons. I used a combination of [jumbo](amazon.com/dp/B01I0E58YA) ($28.98 for 96) and [small](https://www.orientaltrading.com/geometric-connecting-shapes-building-blocks-set-400-pc--a2-12_4337.fltr) ($19.99 for 400) shapes. The jumbo size are 2.5"-3.5" which makes a nice size for my dog to hit with her nose. The small shapes were useful for adding on and using in combinations to make each button unique.

**MX Keyboard Switches (x80)** -- These are the actual electrical switches that get wired up. They are attached to the board, and get depressed by the paddle-like spacer. I used [Gateron Greens](https://amazon.com/dp/B07X3WRCPH) ($34.99 for 90) for their higher resistance (80 gf) to being activated, but [Akko](https://amazon.com/dp/B07PFCVDPD) ($13.99 for 45) should work just as well. 

**10W Portable Speaker with Aux In** -- The speaker should be selected for minimal depth. The [Philips BT3500B/37](amazon.com/gp/product/B00J3O9DYI) I used is now discontinued, but works well and does not need to be used at max volume. One option is the [Philips BT2500B/37](
https://amazon.com/dp/B00J3O9YRY) ($19.99) which seems to be the smaller mono version, though it specifies only 3W RMS, so might not be loud enough. It is only 1.3" thick, like the one I used, which is a plus. An alternative is this [generic brand speaker](https://smile.amazon.com/dp/B07PJZRJ8X) ($12.27 using coupon) which claims to be 10W RMS and 1.8" thick.

**Power Bank** -- I used a 10,000 mAh power bank, but a 20,000 mAh would double the wireless time with only a minimal cost increase. A large, clear indicator on the face of the battery is a plus. Nearly all power banks have the two outputs we require. [20,000 mAh Power Bank](https://amazon.com/dp/B09CL7TQRX) ($15.99 using coupon) or this [Dog Paw Indicator Power Bank](https://amazon.com/dp/B07YCR7FR9) ($29.99) are good options.

**Teensy 4.1 Microcontroller and Audio Shield** -- I suggest the [presoldered](https://www.pjrc.com/store/teensy41_pins.html) ($32.60 without ethernet chip) Teensy just to save the effort soldering the header pins. The [audio shield](https://www.pjrc.com/store/teensy3_audio.html) ($13.75) is also required, and two [14x1 sockets](https://www.pjrc.com/store/socket_14x1.html) ($1.40) are recommended so that the shield and base board can easily plug together. Teensy provides this premade audio shield with a 3.5mm stereo socket and hardware support that makes playback of wav files straightforward. The base 4.1 board still has 18 pins available after attaching the audio shield, enough to support 81 buttons. You will need a [microSD card](https://amazon.com/dp/B07ZG93S5J) ($4.95) of some sort to store the sound files on - even an ancient one with a size measured in megabytes will be fast enough and large enough. You may want to buy [Dupont wires](https://amazon.com/dp/B09ZQFWRJJ) ($6.99), aka female jumper wires, to make connecting to the Teensy's pins easier. Finally, a [surface-mount project box, 4" x 2" x 2"](https://amazon.com/dp/B07S6PKW2L) ($6.17 using coupon) to contain the Teensy is also required.

**Short USB and 3.5mm stereo cables** -- USB power needs to run from the power bank ('regular' i.e. type A plug) to the Teensy (micro) and to the speaker (mini for the Philips, or micro for the Lenrue), using e.g. [1' USB Micro cables](https://amazon.com/dp/B09S3JSHZD) ($5.94 for 2). You will also need to be able to plug in the power bank (type C) to a power source (any usb charger or computer will work, 500 mA is sufficient). A [1' audio cable](https://amazon.com/dp/B06XF59XQK) ($2.44) runs between the Teensy and the speaker.

**French Cleat, 18" (optional)** -- If you want to wall-mount the board but still be able to easily remove it and use it wirelessly, a [French cleat](https://amazon.com/dp/B00FXPEPPI) ($11.54) is ideal. 


### Tools Required
* Saw -- for cutting board and dowels
* Drill, 1/16", 3/16", 3/4" [Forstner](https://www.menards.com/main/tools/power-tool-accessories/drill-bits-accessories/cmt-reg-forstner-drill-bit/537-190-31/p-1444426666543-c-10079.htm) or [Spade](https://www.menards.com/main/tools/power-tool-accessories/drill-bits-accessories/irwin-reg-speedbor-reg-4-spade-drill-bit/87912/p-1444436166861-c-10079.htm) bits -- for pilot holes, spacers, and keyboard switches respectively
* Philips and Robinson screwdriver heads
* Carpenter's square -- for true cuts and true dowel positioning
* Narrow (1/2") wood file or rasp, optional
* Pencil or fine-tipped marker
* Soldering iron, solder, 18-28 AWG hookup wire (I used 26), optionally 
* Hot glue, silicone glue, etc -- for attaching shapes to spacers
* [VHB tape](https://amazon.com/dp/B01BU7038A) -- very high bond foam tape for mounting powerbank and speaker. Alternatively, you can try Command adhesive or can drill keyhole slots into the housing of the speaker.
* Paint -- I suggest oil/enamel semi-gloss for durability and ease of cleaning.


## Assembly
![Board layout and dimensions: 3.125" from left edge of button to left edge of adjacent button, 3.75" from top edge of horizontal dowel to top edge of adjacent dowel](https://i.imgur.com/iVbYFM3.png)

### Board Construction

1. Evaluate where you will use the board and determine its maximum size. Determine the number of buttons you can fit in that space, allowing for 3 1/8" horizontal spacing and 3 3/4" vertical spacing and for room at the bottom to mount the power bank, speaker, and microcontroller. Keep in mind your dog's reach; my dog is more willing to stretch upward to hit high buttons than she is to crouch to hit low buttons. My board's button area is a 31"x31" square, which fits 10 buttons across in 8 rows, with additional height both above (for a handle) and below (to mount the electronic components). The software supports up to 255 buttons.

2. Cut board to desired shape and size, and dowels to matching width. Note: unlike illustration above, you probably want the dowels to come flush to the edge of the panel, so that you have room screw them down at each edge.
3. Measure and mark the positions for the dowels. On the dowels, measure and mark the positions of each 'paddle' (flooring spacer). Drill 1/16" pilot holes through the dowel in 4 positions: close to each outer edge, and two central positions unobstructed by paddles. Attach the dowels to the board using the 5/8" wood screws.
4. Drill two 1/16" holes along the short edge of the thin half of a spacer. Using this spacer as a template, mark the positions for two holes at every paddle position along the dowels. Drill 1/16" pilot holes at each of these positions, going through the dowel and plywood both. 
5. Using the template spacer, mark the position of holes on the remaining spacers (place them back to back so they are flush against one another). Drill these holes at 3/16". 
6. Test mount one paddle to a suitable position on the board. Preferably, choose a position that will be occupied by one of your initial buttons (simply so you don't end up with less attractive enlarged holes showing on a dowel afterward). You will want the keyboard switches centered on the thick part of the paddle; determine where that centerline is vertically using the attached paddle. Mark that line for that row of buttons, and measure and mark corresponding lines for the remaining rows. 
7. Mark hole positions for each keyboard switch, using the lines from step 6 and the position of the pilot holes for positioning left-right. Drill these holes at 3/4". 
8. Paint the board and allow 24 hours to dry. 
9. Insert the keyboard switches into each hole. The fit will be tight; the square profile of the switch does not quite fit into the hole at the corners. The plywood should yield enough to allow you to press-fit most of the switches. If necessary, use a file or rasp to enlarge the hole where the corners fit. The widest, flared part of the switch will sit flush atop the surface of the board. 
10. With all switches press-fit, hold the board horizontal and give several hard vertical shakes. If any keyboard switches fall out, reinsert them and secure with a little glue. 

### Board Wiring
The basic idea of the wiring is that they keyboard switches are connected in a mesh. One wire is used per row and per column, such that all the buttons in a given row share one wire in common, and all the buttons in one column share one wire in common.

1. Mark the location where the project box will be mounted to the board. With the project box in place, drill through its floor at one corner and on through the board. This is where the wiring of the keyboard buttons will enter the project box. 

2. Determine the maximum length of wire needed - it must span the entire width of the board, and must be able to reach from the far corner of the board to wherever the microcontroller will be sited, plus a little to spare. The width plus the longest diagonal plus 6" should be adequtate.
3. Cut one wire to that length to start; you may find you want to use many smaller wires instead of a few large ones.
4. Two alternative procedures:
	* Lay the wire across the first row of keyboard switches, with a few extra inches at one end (and a large excess at the other). Start at a keyboard switch near the center: strip about 3/8" of insulation from the wire at that position. Loop the exposed wire around one terminal on the keyboard switch and pull tight. Move to the next switch to the left or right and repeat, until the entire row is completed. 
	* If the insulation on your hookup wire is difficult to strip from the center of the wire in this manner, you will instead need to cut a short piece of wire, strip the ends, and wrap around a pin on two adjacent switches, then repeat until all switches are daisy-chained into a single electrically-continuous row. One of the keyboard switches at the end (or anywhere, technically) needs a longer wire connected that will run to the microcontroller.  
	* When either procedure is complete, all the keyboard switches in one row should be connected to each other on one pin, with the second pin on every switch unconnected to anything. There should also be a long length connected that will run to the microcontroller.
5. Solder the wrapped wires onto the pins.
6. Repeat steps 2-4 for each remaining row, and then each column of the board. 
7. If you elected to use Dupont wires, cut them so you have a short length of wire attached to the female socket, strip the end, and solder to terminate the long length of each wire.


### Teensy Software
1. Follow the Teensy [first-use tutorial](https://www.pjrc.com/teensy/first_use.html) to make sure it is working as expected. 

2. Install the Arduino and Teensyduino software for your operating system following the instructions on the [download page](https://www.pjrc.com/teensy/td_download.html). It's best to allow the installer to add all the included libraries. At a minimum, you must install the `Audio`, `Keypad`, and `SD` libraries. 
3. Download my [program](https://raw.githubusercontent.com/tofof/dog-keyboard/main/src/main.cpp) for the Teensy.
4. Determine which of the remaining pins on the Teensy you will use; one pin is required for each row and column. 
5. Edit [lines 35-36](https://github.com/tofof/dog-keyboard/blob/df448044fdddf9b8bd86df4d2e580c3ba55f3dbf/src/main.cpp#L35-L36) to correspond to the pins you have chosen to use. The pins must be named in order from top to bottom for the row pins, and from left to right for the column pins. 
6. Edit [lines 23-34](https://github.com/tofof/dog-keyboard/blob/df448044fdddf9b8bd86df4d2e580c3ba55f3dbf/src/main.cpp#L35-L36) to match the shape of your board. In particular, define `ROWS` and `COLUMNS` according to your board, then edit the array. The array should correspond dimensionally to your layout, and should uniquely number each button position. Mine specifies the numbers 10-19 for the first row, 20-29 for the second, and soforth through 89. 
Effectively, the column (0-9 in my case for 10 columns) specifies the ones digit, and the row (1-8 for 8 rows) specifies the tens digit. For example, *Help* is button 41 in the layout pictured below.
![Layout diagram showing that columns specify the ones digit from 0-9, and rows specify the tens digit from 10-80](https://i.imgur.com/pWoVYsR.png)

There are a couple of things to note. The numbers in the array are hexadecimal, which is why they are written as e.g. `\x41`. This means that the ones digit can actually span from 0-f, for 16 possible values, as can the 'tens' digit. However, **00 can't be used as a button identifier** for technical reasons (any button assigned to `\x00` will be nonfunctional). 
If needed, you can assign any 2-digit hexadecimal number to any position -- you don't *have* to treat the columns and rows as indices. For example, if you wanted a 25-column, 4-row layout, you could assign 01..0f..19 as the first row's values, and 1a..32 as the second row, etc.
7. Upload/flash the modified program to your Teensy. 
8. Record .wav files for each button. I used [TextToWav](https://download.cnet.com/TextToWav/3000-2169_4-10773719.html) to record the words using the Windows speech engine, after downloading an [alternative voice](https://superuser.com/questions/1020849/get-more-microsoft-text-to-speech-voices) to pronounce them. The filename must correspond to the button id. To use the previous example, the *Help* button, id `\x41`, corresponds to the file `41.wav`, which is a recording of a voice saying the word "Help." 
9. Copy the .wav files to the SD card (not in a folder, just directly on the drive) and install the SD card into the Teensy. Use the SD port on the base board, not the one on the audio shield.
10. Connect power and a speaker to the Teensy, then short a row & column pin together. The corresponding .wav file should immediately play.
If not, it's possible your SD card's access time is slower than expected. In that case, increase the value (milliseconds) on [line 89](https://github.com/tofof/dog-keyboard/blob/df448044fdddf9b8bd86df4d2e580c3ba55f3dbf/src/main.cpp#L89), reupload the program, and try again. If the value is already as high as 100 milliseconds and it's still not working, then there's a problem with your pin specifications, your connection between the Teensy controller board and the audio shield, or something else.

### Teensy Wiring
1. Solder the 14-pin sockets into place on the the audio shield. Pay attention to the numbering of the pins; they must align to the same-numbered pins on the Teensy 4.1 board. You will need to solder the socket to either the top or the bottom of the shield according to which side needs to be facing the corresponding pins on the Teensy controller. 

2. Plug the shield into the controller. 
3. Install the Teensy into the project box. Test fit the connections, then cut or drill holes for the audio cable, usb cable, and (optionally) access to the SD card. 
4. Bring the wires from the back of the board through the hole in the board and project box.
5. Plug in (or solder, if you did not elect to use Dupont wires) the wires to their pins, corresponding to the ones specified in lines 35-36 of the program.
6. Connect the Teensy to power and speakers and test the keyboard switch at a position corresponding to a .wav file; the audio should play.

### Final Steps
1. Screw paddles into place for every desired button using the pocket-hole screws and the previously-piloted holes. Don't screw them on so tightly that the paddles cannot move.

2. Glue geometric shapes onto the paddles. You may find it useful to let larger shapes cover the screws. 
	Keep in mind that dogs have dichromatic vision with Blue and Yellow-Orange cones; they cannot generally distinguish Red from Green, for example. It's best if you use combinations of the geometric shapes so that each button's shape is physically distinct from any other buttons. If you need to duplicate shape, it's best for those buttons to be placed apart from one another so that they can still be distinguished by position.
	None of this is absolutely essential, however -- dogs using commercial buttons distinguish them by position alone. 
3. Label the buttons for human understanding. I used a large-format labelmaker and affixed the labels below each button, on the surface of the board. Avoid trying to label the surface of the button itself since that will be prone to wear and tear. It also helps to use button shapes that encode meaning. For example, I use a red octagon for 'done', a long red oval cut in half and arranged into a heart shape for 'love you', a downward-facing triangle for 'downstairs', and a doubled right-facing triangle for 'ride'. 
4. Permanently affix the power bank and speaker using VHB tape or some other solution. I suggest plugging them in first, and letting the necessary cabling help inform your layout. 

Congratulations, your board should be ready to use!

Remember: the humans will be the only ones using it for at least the first month. Don't get discouraged! Your dog is learning by watching you.

## Resources
* https://www.hungerforwords.com/ -- Christina Hunger's website. Here are a couple of the most important ideas from it:
> Your dog will learn to use her buttons by seeing you use them. The more you talk to your dog using her buttons, the faster she’ll learn how to use them. Every time you hit one of her buttons, you are showing her how she can say that word too. This is called _modeling._ You are _modeling_ how and when to use each button by pushing it at the appropriate times. When you say “eat,” say it verbally and say it with her button before giving her food. Before you go outside, say “outside” verbally and say it with her button. Every time you are saying a word to your dog that she has a button for, you should be saying it both verbally **and** with her button. This is called _aided language input_ and is one of the most important strategies for teaching language with AAC.

> The first words I introduced to Stella were “outside”, “play”, “water”, and “walk.” Beginning words should be highly motivating and frequently occurring for your dog to learn best.

* https://how.theycantalk.org/c/home -- A community website for people using AAC boards with their pets. It includes discussions of useful words, beginner lessons, forums, etc.
