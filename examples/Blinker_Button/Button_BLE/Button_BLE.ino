#define BLINKER_BLE

#include <Blinker.h>
#include <Servo.h>

#define BUTTON_1 "ButtonKey"

BlinkerButton Button1(BUTTON_1);
Servo myservo;

void button1_callback(const String & state)
{
    BLINKER_LOG("get button state: ", state);

    if (state == BLINKER_CMD_BUTTON_TAP) {
        BLINKER_LOG("Button tap!");
    }
    else if (state == BLINKER_CMD_ON) {
        BLINKER_LOG("Toggle on!");
        myservo.write(165);
        Button1.print("on");
    }
    else if (state == BLINKER_CMD_OFF) {
        BLINKER_LOG("Toggle off!");
        myservo.write(15);
        Button1.print("off");
    }
    else {
        BLINKER_LOG("Get user setting: ", state);
    }
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
