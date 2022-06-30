#include "ros/ros.h"
#include "std_msgs/String.h"
 
//回调函数，当接收到订阅话题的时候就会被调用。
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("hello", 5, chatterCallback);
  ros::Rate loop_rate(0.5); 
  ros::spin();
  return 0;
}
