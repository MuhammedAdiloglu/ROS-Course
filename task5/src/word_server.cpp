#include "ros/ros.h"
#include"task5/words.h"
bool count_words(task5::words::Request  &req, task5::words::Response &res)
{
    int len = req.word.length();
    int counter=1;
    if (len>0 )
    {       for (int i = 0 ; i < len ; ++i)
        {
            
            if (req.word[i]== ' ')
            {
            ++counter;
            }
        }

     
    }
    else 
    {
        counter=0;
        
    }
    res.count = counter;
    return true;
 }

int main(int argc, char **argv)
{
ros::init( argc , argv , "word_counter_server");
ros::NodeHandle n;
ros::ServiceServer service = n.advertiseService("word_counter",count_words);
ros::spin();
return 0;
}
