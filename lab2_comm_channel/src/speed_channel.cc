#include "speed_channel.h"
#include <iostream>

SpeedChannel::SpeedChannel():
    data{new float[max_size]},
    L_index{0},
    R_index{0},
    size{0} {}

SpeedChannel::SpeedChannel(const SpeedChannel &obj):
    data(new float[max_size]),
    L_index{obj.L_index},
    R_index{obj.R_index},
    size{obj.size}
{
        for(int i = 0; i < max_size; i++){
            data[i] = obj.data[i];
        }
}


SpeedChannel::~SpeedChannel()
{
        delete[] data;
}



void SpeedChannel::write(const SensorValue &val){
    if(!std::holds_alternative<float>(val)){
        std::cerr << "SpeedChannel value must be float\n";
        return;
    }
    if(size == max_size){
        // it is fulled
        std::cerr << "SpeedChannel full, value dropped\n";
        return;
    }
    if(R_index == max_size){
        R_index= 0;
    }
    data[R_index] = std::get<float>(val);
    std::cout << "SpeedChannel wrote " << data[R_index]<< std::endl;
    R_index++;
    size++;
}

SensorValue SpeedChannel::read(){
    if(size == 0){
        return std::monostate{};
    }
    if(L_index == max_size){
        L_index = 0;
    }
    float val = data[L_index];
    std::cout << "SpeedChannel read " << val << std::endl;
    L_index++;
    size--;
    return val;
}