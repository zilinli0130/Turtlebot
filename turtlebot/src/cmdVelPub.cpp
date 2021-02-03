#include <ros/ros.h>
#include "turtlebot/cmdVelPub.h"
#include <geometry_msgs/Twist.h>

cmdVelPub::cmdVelPub() {
    nh = ros::NodeHandle("~");
    pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
}

void cmdVelPub::moveRobot(std::string direction) {

    if (direction == "front") {
        move.linear.x = x;
        move.angular.z = 0.0;
    } else if (direction == "left") {
        move.linear.x = 0.0;
        move.angular.z = z;
    } else if (direction == "right") {
        move.linear.x = 0.0;
        move.angular.z = -z;
    } else if (direction == "stop") {
        move.linear.x = 0.0;
        move.angular.z = 0.0;
    }
    pub.publish(move);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "cmdVelPub_node");
    cmdVelPub *cmdVelPubObject = new cmdVelPub();
    ros::Rate rate(2);

    while (ros::ok()) {
        cmdVelPubObject->moveRobot("front");
        rate.sleep();
        ros::spinOnce();
        
    }
    delete cmdVelPubObject;
    return 0;
}