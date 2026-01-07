#include "Arduino.h"
#include "config.h"
#include "MsgService.h"

void serialEvent();

String content;
MsgServiceClass MsgService;

bool MsgServiceClass::isMsgAvailable(){
    serialEvent();
    return msgAvailable;
}

Msg* MsgServiceClass::receiveMsg(){
    Msg* msg = currentMsg;
    resetMsg();
    return msg;
}

void MsgServiceClass::init(){
    Serial.begin(115200);
    content.reserve(256);
    resetMsg();
}

void MsgServiceClass::resetMsg(){
    currentMsg->setContent("");
    msgAvailable = false;
    content = "";
}

void MsgServiceClass::sendMsg(const String& msg){
    Serial.println(msg);
}

void serialEvent() {
    /* reading the content */
    while (Serial.available()) {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();
        MsgService.currentMsg->setContent(cmd);
        MsgService.msgAvailable = true; 
        content = "";     
    }
}

bool MsgServiceClass::isMsgAvailable(Pattern& pattern){
    return (msgAvailable && pattern.match(*currentMsg));
}

Msg* MsgServiceClass::receiveMsg(Pattern& pattern){
    if (msgAvailable && pattern.match(*currentMsg)){
        Msg* msg = currentMsg;
        resetMsg();
        return msg;  
    } else {
        return NULL; 
    }
}