#include "ros/ros.h"
#include "robot_control/state.h"
#include "dynamixel_msgs/JointState.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/Float64.h"
#include "math.h"

// ros::Time begin = ros::Time::now();


int main(int argc, char **argv){
ros::init(argc, argv, "moveit_motor_state");

ros::NodeHandle nh1;
ros::NodeHandle nh2;
ros::NodeHandle nh3;
ros::NodeHandle nh4;
ros::NodeHandle nh5;


ros::Publisher pub1 = nh1.advertise<std_msgs::Float64>("/motortom2m/command", 100);
ros::Publisher pub2 = nh2.advertise<std_msgs::Float64>("/joint2/command", 100);
ros::Publisher pub3 = nh3.advertise<std_msgs::Float64>("/joint4/command", 100);
ros::Publisher pub4 = nh4.advertise<std_msgs::Float64>("/joint6/command", 100);
ros::Publisher pub5 = nh5.advertise<std_msgs::Float64>("/end/command", 100);

std_msgs::Float64 msg1;
std_msgs::Float64 msg2;
std_msgs::Float64 msg3;
std_msgs::Float64 msg4;
std_msgs::Float64 msg5;

ros::Rate loop_rate(10);
while(ros::ok()){

    double secs =ros::Time::now().toSec();
	msg1.data=0.3*sin(2*3.14*0.5*secs);
	msg2.data=0.3*sin(2*3.14*0.5*(secs-0.25));
	msg3.data=0.3*sin(2*3.14*0.5*(secs-0.5));
	msg4.data=0.3*sin(2*3.14*0.5*(secs-0.75));
	msg5.data=0.3*sin(2*3.14*0.5*(secs-1));
	pub1.publish(msg1);
	pub2.publish(msg2);
	pub3.publish(msg3);
	pub4.publish(msg4);
	pub5.publish(msg5);
    ros::spinOnce();
    loop_rate.sleep();
}
return 0;
}