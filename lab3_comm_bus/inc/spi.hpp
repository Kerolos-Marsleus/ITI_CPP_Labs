#pragma once
#include "icomm_bus.hpp"
class Spi : public ICommBus{
    public : 
        void send(int data) override;
};