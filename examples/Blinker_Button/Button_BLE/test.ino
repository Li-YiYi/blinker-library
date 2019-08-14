#include <Servo.h>
Servo servo;
void setup(){
    pinMode(11, OUTPUT);
    servo.attach(11);
}

void loop() {
    servo.write(20);
    delay(1000);
    servo.write(150);
    delay(1000);
}
