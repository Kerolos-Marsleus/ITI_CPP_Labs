#pragma once
#include "icomm_bus.hpp"
#include <vector>

class DataProvider{
    private:
        std::vector<ICommBus*> m_bus;

    public:
        void add_bus(ICommBus& bus);
        void broadcast(int data);
};