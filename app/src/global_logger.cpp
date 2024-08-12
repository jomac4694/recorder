#include "global_logger.h"
#include <iostream>
#include <fstream>
#include "boost/date_time/posix_time/posix_time.hpp"

Logger::Logger() : mStream(&std::cout)
{
    auto cb = std::bind(&Logger::HandleLogMsg, this, std::placeholders::_1);
    RegisterEvent(cb, EventName::LOG_EVENT);
}
void Logger::HandleLogMsg(EventPtr e)
{
  //  auto timeUTC = boost::posix_time::microsec_clock::universal_time();
    std::lock_guard<std::mutex> lock(mStreamSync);
    auto p = boost::posix_time::from_iso_string(e->GetField<std::string>(EventName::TIMESTAMP));
    *mStream << to_iso_extended_string(p) << " " << e->GetField<std::string>(EventName::LOG_MSG) << std::endl;
    mStream->flush();
}

Logger& Logger::Instance()
{
    static Logger logger; //("/Users/josephmcilvaine/cpp_cmake_template/build/logs.txt");
    return logger;
} 

Logger::Logger(const std::string& file_path) : 
    mStream(new std::ofstream(file_path, std::ios::app))
{
    mDelete = true;
    auto cb = std::bind(&Logger::HandleLogMsg, this, std::placeholders::_1);
    RegisterEvent(cb, EventName::LOG_EVENT);
}

Logger::~Logger()
{
    if (mDelete)
    {
        delete mStream;
    }
}

void Logger::Activate()
{

}

void Logger::LogMessage(const std::string& message)
{
    auto t1 = make_event_ptr<LogEvent>();
    t1->SetField(EventName::LOG_MSG, message);
    SendEvent(t1);
}