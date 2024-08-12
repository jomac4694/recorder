#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include "messaging_thread.h"

typedef std::ostream* stream_ptr;

class Logger : public MessagingThread
{
    public:
        Logger();
        Logger(const std::string& file_path);

        ~Logger();
        static Logger& Instance();
        void LogMessage(const std::string& message);
        void HandleLogMsg(EventPtr e);
    protected:
        void Activate() override;
    private:
        stream_ptr mStream;
        std::mutex mStreamSync;
        bool mDelete{false};
};

#define LOG(MESSAGE)    \
    Logger::Instance().LogMessage(MESSAGE);
#endif