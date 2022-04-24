#include <ros/ros.h>
#include<task5/words.h>
#include<iostream>
using namespace std;
int main(int argc, char **argv)
{
    ros::init(argc, argv, "word_counter_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<task5::words>("word_counter");
    task5::words srv;
    string sen = "";
    cerr<<"please enter a sentence"<<endl;
    getline(cin, sen);
    srv.request.word= sen;
    if (client.call(srv))
    {
        cerr<<"The number of words in this sentence is: "<<srv.response.count<<endl;
    }
    else
    {
            cerr<<"failed"<<endl;
    
    }
    return 0 ;
        
}