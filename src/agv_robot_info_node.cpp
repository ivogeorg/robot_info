#include "robot_info/agv_robot_info_class.h"
#include "ros/init.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "agv_robot_info_publisher_node");

    ros::NodeHandle nh;
    AGVRobotInfo robot(&nh);

    while (ros::ok()) {
        robot.publish_data();
        ros::spinOnce();
        robot.sleep();
    }
    
    return 0;    
}