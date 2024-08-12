#include <iostream>
#include "message_bus.h"
#include "test_comp.h"
#include "global_logger.h"
#include "tcp_listener.h"
#include "mac_global_listener.h"
#include "recorder.h"
// Want to create Event based Messaging threads
    // can publish and subscribe for events
// need some concept of Event
    // 
// event queue
int main(int argc, char* argv[])
{
    
    MessageBus& bus = MessageBus::Instance();
    Logger& log = Logger::Instance();
    std::shared_ptr<TestEvent> t1 = std::shared_ptr<TestEvent>(new TestEvent());
    t1->SetField(EventName::INT32_FIELD, -500);
    t1->SetField(EventName::DOUBLE_FIELD, 2.4212);
    t1->SetField(EventName::STRING_FIELD, "TestEvent1");
    std::shared_ptr<TestEvent> t2 = std::shared_ptr<TestEvent>(new TestEvent());
    t2->SetField(EventName::INT32_FIELD, -1000);
    t2->SetField(EventName::DOUBLE_FIELD, 5.533);
    t2->SetField(EventName::STRING_FIELD, "TestEvent2");

    bus.QueueEvent(t1);
    bus.QueueEvent(t2);
    bus.AddMessage(std::shared_ptr<MessagingThread>(&log));
    bus.AddMessage(std::shared_ptr<MessagingThread>(new MacGlobalListener()));
    for (int i = 0; i < 3; i++)
        bus.AddMessage(std::shared_ptr<MessagingThread>(new TcpListener(1234 + i, "TCPServer " + std::to_string(i))));
    bus.AddMessage(std::shared_ptr<MessagingThread>(new TestComp()));
    bus.AddMessage(std::shared_ptr<MessagingThread>(new Recorder()));
    bus.StartBus();
    
    Logger::Instance().LogMessage("yo");
    std::cout << "hello world" << std::endl;
}