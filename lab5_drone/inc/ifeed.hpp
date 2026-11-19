#pragma once    


class IFeed{
    public:
    virtual ~IFeed() = default;
    virtual void activate() = 0;
    virtual void deactivate() = 0;

};