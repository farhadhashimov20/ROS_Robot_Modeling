#include "ros/node_handle.h"
#include "ros/ros.h"
#include "ros/time.h"
#include "tf/LinearMath/Quaternion.h"
#include "tf/LinearMath/Vector3.h"
#include "tf/transform_broadcaster.h"
#include "tf/transform_datatypes.h"
#include <iostream>

int main(int argc, char **argv) {

  ros::init(argc, argv, "map_frame_broadcaster");
  ros::NodeHandle node_obj;

  tf::TransformBroadcaster broadcaster;
  tf::Transform transform;

  ros::Rate loop_rate(1000);

  while (ros::ok()) {
    transform.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
    transform.setRotation(tf::Quaternion(0, 0, 0, 1));
    broadcaster.sendTransform(
        tf::StampedTransform(transform, ros::Time::now(), "map", "base_link"));
    loop_rate.sleep();
  }
}