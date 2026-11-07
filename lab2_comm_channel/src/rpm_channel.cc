#include "rpm_channel.h"
#include <iostream>

RPMChannel::RPMChannel():
    data{new int[max_size]},
    L_index{0},
    R_index{0},
    size{0} {}

RPMChannel::RPMChannel(const RPMChannel &obj):
    data(new int[max_size]),
    L_index{obj.L_index},
    R_index{obj.R_index},
    size{obj.size}
{
        for(int i = 0; i < max_size; i++){
            data[i] = obj.data[i];
        }
}


RPMChannel::~RPMChannel()
{
        delete[] data;
}



void RPMChannel::write(const SensorValue &val){
    if(!std::holds_alternative<int>(val)){
        std::cerr << "RPM value must be int\n";
        return;
    }
    if(size == max_size){
        // it is fulled
        std::cerr << "RPMChannel full, value dropped\n";
        return;
    }
    if(R_index == max_size){
        R_index= 0;
    }
    data[R_index] = std::get<int>(val);
    std::cout << "RPMChannel wrote " << data[R_index]<< std::endl;
    R_index++;
    size++;
}

SensorValue RPMChannel::read(){
    if(size == 0){
        return std::monostate{};
    }
    
    if(L_index == max_size){
        L_index = 0;
    }
    int val = data[L_index];
    std::cout << "RPMChannel read " << val << std::endl;
    L_index++;
    size--;
    return val;
}