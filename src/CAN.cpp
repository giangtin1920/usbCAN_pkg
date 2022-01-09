// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// #include <net/if.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <sys/ioctl.h>

// #include <linux/can.h>
// #include <linux/can/raw.h>

#include "CAN.h"

void handleFrame01A(const can::Frame &f){

	ROS_INFO("revieve CAN frames ok");
    // handle specific frame ----------> uu tien xu ly truoc
    //LOG("123? " << can::tostring(f, true)); // lowercase: true
//     std::stringstream ss;
//     can_float.byte.byte1 = f.data[0];
//     can_float.byte.byte2 = f.data[1];
//     can_float.byte.byte3 = f.data[2];
//     can_float.byte.byte4 = f.data[3];
}

// CANbus CANBus;
void processCanTxEvent(const ros::TimerEvent& )
{
	can::Frame canTx;
	// sockaddr_can addr;
	canTx.id = 0x01B;
	canTx.dlc = 2;
	canTx.data[0] = 0x11;
	canTx.data[1] = 0x22;

    // Writing CAN frames
    if (driver.send(canTx))
    {
        ROS_INFO("Writing CAN frames ok");
    }
        
    canTx_msg.id = canTx.id;
    canTx_msg.length = canTx.dlc;
    can_publisher.publish(canTx_msg);
    ROS_INFO("publish message ok");

    // return 0;
}

can::CommInterface::FrameListener::ListenerConstSharedPtr one_frame = driver.createMsgListener(can::MsgHeader(0x01A), handleFrame01A);

int main (int argc, char** argv)
{
    ros::init(argc, argv, "can_node");

	ros::NodeHandle n("~");
    ros::NodeHandle nh;

	n.param<string>("device", device, "slcan0");
	n.param<string>("publisher_topic", publisher_topic, "can_publisher");
	n.param<string>("subscriber_topic", subscriber_topic, "can_subscriber");


	if(driver.init("slcan0", false))
	{
		ROS_ERROR("Could not open device: %s",device.c_str());
		// return -1;
	}

	can_publisher = nh.advertise<usbcan_pkg::can_msg>("publisher_topic",1000);
	// can_subscriber = nh.subscribe(subscriber_topic.c_str(), 1000, canRxHandler);
	// CAN_pub = nh.advertise<usbCAN_pkg::CAN_msg>("CAN_Data", 1000);

	ros::Timer timer_CAN = nh.createTimer(ros::Duration(0.5), processCanTxEvent);
    
    // While loop do nothing, data received by interrupt
    while(ros::ok())
    {
        ros::spinOnce();
    }

    return 0;
}

    
