* Copyright 2021 Umbratek Inc. All Rights Reserved.
 *
 * Software License Agreement (BSD License)
 *
 * Author: johnson <johnson@umbratek.com>
 ============================================================================*/
#include <cstdlib>
#include "adra_ros/Api.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "adra_server_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<adra_ros::Api>("adra_server");
  adra_ros::Api srv;
  const char *api[4] = { "get_motion_mode", "into_motion_mode_pos",
                             "into_motion_enable", "set_pos_target" };
  for (int i=0; i <4; i++) {
  srv.request.api_name = api[i];
  srv.request.args.clear();
  srv.request.args.push_back("1");
  if (i=3) {
  srv.request.args.push_back("
  if (client.call(srv)) {
    int size = srv.response.rets.size();
    if (i=0) {
    ROS_INFO("rets size : %d ,ret[0]: %s ret[1]: %s", size, srv.response.rets[0].c_str(), srv.response.rets[1].c_str()); 
    }
    else {
    ROS_INFO("rets size : %d ,ret[0]: %s", size, srv.response.rets[0].c_str());
    }} else {
    ROS_ERROR("Failed to call service ");
    return 1;
  }
  srv.response.rets.clear();
  }
  return 0;
}
