#include <IRremote.h>
#include <IRremoteInt.h>


const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
decode_results last_ir;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  irrecv.enableIRIn();  // start the reciever 
}


void loop() {
  if (irrecv.decode(&results)) {
    switch(results.value) {
      case 0xA10CC40B:
      case 0xA10C840B:
        Serial.print("p"); // pause and play
        break;
      case 0xA10C240B:
      case 0xA10CA807:
        Serial.print("r"); // right and fast forward
        break;
      case 0xA10C440B:
      case 0xA10CE807:
        Serial.print("l"); // rewind and left
        break;
      case 0xA10C6807:
        Serial.print("d");  // down
        break;
      case 0xA10C2807:
        Serial.print("u");  // up
        break;
      case 0xA10C9807:
        Serial.print("s"); //select
        break;
    }
    irrecv.resume();
  }
}
