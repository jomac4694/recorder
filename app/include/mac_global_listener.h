#include "ApplicationServices/ApplicationServices.h"
#include "messaging_thread.h"

class MacGlobalListener : public MessagingThread
{
    public:
        MacGlobalListener();
        ~MacGlobalListener() = default;
       // void SetContext(std::shared_ptr<IListeningContext> context) override;
        void HandlePlaybackStatus(EventPtr);
    protected:
        void Activate() override;
    private:
        static CGEventRef OnInput(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *userInfo);
        std::thread mListenThread;
        bool mPlaybackRunning{false};
        //std::shared_ptr<IListeningContext> mContext;
};