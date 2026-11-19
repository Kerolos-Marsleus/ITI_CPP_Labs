#pragma once
#include "icomm_bus.hpp"
class Uart : public ICommBus{
    public : 
        void send(int data) override;
};