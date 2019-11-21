#include "synchronization_manager.h"
namespace virtualgimbal
{
synchronization_manager::synchronization_manager() : pnh_("~"), image_transport_(nh_)
{
    std::string image = "/image";
    std::string imu_data = "/imu_data";
    pnh_.param("image", image, image);
    pnh_.param("imu_data", imu_data, imu_data);
    ROS_INFO("image topic is %s", image.c_str());
    ROS_INFO("imu_data topic is %s", imu_data.c_str());

    camera_subscriber_ = image_transport_.subscribeCamera(image, 100, &synchronization_manager::callback, this);
    imu_subscriber_ = pnh_.subscribe(imu_data, 10000, &synchronization_manager::imu_callback, this);
}

void synchronization_manager::callback(const sensor_msgs::ImageConstPtr &image, const sensor_msgs::CameraInfoConstPtr &ros_camera_info)
{
}

void synchronization_manager::imu_callback(const sensor_msgs::Imu::ConstPtr &msg)
{
}

double synchronization_manager::estimate_offset_time()
{
    return 0.0;
}

} // namespace virtualgimbal
