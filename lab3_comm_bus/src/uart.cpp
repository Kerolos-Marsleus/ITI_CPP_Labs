#include "uart.hpp"
#include <iostream>

void Uart::send(int data){
    std::cout << "In UART : " << data << "\n";
}