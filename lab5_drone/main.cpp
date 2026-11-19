#include "drone_control_station.hpp"
#include <memory>
#include "lidar.hpp"
#include "camera.hpp"
#include "mic.hpp"
int main(){
    DroneControlStation drone;
    auto lidar = std::make_unique<Lidar>();
    drone.registerFeed(std::move(lidar));
    drone.activateFeed();
    drone.viewFeed();
    drone.deActivateFeed();

    auto camera = std::make_unique<Camera>();
    drone.registerFeed(std::move(camera));
    drone.activateFeed();
    drone.viewFeed();
    drone.deActivateFeed();

    auto mic = std::make_unique<Mic>();
    drone.registerFeed(std::move(mic));
    drone.activateFeed();
    drone.viewFeed();
    drone.deActivateFeed();

}