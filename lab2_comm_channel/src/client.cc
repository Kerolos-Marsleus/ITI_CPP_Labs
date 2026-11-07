#include "client.h"


void Client::reconnect(Server &s,  Channel_id_t id){
    channel_ptr = s.connect(id);
}

SensorValue Client::listen(){
    if(channel_ptr == nullptr){
        return std::monostate{};
    }
    return channel_ptr->read();
}

Client::Client(Server &s, Channel_id_t id): channel_ptr{s.connect(id)}
{

}

