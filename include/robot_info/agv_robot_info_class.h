#ifndef AGV_ROBOT_INFO_CLASS_H
#define AGV_ROBOT_INFO_CLASS_H

#include "robot_info/robot_info_class.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include <string>


class AGVRobotInfo : public RobotInfo {
    std::string maximum_payload_;

protected:
    void compile_info() override;

public:
    AGVRobotInfo() = default;
    AGVRobotInfo(ros::NodeHandle *, ros::Rate, int);
    AGVRobotInfo(ros::NodeHandle *);

    ~AGVRobotInfo() = default;
};



#endif