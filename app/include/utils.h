#ifndef UTIL_H
#define UTIL_H
#include "boost/date_time/posix_time/posix_time.hpp"
namespace Utils
{
static inline uint64_t NowMilli()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

static inline std::string NowString()
{
        auto timeUTC = boost::posix_time::microsec_clock::universal_time();
        return to_iso_string(timeUTC);
}
}

#endif