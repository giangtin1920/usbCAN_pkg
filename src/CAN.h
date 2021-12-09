#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include "usbCAN_pkg/CAN_msg.h"
using namespace std;

struct output_msg
{
    uint32_t id;
    uint8_t type;
    uint8_t length;
    uint8_t data[8];
};

class CANbus
{
    public:
    CANbus();
    // explicit
    CANbus(CANbus &&) {};
    // implicit
    CANbus(const CANbus&) = default;
    CANbus& operator=(const CANbus&) = default;
    ~CANbus();

    output_msg CAN_output;

    private:

};
