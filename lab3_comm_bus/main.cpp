#include "data_provider.hpp"
#include "uart.hpp"
#include "spi.hpp"
#include "eth.hpp"

int main(){
    Uart uart;
    Spi spi;
    Eth eth;

    DataProvider dp;
    dp.add_bus(uart);
    dp.add_bus(spi);
    dp.add_bus(eth);

    dp.broadcast(5);

}