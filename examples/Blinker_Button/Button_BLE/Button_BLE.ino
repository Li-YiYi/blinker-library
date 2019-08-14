#define BLINKER_BLE

#include <Blinker.h>

#define BUTTON_1 "ButtonKey"

BlinkerButton Button1(BUTTON_1);


void servopulse(int angle){
    int pulsewidth=(angle*11)+500;  //将角度转化为500-2480的脉宽值，每多转1度，对应高电平多11us
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
        for(int i=0;i<50;i++)
        {
          servopulse(165);
        }   
    }
    else if (state == BLINKER_CMD_OFF) {
        BLINKER_LOG("Toggle off!");
        Button1.print("off");
        for(int i=0;i<50;i++)
        {
          servopulse(15);
        }   
    }
    else {
        BLINKER_LOG("Get user setting: ", state);
    }
}

void setup()
{
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);

    pinMode(11, OUTPUT);

    Blinker.begin();
    Button1.attach(button1_callback);
}

void loop()
{
    Blinker.run();
}
