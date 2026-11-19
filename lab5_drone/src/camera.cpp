#include "camera.hpp"
#include <iostream>

void Camera::activate(){
    std::cout << "Activate Camera\n";
}
void Camera::deactivate(){
    std::cout << "Deactivate Camera\n";
}

void Camera::playFeed(){
    std::cout << "Playing feed Camera\n";
}