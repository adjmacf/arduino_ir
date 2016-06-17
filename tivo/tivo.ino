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

    // if we recieve repeat code just change results to last used value unless it's somethings that we don't want to repeat a bunch
    // this is a bit of a hack and is kind of ugly
    if (results.value == 0xFFFFFFFF && 
        last_ir.value != 0xA10CC40B && 
        last_ir.value != 0xA10C840B &&
        last_ir.value != 0xA10C9807) {
      results = last_ir;
    }

   // if we detect pause or play
   if (results.value == 0xA10CC40B || results.value == 0xA10C840B) {
     Serial.print("p");
     delay(100);
   }

  // if we detect fast forward
  else if (results.value == 0xA10C240B || results.value == 0xA10CA807) {
     Serial.print("r");
   }

  // if we detect rewind
  else if (results.value == 0xA10C440B || results.value == 0xA10CE807) {
     Serial.print("l");
   }

  // if we detect channel down
  else if (results.value == 0xA10C6807) {
    Serial.print("d");
  }

  // if we detect up
  else if (results.value == 0xA10C2807) {
    Serial.print("u");
  }
  
  // if we detect select
  else if (results.value == 0xA10C9807) {
    Serial.print("s");
  }

   last_ir = results;
   irrecv.resume();
  }
}


