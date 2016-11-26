#include <Keyboard.h>

#include <IRremote.h>
#include <IRremoteInt.h>


const int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  Keyboard.begin();
  irrecv.enableIRIn();  // start the reciever 


}



void loop() {
  if (irrecv.decode(&results)) {
   Serial.println(results.value, HEX);
   if (results.value == 0xA10CC40B) {
     Keyboard.write(' ');
     Serial.write("p");
   }
   irrecv.resume();
  }
}


