#ifndef ROBOT_INFO_CLASS_H
#define ROBOT_INFO_CLASS_H

#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/publisher.h"
#include "ros/ros.h"
#include <string>

class RobotInfo {
  // Robot info
  std::string robot_description_;
  std::string serial_number_;
  std::string ip_address_;
  std::string firmware_version_;

  // ROS
  ros::Rate loop_rate_;
  int queue_size_;
  ros::Publisher robot_info_pub_;

  robotinfo_msgs::RobotInfo10Fields msgs_;

protected:
  virtual void compile_info();

public:
  RobotInfo() = default;
  RobotInfo(ros::NodeHandle *, ros::Rate loop_rate, int queue_size,
            std::string robot_desc, std::string serial_num, std::string ip_addr,
            std::string firmware_ver);
  RobotInfo(ros::NodeHandle *, ros::Rate loop_rate, int queue_size);
  RobotInfo(ros::NodeHandle *);

  ~RobotInfo() = default;

  void publish_data();
  void sleep() { loop_rate_.sleep(); }
};

#endif