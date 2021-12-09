#include "CAN.h"

ros::Publisher CAN_pub;
CANbus CANbus;
usbCAN_pkg::CAN_msg CAN_output_msg;

void timer_CAN_Callback(const ros::TimerEvent& )
{
    CAN_output_msg.id = CANbus.CAN_output.id;
    CAN_pub.publish(CAN_output_msg);
    ROS_INFO("publish message ok");
}

int main (int argc, char** argv)
{
    ros::init(argc, argv, "CAN");
    ros::NodeHandle nh;
    CAN_pub = nh.advertise<usbCAN_pkg::CAN_msg>("CAN_Data", 1000);
    ros::Timer timer_CAN = nh.createTimer(ros::Duration(0.05), timer_CAN_Callback);

    // While loop do nothing, data received by interrupt
    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}

    
