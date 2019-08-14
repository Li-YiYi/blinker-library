#define BLINKER_BLE

#include <Blinker.h>
#include <Servo.h>

#define BUTTON_1 "ButtonKey"

BlinkerButton Button1(BUTTON_1);
Servo myservo;

void servopulse(int angle){
    int pulsewidth=(angle*11)+500;  //将角度转化为500-2480的脉宽值，每多转1度，对应高电平多11us     digitalWrite(servopin,HIGH);    //将舵机接口电平至高
    digitalWrite(11,HIGH); 
    delayMicroseconds(pulsewidth);  //延时脉宽值的微秒数
    digitalWrite(11,LOW);     //将舵机接口电平至低
    delayMicroseconds(20000-pulsewidth);
}    

void button1_callback(const String & state)
{
    BLINKER_LOG("get button state: ", state);

    if (state == BLINKER_CMD_BUTTON_TAP) {
        BLINKER_LOG("Button tap!");
    }
    else if (state == BLINKER_CMD_ON) {
        BLINKER_LOG("Toggle on!");
        Button1.print("on");
        myservo.write(165);
        Blinker.delay(25);
    }
    else if (state == BLINKER_CMD_OFF) {
        BLINKER_LOG("Toggle off!");
        Button1.print("off");
        myservo.write(15);
        Blinker.delay(25);
    }
    else {
        BLINKER_LOG("Get user setting: ", state);
    }
}

void setup()
{
    //Serial.begin(115200);
    //BLINKER_DEBUG.stream(Serial);

    pinMode(11, OUTPUT);

    Blinker.begin(0,1);
    Button1.attach(button1_callback);
    myservo.attach(11);
}

void loop()
{
    Blinker.run();
}
