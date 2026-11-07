#ifndef SPEED_CHANNEL_H
#define SPEED_CHANNEL_H
#include "channel.h"



class SpeedChannel : public Channel{
    private:
    float* data;
    int L_index;
    int R_index;
    int size;
    static constexpr int max_size = 2;
    public:
        SpeedChannel();
        SpeedChannel(const SpeedChannel &obj);
        SpeedChannel& operator= (const SpeedChannel &obj) = delete;
        ~SpeedChannel();

        void write(const SensorValue &val) override;
        SensorValue read() override;
};




#endif /*SPEED_CHANNEL_H*/