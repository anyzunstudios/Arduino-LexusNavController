#include <SoftwareSerial.h>
#include <LexusNavController.h>

// RX=D8 (remote line), TX=NULL (unused)
SoftwareSerial navUart(8, NULL);
LexusNavController nav(navUart);

void setup() {
  Serial.begin(115200);
  navUart.begin(2400);

  // Same defaults as your working sketch: showHex=true, autoPrint=true
  nav.begin(/*showHex=*/true, /*autoPrint=*/true);

  // If you ever tweak: nav.setFrameTimeoutMs(40); nav.setDebounceMs(180);
  Serial.println(F("Minimal ready: 2400bps RX=D8, strict match, HEX ON"));
}

void loop() {
  nav.update();
  // Printing is handled by the library (exactly like your sketch).
  // If you prefer to decide when to print, call nav.setAutoPrint(false) and use example 02.
}
