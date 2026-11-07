
#include "Server.h"
void Server::Write_channel(Channel_id_t id, const SensorValue & data){
    switch (id)
    {
    case SPEED:
        speed_ch.write(data);
        break;
    case TEMP:
        temp_ch.write(data);
        break;
    case RPM:
        rpm_ch.write(data);
        break;
    default:
        break;
    }
}


Channel* Server::connect(Channel_id_t id){
    switch (id)
    {
    case SPEED:
        return &speed_ch;
    case TEMP:
        return &temp_ch;
    case RPM:
        return &rpm_ch;
    default:
        return nullptr;
    }
    
}