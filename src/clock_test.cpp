#include <clock_test/clock_test.hpp>
#include <rclcpp/create_timer.hpp>

void ClockTest::onTimer()
{
  RCLCPP_INFO(this->get_logger(), "JUST_NOW = %f", this->now().seconds());
  RCLCPP_INFO(this->get_logger(), "NODE_TIME = %f", this->get_clock()->now().seconds());
  RCLCPP_INFO(this->get_logger(), "ROS_TIME = %f", rclcpp::Clock(RCL_ROS_TIME).now().seconds());
  RCLCPP_INFO(this->get_logger(), "SYSTEM_TIME = %f", rclcpp::Clock(RCL_SYSTEM_TIME).now().seconds());
  RCLCPP_INFO(this->get_logger(), "STEADY_TIME_AA = %f", rclcpp::Clock(RCL_STEADY_TIME).now().seconds());
  bool use_sim_time__ = this->get_parameter("use_sim_time").as_bool();
  RCLCPP_INFO(this->get_logger(), "use_sim_time = %s", use_sim_time__ ? "True" : "False");
}

ClockTest::ClockTest(const rclcpp::NodeOptions &node_options)
    : Node("clock_test", node_options)
{

  // clock_pub_ = this->create_publisher<rosgraph_msgs::msg::Clock>("/clock", 1);

  const double rate = 2.0;

  // Timer
  auto timer_callback = std::bind(&ClockTest::onTimer, this);
  auto period = std::chrono::duration_cast<std::chrono::nanoseconds>(
      std::chrono::duration<double>(1.0 / static_cast<double>(rate)));

  timer_ = std::make_shared<rclcpp::GenericTimer<decltype(timer_callback)>>(
      this->get_clock(), period, std::move(timer_callback),
      this->get_node_base_interface()->get_context());
  this->get_node_timers_interface()->add_timer(timer_, nullptr);
}

#include <rclcpp_components/register_node_macro.hpp>

RCLCPP_COMPONENTS_REGISTER_NODE(ClockTest)
