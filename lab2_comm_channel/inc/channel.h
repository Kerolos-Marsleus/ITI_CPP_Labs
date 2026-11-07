#ifndef CHANNEL_H
#define CHANNEL_H

#include <variant>
using SensorValue = std::variant<std::monostate,int, float, double>;

class Channel {
    public:
    virtual ~Channel() = default;

    virtual void write(const SensorValue &val) = 0;
    virtual SensorValue read() = 0;

};






#endif  /*CHANNEL_H*/