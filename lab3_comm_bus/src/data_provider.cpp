#include "data_provider.hpp"

void DataProvider::add_bus(ICommBus& bus){
    m_bus.emplace_back(&bus);
}
void DataProvider::broadcast(int data){
    for(ICommBus * bus : m_bus){
        bus->send(data);
    }
}