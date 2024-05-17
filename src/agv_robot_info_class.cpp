#include "robot_info/agv_robot_info_class.h"
#include "robot_info/robot_info_class.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include <string>
#include <vector>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh, ros::Rate loop_rate,
                           int queue_size)
    : RobotInfo(nh, loop_rate, queue_size) {
  maximum_payload_ = "100 Kg";
  ROS_INFO("AGV robot created");
}

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh) : AGVRobotInfo(nh, 2, 10) {}

void AGVRobotInfo::compile_info() {
  msgs_.data_field_05 = "maximum_payload: " + maximum_payload_;
  std::vector<std::string> hyd_params = std::move(hsm_.pack_hydraulic_parameters());
  msgs_.data_field_06 = "hydraulic_oil_temperature: " + hyd_params[0];
  msgs_.data_field_07 = "hydraulic_oil_tank_fill_level: " + hyd_params[1];
  msgs_.data_field_08 = "hydraulic_oil_pressure: " + hyd_params[2];
}

void AGVRobotInfo::publish_data() {
  RobotInfo::compile_info();
  compile_info();
  robot_info_pub_.publish(msgs_);
}