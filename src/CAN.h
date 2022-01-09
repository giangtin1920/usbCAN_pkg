#ifndef CAN_INIT_H
#define CAN_INIT_H

#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include "usbcan_pkg/can_msg.h"

#include "socketcan_interface/socketcan.h"
#include "socketcan_interface/threading.h"
#include "socketcan_interface/interface.h"
#include "socketcan_interface/string.h"
// #include <linux/can.h>

using namespace std;
can::ThreadedSocketCANInterface driver;

struct output_msg
{
    uint32_t id;
    uint8_t type;
    uint8_t length;
    uint8_t data[8];
};

std::string device,publisher_topic,subscriber_topic;

// can::SocketCANInterface can;

ros::Publisher can_publisher;
ros::Subscriber can_subscriber;

usbcan_pkg::can_msg canTx_msg;
usbcan_pkg::can_msg canRx_msg;

class CANbus: public can::SocketCANInterface
{
    public:
    CANbus();
    // explicit
    CANbus(CANbus &&) {};
    // implicit
    CANbus(const CANbus&) = default;
    CANbus& operator=(const CANbus&) = default;
    ~CANbus();



    output_msg canTx_output;
    output_msg canRx_output;

    void canRxHandler (void);
    // void processCanTxEvent (const ros::TimerEvent& );

    private:

};


#endif