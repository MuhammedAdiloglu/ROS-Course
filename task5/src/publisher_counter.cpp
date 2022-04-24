#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <iostream>
/*using namespace std;*/
int main(int argc , char ** argv)
{
    ros::init(argc, argv , "Counter_pub");
    ros::NodeHandle n;
    ros::Publisher counter_pub1= n.advertise<std_msgs::Int8>("counter",100);
    std_msgs::Int8 msg;
    ros::Rate loop_rate(5);
    int count = 0;
    while(ros::ok())
    {
        msg.data = count;
        ROS_INFO("%d", msg.data);
        counter_pub1.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;

    }
    return 0;
}

