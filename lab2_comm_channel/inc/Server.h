#ifndef SERVER_H
#define SERVER_H

#include "rpm_channel.h"
#include "speed_channel.h"
#include "temp_channel.h"

typedef enum {
    SPEED,
    TEMP,
    RPM,
    NUM_OF_TYPES
}Channel_id_t;

class Server{
    private:
        RPMChannel rpm_ch;
        SpeedChannel speed_ch;
        TempChannel temp_ch;


    public: 

        void Write_channel(Channel_id_t id, const SensorValue & data);
        Channel* connect(Channel_id_t id);
};


#endif