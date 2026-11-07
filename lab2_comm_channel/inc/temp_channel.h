#ifndef TEMP_CHANNEL_H
#define TEMP_CHANNEL_H
#include "channel.h"



class TempChannel : public Channel{
    private:
    double* data;
    int L_index;
    int R_index;
    int size;
    static constexpr int max_size = 2;
    public:
        TempChannel();
        TempChannel(const TempChannel &obj);
        TempChannel& operator= (const TempChannel &obj) = delete;
        ~TempChannel();

        void write(const SensorValue &val) override;
        SensorValue read() override;
};




#endif /*TEMP_CHANNEL_H*/