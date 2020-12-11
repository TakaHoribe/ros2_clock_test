from launch import LaunchContext
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackage
from pathlib import Path

import os


def generate_launch_description():

    context = LaunchContext()

    clock_test = Node(
        package='clock_test',
        executable='clock_test_node',
        name='clock_test',
        # node_namespace='simulation',
        output='screen',
        parameters=[
            {
                # "use_sim_time": True,
            }
        ]
    )
    clock_test_w_namespace = Node(
        package='clock_test',
        executable='clock_test_node',
        name='clock_test',
        namespace='test',
        output='screen',
        parameters=[
            {
                # "use_sim_time": True,
            }
        ]
    )


    return LaunchDescription([
        clock_test,
        clock_test_w_namespace
    ])
