#include "lidar.hpp"
#include <iostream>

void Lidar::activate(){
    std::cout << "Activate Lidar\n";
}
void Lidar::deactivate(){
    std::cout << "Deactivate Lidar\n";
}

void Lidar::scanEnv(){
    std::cout << "ScanEnv Lidar\n";
}