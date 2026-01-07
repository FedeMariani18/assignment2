#ifndef __MESSAGE_TASK__
#define __MESSAGE_TASK__

#include "kernel\Task.h"
#include "kernel\MsgService.h"
#include "model\Context.h"
#include "model\ContextAlarm.h"


class MsgManagerTask: public Task{

public:
    MsgManagerTask(Context& context, ContextAlarm& contextAlarm, Command& command, double& distance);
    void init(int period) override;
    void tick();

private:
    void receive();
    void send();
    Command transformMsgToCommand(Msg* msg);

    Context& context;
    ContextAlarm& contextAlarm;
    Command& command;
    double& distance; 
};

#endif