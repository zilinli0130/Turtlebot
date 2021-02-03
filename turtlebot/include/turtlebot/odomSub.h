#ifndef ODOM_SUB_H
#define ODOM_SUB_H
#include "nav_msgs/Odometry.h"
#include <ros/ros.h>

class odomSub {
  
protected:
    ros::NodeHandle nh;
    ros::Subscriber sub;

public:
    odomSub();
    void callback(const nav_msgs::Odometry::ConstPtr& msg);
};
#endif