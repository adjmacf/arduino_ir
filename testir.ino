#include <IRremote.h>
#include <IRremoteInt.h>


const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  irrecv.enableIRIn();  // start the reciever 
}


void loop() {
  if (irrecv.decode(&results)) {
   if (results.value == 0x20DF5DA2 || results.value == 0x20DF0DF2) {
     Serial.write("p");
   }
   irrecv.resume();
  }
}


