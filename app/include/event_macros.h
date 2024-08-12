#ifndef EVENT_MACROS_H
#define EVENT_MACROS_H

#include "event.h"

#define BEGIN_NEW_EVENT(CLAZZ, NAME) \
class CLAZZ : public Event \
{ \
    public: \
        CLAZZ() : Event(EventName::NAME) { \
            mFieldsMap =  \
            { \
                {EventName::TIMESTAMP, std::string()},

#define ADD_FIELD(NAME, TYPE) \
    {EventName::NAME, TYPE},

#define END_NEW_EVENT() \
            }; \
        } \
        std::string GetName() override { return mName; } \
};
#endif