#include "channel.h"
#include "Server.h"
#include "client.h"
#include <iostream>

void print(const SensorValue& v);

int main(void){
    
    Server serv;
    Client c1(serv,SPEED);
    Client c2(serv,RPM);
    Client c3(serv,TEMP);

    serv.Write_channel(SPEED,5.f);
    serv.Write_channel(SPEED,50.f);
    serv.Write_channel(SPEED,500.f);
    serv.Write_channel(TEMP,6.0);
    serv.Write_channel(RPM,7);

    print(c1.listen());
    print(c1.listen());
    print(c1.listen());
    print(c2.listen());
    print(c3.listen());
  
}


void print(const SensorValue& v){
    if(const int* p = std::get_if<int>(&v)){
        std::cout << *p << "\n";
    }else if(const float* p = std::get_if<float>(&v)){
        std::cout << *p << "\n";
    }else if(const double* p = std::get_if<double>(&v)){
        std::cout << *p << "\n";
    }else{
        std::cout << "NO Data\n";
    }
}