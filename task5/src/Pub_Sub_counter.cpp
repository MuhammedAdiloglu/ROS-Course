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
    ros::init(argc, argv , "Counter_pub1");
    // ros::init(argc, argv, "sub_1");
    ros::NodeHandle n;
    // ros::NodeHandle n1;
    ros::Publisher Counter_pub2= n.advertise<std_msgs::Int8>("counter",100);
    ros::Subscriber Counter_sub2 = n.subscribe("counter", 100, CounterCallback );
    std_msgs::Int8 msg;
    ros::Rate loop_rate(5);
    int count = 0;
    while(ros::ok())
    {
        std_msgs::Int8 msg;
        msg.data = count;
        ROS_INFO("%d", msg.data);
        Counter_pub2.publish(msg);
        loop_rate.sleep();
        ++count;

    }
    ros::spin();
    return 0;
}

