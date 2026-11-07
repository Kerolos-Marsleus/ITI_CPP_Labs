#ifndef RPM_CHANNEL_H
#define RPM_CHANNEL_H
#include "channel.h"



class RPMChannel : public Channel{
    private:
    int* data;
    int L_index;
    int R_index;
    int size;
    static constexpr int max_size = 2;
    public:
        RPMChannel();
        RPMChannel(const RPMChannel &obj);
        RPMChannel& operator= (const RPMChannel &obj) = delete;
        ~RPMChannel();

        void write(const SensorValue &val) override;
        SensorValue read() override;
};




#endif /*RPM_CHANNEL_H*/