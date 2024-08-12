#ifndef TCP_LISTENER_H
#define TCP_LISTENER_H
#include "messaging_thread.h"

class TcpListener : public MessagingThread
{
    public:
        TcpListener(const uint16_t port, const std::string& name);
        ~TcpListener();
     //   void HandleTestEvent(EventPtr event);
        void Listen();
    protected:
        void Activate() override;
    private:
        std::thread mListenThread;
        uint16_t mPort;
        std::string mName;
};


#endif