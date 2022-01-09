// #include "CAN.h"

// CANbus::CANbus()
// {

// };

// CANbus::~CANbus()
// {

// };

// void CANbus::canRxHandler(void)
// {
//     // boost::system::error_code ec;
//     // readFrame(ec);
    

//     // can_rx_msg_.flags = (rx_.can_id & (1 << 31)) >> 29;
//     // can_rx_msg_.cob = rx_.can_id & 0x1FFFFFFF; // mask out EFF/RTR/ERR flags from id
//     // can_rx_msg_.id = rx_.can_id & 0x1FFFFFFF;
//     // can_rx_msg_.length = rx_.can_dlc;
//     // for (int i = 0; i <rx_.can_dlc; i++)
//     // {
//     // can_rx_msg_.data[i] = rx_.data[i];
//     // }
//     // can_rx_publisher_.publish(can_rx_msg_);

// }

// // void CANbus::processCanTxEvent(const ros::TimerEvent& )
// // {
// // 	can::Frame canTx;
// // 	// sockaddr_can addr;
// // 	canTx.id = 0x01A;
// // 	canTx.dlc = 2;
// // 	canTx.data[0] = 0x11;
// // 	canTx.data[1] = 0x22;

// //     // Writing CAN frames
// //     if (can::CommInterface::send(canTx))
// //     {
// //         ROS_INFO("Writing CAN frames ok");
// //     }
        
// //     canTx_msg.id = canTx.id;
// //     canTx_msg.length = canTx.dlc;
// //     can_publisher.publish(canTx_msg);
// //     ROS_INFO("publish message ok");

// //     // return 0;
// // }