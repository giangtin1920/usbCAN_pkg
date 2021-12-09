#include "CAN.h"

usbCAN_pkg::CAN_msg CAN_output_msg;

void chatterCallback (const usbCAN_pkg::CAN_msg& CAN_output_msg)
{
    ROS_INFO("I heard: [%d]", CAN_output_msg.type);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener_CAN");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("CAN_Data", 1000, chatterCallback);
    ros::spin();
    return 0;
}
