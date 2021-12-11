#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "CAN.h"

ros::Publisher CAN_pub;
CANbus CANbus;
usbCAN_pkg::CAN_msg CAN_output_msg;

int timer_CAN_Callback(const ros::TimerEvent& )
{
    CAN_output_msg.id = CANbus.CAN_output.id;
    CAN_pub.publish(CAN_output_msg);
    ROS_INFO("publish message ok");

	int s;
	int nbytes;
	struct sockaddr_can addr;
	struct can_frame frame;
	struct ifreq ifr;

	const char *ifname = "vcan0";

	if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) == -1) {
		perror("Error while opening socket");
		return -1;
	}

	strcpy(ifr.ifr_name, ifname);
	ioctl(s, SIOCGIFINDEX, &ifr);
	
	addr.can_family  = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	printf("%s at index %d\n", ifname, ifr.ifr_ifindex);

	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		perror("Error in socket bind");
		return -2;
	}

	frame.can_id  = 0x123;
	frame.can_dlc = 2;
	frame.data[0] = 0x11;
	frame.data[1] = 0x22;

    nbytes = write(s, &frame, sizeof(struct can_frame));
	printf("Wrote %d bytes\n", nbytes);
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

    
