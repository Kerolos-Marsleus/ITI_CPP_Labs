#pragma once
#include <memory>
#include "ifeed.hpp"
class DroneControlStation{
    private:
        std::unique_ptr<IFeed> ptr;

    public:
        void registerFeed(std::unique_ptr<IFeed> feed);
        void viewFeed();
        void activateFeed();
        void deActivateFeed();
};