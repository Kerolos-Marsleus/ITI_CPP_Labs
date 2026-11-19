#pragma once
#include "ifeed.hpp"

class Mic :public IFeed
{
public:
    void activate()override;
    void deactivate()override;
    void playSound();
};