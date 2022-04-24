#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <iostream>
void CounterCallback(const std_msgs::Int8::ConstPtr& msg)
{
    ROS_INFO("The counter is [%d]", msg->data);
}
/*using namespace std;*/
int main(int argc , char ** argv)
{
    ros::init(argc, argv, "Counter_sub");
    ros::NodeHandle n;
    ros::Subscriber counter_sub1 = n.subscribe("counter", 100, CounterCallback );
    ros::spin();
    return 0;
}

