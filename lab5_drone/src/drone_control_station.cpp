#include "drone_control_station.hpp"
#include "lidar.hpp"
#include "mic.hpp"
#include "camera.hpp"
#include <iostream>
void DroneControlStation::registerFeed(std::unique_ptr<IFeed> feed)
{
    ptr = std::move(feed);
}

void DroneControlStation::activateFeed()
{
    if (ptr)
    {
        ptr->activate();
    }
}

void DroneControlStation::deActivateFeed()
{
    if (ptr)
    {
        ptr->deactivate();
    }
}

void DroneControlStation::viewFeed()
{
    if (Lidar *lidar = dynamic_cast<Lidar *>(ptr.get()))
    {
        lidar->scanEnv();
    }
    else if (Camera *camera = dynamic_cast<Camera *>(ptr.get()))
    {
        camera->playFeed();
    }
    else if (Mic *mic = dynamic_cast<Mic *>(ptr.get()))
    {
        mic->playSound();
    }else{
        std::cerr << "Invalid type\n";
    }
}