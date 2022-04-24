#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <task5/imaginary_msg.h>
#include <iostream>
int main(int argc , char ** argv)
{
    ros::init(argc, argv , "Num_pub");
    ros::NodeHandle n;
    ros::Publisher num_pub= n.advertise<task5::imaginary_msg>("Num",100);
    task5::imaginary_msg Num;
    ros::Rate loop_rate(5);
    int count = 0;
    while(ros::ok())
    {
        Num.real = rand() % 10;
        Num.img =rand() % 10;
        Num.i = 'i';
        ROS_INFO("%d + %d%c", Num.real , Num.img , Num.i);
        num_pub.publish(Num);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;

    }
    return 0;
}

