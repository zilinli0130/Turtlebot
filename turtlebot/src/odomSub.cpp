#include "nav_msgs/Odometry.h"
#include "turtlebot/odomSub.h"
#include <ros/ros.h>

odomSub::odomSub() {
    nh = ros::NodeHandle("~");
    sub = nh.subscribe("/odom", 1000, &odomSub::callback, this);
}

void odomSub::callback(const nav_msgs::Odometry::ConstPtr& msg) {
   // ROS_INFO("%s", msg->header.frame_id.c_str());
  // ROS_INFO("%f", msg->twist.twist.linear.x);
  ROS_INFO("The position in x direction is");
  ROS_INFO("%f", msg->pose.pose.position.x);
}



int main(int argc, char** argv) {
    ros::init(argc, argv, "odomSub_node");
    odomSub odomSubObject;
    ros::spin();
    return 0;
}