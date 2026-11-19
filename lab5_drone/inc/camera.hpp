#pragma once
#include "ifeed.hpp"

class Camera :public IFeed
{
public:
    void activate()override;
    void deactivate()override;
    void playFeed();
};