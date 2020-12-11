#include "clock_test/clock_test.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions node_options;
  auto node = std::make_shared<ClockTest>("clock_test_node", node_options);

  rclcpp::spin(node);

  return 0;
};
