#pragma once

class ICommBus{
    public:
        virtual ~ICommBus() = default;
        virtual void send(int data) = 0;

};