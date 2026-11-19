#pragma once
#include "ifeed.hpp"

class Lidar :public IFeed
{
public:
    void activate()override;
    void deactivate()override;
    void scanEnv();
};