#include "robot_info/agv_robot_info_class.h"
#include "robot_info/robot_info_class.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include <string>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh, ros::Rate loop_rate,
                           int queue_size)
    : RobotInfo(nh, loop_rate, queue_size) {
  maximum_payload_ = "100 Kg";
  ROS_INFO("AGV robot created");
}

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh) : AGVRobotInfo(nh, 2, 10) {}

void AGVRobotInfo::compile_info() {
    RobotInfo::compile_info();
    msgs_.data_field_05 = "maximum_payload: " + maximum_payload_;
}