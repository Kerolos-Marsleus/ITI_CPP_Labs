#include "channel.h"
#include "Server.h"
#include "client.h"
#include <iostream>

int main(void){
    
    Server serv;
    Client c1(serv,SPEED);
    Client c2(serv,RPM);
    Client c3(serv,TEMP);

    serv.Write_channel(SPEED,5);
    serv.Write_channel(SPEED,50);
    serv.Write_channel(SPEED,500);
    serv.Write_channel(TEMP,6);
    serv.Write_channel(RPM,7);

    std::cout<< c1.listen() << std::endl;
    std::cout<< c1.listen() << std::endl;
    std::cout<< c1.listen() << std::endl;
    std::cout<< c2.listen() << std::endl;
    std::cout<< c3.listen() << std::endl;

    

    
}