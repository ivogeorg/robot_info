#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include <string>

RobotInfo::RobotInfo(ros::NodeHandle *nh, ros::Rate loop_rate, int queue_size,
                     std::string robot_desc, std::string serial_num,
                     std::string ip_addr, std::string firmware_ver)
    : robot_description_{robot_desc}, serial_number_{serial_num},
      ip_address_{ip_addr}, firmware_version_{firmware_ver},
      loop_rate_{loop_rate}, queue_size_(queue_size),
      robot_info_pub_{nh->advertise<robotinfo_msgs::RobotInfo10Fields>(
          "robot_info", queue_size_)} {
  ROS_INFO("/robot_info topic publisher created");
}

RobotInfo::RobotInfo(ros::NodeHandle *nh, ros::Rate loop_rate, int queue_size)
    : RobotInfo(nh, loop_rate, queue_size, "Mir100", "567A359", "169.254.5.180",
                "3.5.8") {}

RobotInfo::RobotInfo(ros::NodeHandle *nh) : RobotInfo(nh, 2, 10) {}

void RobotInfo::compile_info() {
  msgs_.data_field_01 = "robot_description: " + robot_description_;
  msgs_.data_field_02 = "serial_number: " + serial_number_;
  msgs_.data_field_03 = "ip_address: " + ip_address_;
  msgs_.data_field_04 = "firmware_version: " + firmware_version_;
}

void RobotInfo::publish_data() {
  compile_info();
  robot_info_pub_.publish(msgs_);
}
