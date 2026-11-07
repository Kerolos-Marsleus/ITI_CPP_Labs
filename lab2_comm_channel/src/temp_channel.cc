#include "temp_channel.h"
#include <iostream>

TempChannel::TempChannel():
    data{new double[max_size]},
    L_index{0},
    R_index{0},
    size{0} {}

TempChannel::TempChannel(const TempChannel &obj):
    data(new double[max_size]),
    L_index{obj.L_index},
    R_index{obj.R_index},
    size{obj.size}
{
        for(int i = 0; i < max_size; i++){
            data[i] = obj.data[i];
        }
}


TempChannel::~TempChannel()
{
        delete[] data;
}



void TempChannel::write(const SensorValue &val){
    if(!std::holds_alternative<double>(val)){
        std::cerr << "TempChannel value must be double\n";
        return;
    }
    if(size == max_size){
        // it is fulled
        std::cerr << "TempChannel full, value dropped\n";
        return;
    }
    if(R_index == max_size){
        R_index= 0;
    }
    data[R_index] = std::get<double>(val);
    std::cout << "TempChannel wrote " << data[R_index]<< std::endl;
    R_index++;
    size++;
}

SensorValue TempChannel::read(){
    if(size == 0){
        return std::monostate{};
    }
    if(L_index == max_size){
        L_index = 0;
    }
    double val = data[L_index];
    std::cout << "TempChannel read " << val << std::endl;
    L_index++;
    size--;
    return val;
}