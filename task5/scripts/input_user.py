#!/usr/bin/env python
import rospy
import std_msgs
from geometry_msgs.msg import Twist


def get_linear_vel():
  rospy.loginfo("please enter a number between 2 and 6 ")
  linear_input = 0 
  linear_input = input()
  if linear_input >= 2 and linear_input <= 6 :
    return float(linear_input)
  else:
    rospy.loginfo("you entered a wrong value. please enter a number between 2 and 6 ")
    return get_linear_vel()
    
def get_angular_vel():
  rospy.loginfo("please enter a number between 1 and 3 ")
  angular_input = 0
  angular_input  = input()
  if angular_input >= 1 and angular_input <= 3 :
     return float(angular_input)
  else :
    rospy.loginfo("you entered a wrong value. please enter a number between 1 and 3 ")
    return get_angular_vel()

class ControlTurtlesim():

    def __init__(self):

        rospy.init_node('move_turtlesim_user', anonymous=False)

		# Message to screen
        rospy.loginfo(" Press CTRL+c to stop moving the Turtle")

        # Keys CTRL + c will stop this script
        rospy.on_shutdown(self.shutdown)


        self.cmd_vel = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)


	    # Turtlesim will receive our messages 10 times per second.
        rate = rospy.Rate(10);

        rospy.loginfo("Set rate 10Hz")

        move_cmd_user = Twist()
        move_cmd_user.linear.x = get_linear_vel()
        move_cmd_user.angular.z = get_angular_vel()

	    # Loop until you type CTRL+c
        while not rospy.is_shutdown():
            self.cmd_vel.publish(move_cmd_user)
            rate.sleep()


    def shutdown(self):
        # You can stop turtlesim_move by publishing an empty Twist message
        rospy.loginfo("Stopping the turtle")

        self.cmd_vel.publish(Twist())

        # Give it some time to stop
        rospy.sleep(1)

if __name__ == '__main__':

    try:
        ControlTurtlesim()
    except:
        rospy.loginfo("End of the swim for this Turtle.")
