#ifndef LASER_SUB_H
#define LASER_SUB_H
#include "sensor_msgs/LaserScan.h"
#include <ros/ros.h>
#include <unordered_map>

class laserSub {
  
protected:
    ros::NodeHandle nh;
    ros::Subscriber sub;
    sensor_msgs::LaserScan laserData;
    std::unordered_map<std::string, float> hashmap;

public:
    laserSub();
    std::unordered_map<std::string, float> callback(const sensor_msgs::LaserScan::ConstPtr& msg);
};
#endif