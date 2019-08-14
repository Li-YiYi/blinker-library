#define BLINKER_BLE

#include <Blinker.h>
#include <Servo.h>

#define BUTTON_1 "ButtonKey"

BlinkerButton Button1(BUTTON_1);
Servo myservo;

void button1_callback(const String & state)
{
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    BLINKER_LOG("get button state: ", state);
    if(state = "on"){
        myservo.write(165);
    }
    elif(state = "off") {
        myservo.write(165);
    }

    Button1.print(state);
}


void setup()
{
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);

    pinMode(9, OUTPUT);
    Blinker.begin();
    Button1.attach(button1_callback);
    myservo.attach(9);
}

void loop()
{
    Blinker.run();
}
