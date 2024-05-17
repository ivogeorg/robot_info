### robot_info

#### Run
`cd ~/catkin_ws/src`  
`git clone https://github.com/ivogeorg/robot_info.git`  
`roscore`  
`rosrun robot_info robot_info_node` or `rosrun robot_info agv_robot_info_node`  
`rostopic echo /robot_info` (in another terminal)  

#### Submission notes
1. There are 2 other tags that delimit different implementations.
2. The `AGVRobotInfo::publish_data` implementation is less elegant in order to adhere to the requirement that the function is `virtual` in the `RobotInfo` base class and overriden in the derived class.
3. The implementation of the `HydraulicSystemMonitor` is overengineered in order to adhere to the requirement that there is at least one method. Initially, the data fields were `public` and accessed directly, but they were converted to (implicitly) `private` in order to provide a `get_params()` method. I used the opportunity to try out _move semantics_. This also required that `src/hydraulic_system_monitor.cpp` be added to the `agv_robot_info_node` executable.

