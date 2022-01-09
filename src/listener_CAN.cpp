#include "CAN.h"

usbcan_pkg::can_msg CAN_output_msg;

void chatterCallback (const usbcan_pkg::can_msg& CAN_output_msg)
{
    ROS_INFO("I heard: [%d]", CAN_output_msg.id);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener_CAN");
    ros::NodeHandle nk;
    ros::Subscriber sub = nk.subscribe("publisher_topic", 1000, chatterCallback);
    ros::spin();
    return 0;
}
