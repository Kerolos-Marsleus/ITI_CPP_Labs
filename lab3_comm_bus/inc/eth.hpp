#pragma once
#include "icomm_bus.hpp"
class Eth : public ICommBus{
    public : 
        void send(int data) override;
};