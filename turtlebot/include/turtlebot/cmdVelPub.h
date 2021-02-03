#ifndef CMD_VEL_PUB_H
#define CMD_VEL_PUB_H
#include "geometry_msgs/Twist.h"
#include <ros/ros.h>

class cmdVelPub {
  
protected:
    ros::NodeHandle nh;
    ros::Publisher pub;
    geometry_msgs::Twist move;
    float x = 0.3;
    float z = 0.5;

public:
    cmdVelPub();
    void moveRobot(std::string direction);
};
#endif