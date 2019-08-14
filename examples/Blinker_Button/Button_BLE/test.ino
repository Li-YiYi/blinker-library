#include <Servo.h>
Servo servo;
void setup(){
    servo.attach(11);
}

void loop() {
    servo.write(20);
    delay(1000);
    servo.write(150);
    delay(1000);
}
