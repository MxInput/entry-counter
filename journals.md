# Entry Counter Build Journal

## Jul 17, 2026, 5:42 AM

I added a OLED and connected it to the ESP32 and breadboard, however, when I try to use micropython I keep getting errors when I attempt to import libraries which I think is an error, so next I'll try to go back to C++ and see if that works.

---

## Jul 17, 2026, 6:39 AM

I switched back to C++, but had still was struggling with displaying text on the OLED since most instructions were about displaying sketches, eventually though, I did find one that told me how I was supposed to create text.

---

## Jul 17, 2026, 6:57 AM

I connected the motion sensor to the ESP32 and I initially had a small issue with it detecting multiple entries from a single interaction, however, I fixed this by placing a delay when a motion is detected. In the future, I may change it to millis if it interrupts the rest of the program, but for now it's effective.

---

## Jul 17, 2026, 7:47 AM

I tried adding a button to the program that would reset the number of entrants, however, I think I ran into a bug where the button keeps acting like a switch and stays stuck even after being released. I'll try to mess around to see if it's a self issue, but I think it's just an error.

---

## Jul 17, 2026, 8:04 AM

I added the buzzer so now the system greets the entrant by playing a sound. I still haven't been able to figure out the issue with the buttons like if it is a problem with the program or an issue with the code. I'll keep checking but if I don't notice anything then the project may be finished.