#include <SoftwareSerial.h>
#include <LexusNavController.h>
// RX=D8 (remote line), TX=NULL (unused)
SoftwareSerial navUart(8, NULL);
LexusNavController nav(navUart);

// Example custom code (replace with a real one)
const uint8_t MY_NEW_CODE[] = {0x01,0x02,0x03,0x04};

void setup() {
  Serial.begin(115200);
  navUart.begin(2400);
  nav.begin(true, true);

  // Add a new pattern with a custom ID (>=100 recommended for user space)
  nav.addPattern("MYBTN", MY_NEW_CODE, sizeof(MY_NEW_CODE), 100);

  Serial.println(F("AddCustomButtonCode ready."));
}

void loop() {
  nav.update();
  // Library will auto-print on match; to handle yourself:
  /*
  LNR_Button btn;
  if (nav.poll(btn) && btn == (LNR_Button)100) {
    Serial.println(F("MYBTN detected"));
  }
  */
}
