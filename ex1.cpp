#include "ros/ros.h"
#include "robot_control/state.h"
#include "dynamixel_msgs/JointState.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/Float64.h"

  double pos1;
	double pos2;
	double pos3;
	double pos4;
	double pos5;
	double vel1;
	double vel2;
	double vel3;
	double vel4;
	double vel5;

double pos1cntr=-1.0;
double pos2cntr=-1.0;
double pos3cntr=-1.0;
double pos4cntr=-1.0;
double pos5cntr=-1.0;


void jointCallback(const dynamixel_msgs::JointState::ConstPtr& msg) {

 pos1 = msg->current_pos;
 vel1 = msg->velocity;

	ROS_INFO(" pos 1: %f", pos1);
}

void joint1Callback(const dynamixel_msgs::JointState::ConstPtr& msg) {

 pos2 = msg->current_pos;
 vel2 = msg->velocity;
	ROS_INFO(" pos2: %f", pos2);
}

void joint2Callback(const dynamixel_msgs::JointState::ConstPtr& msg) {

 pos3 = msg->current_pos;
 vel3 = msg->velocity;
	ROS_INFO(" pos3: %f", pos3);
}

void joint3Callback(const dynamixel_msgs::JointState::ConstPtr& msg) {

 pos4 = msg->current_pos;
 vel4 = msg->velocity;
	ROS_INFO(" pos4: %f", pos4);
}

void joint4Callback(const dynamixel_msgs::JointState::ConstPtr& msg) {

 pos5 = msg->current_pos;
 vel5 = msg->velocity;
	ROS_INFO(" pos5: %f", pos5);
}

void jointControlCallback(const std_msgs::Float64::ConstPtr& msg) {

 pos1cntr=msg->data;

	ROS_INFO(" pos 1 cntr: %f", pos1cntr);
}

void joint1ControlCallback(const std_msgs::Float64::ConstPtr& msg) {

 pos2cntr=msg->data;

	ROS_INFO(" pos 2 cntr: %f", pos2cntr);
}

void joint2ControlCallback(const std_msgs::Float64::ConstPtr& msg) {

 pos3cntr=msg->data;

	ROS_INFO(" pos 3 cntr: %f", pos3cntr);
}

void joint3ControlCallback(const std_msgs::Float64::ConstPtr& msg) {

 pos4cntr=msg->data;

	ROS_INFO(" pos 4 cntr: %f", pos4cntr);
}

void joint4ControlCallback(const std_msgs::Float64::ConstPtr& msg) {

 pos5cntr=msg->data;

	ROS_INFO(" pos 5 cntr: %f", pos5cntr);
}

int main(int argc, char **argv){
ros::init(argc, argv, "moveit_motor_state");

ros::NodeHandle n1;
ros::NodeHandle n2;
ros::NodeHandle n3;
ros::NodeHandle n4;
ros::NodeHandle n5;
ros::NodeHandle nh1;
ros::NodeHandle nh2;
ros::NodeHandle nh3;
ros::NodeHandle nh4;
ros::NodeHandle nh5;


ros::NodeHandle nc1;
ros::NodeHandle nc2;
ros::NodeHandle nc3;
ros::NodeHandle nc4;
ros::NodeHandle nc5;

ros::Subscriber sub1 = n1.subscribe("/motortom2m/state", 1000, jointCallback);
ros::Subscriber sub2 = n2.subscribe("/joint2/state", 1000, joint1Callback);
ros::Subscriber sub3 = n3.subscribe("/joint4/state", 1000, joint2Callback);
ros::Subscriber sub4 = n4.subscribe("/joint6/state", 1000, joint3Callback);
ros::Subscriber sub5 = n5.subscribe("/end/state", 1000, joint4Callback);

ros::Subscriber subc1 = nc1.subscribe("/joint1/cntr", 1000, jointControlCallback);
ros::Subscriber subc2 = nc2.subscribe("/joint2/cntr", 1000, joint1ControlCallback);
ros::Subscriber subc3 = nc3.subscribe("/joint3/cntr", 1000, joint2ControlCallback);
ros::Subscriber subc4 = nc4.subscribe("/joint4/cntr", 1000, joint3ControlCallback);
ros::Subscriber subc5 = nc5.subscribe("/joint5/cntr", 1000, joint4ControlCallback);

ros::Publisher pub1 = nh1.advertise<std_msgs::Float64>("/motortom2m/command", 100);
ros::Publisher pub2 = nh1.advertise<std_msgs::Float64>("/joint2/command", 100);
ros::Publisher pub3 = nh1.advertise<std_msgs::Float64>("/joint4/command", 100);
ros::Publisher pub4 = nh1.advertise<std_msgs::Float64>("/joint6/command", 100);
ros::Publisher pub5 = nh1.advertise<std_msgs::Float64>("/end/command", 100);

std_msgs::Float64 msg;


ros::Rate loop_rate(10);
while(ros::ok()){

    if(pos1cntr>pos1){msg.data = pos1cntr; pub1.publish(msg);}
    else{msg.data = pos1;}
    if(pos2cntr>pos2){msg.data = pos2cntr; pub2.publish(msg);}
    else{msg.data = pos2;}
    if(pos3cntr>pos3){msg.data = pos3cntr; pub3.publish(msg);}
    else{msg.data = pos3;}
    if(pos4cntr>pos4){msg.data = pos4cntr; pub4.publish(msg);}
    else{msg.data = pos4;}
    if(pos5cntr>pos5){msg.data = pos5cntr; pub5.publish(msg);}
    else{msg.data = pos5;}

    ros::spinOnce();
    loop_rate.sleep();
}
return 0;
}