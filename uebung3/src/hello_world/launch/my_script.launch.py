import launch
import launch.actions
import launch.substitutions
import launch_ros.actions


def generate_launch_description():
    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable('USER'), '_'],
            description='Prefix for node names'),
        launch_ros.actions.Node(
            package='hello_world', 
            node_executable='talker', 
            output='screen',
            node_name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'talker']),
        launch_ros.actions.Node(
            package='hello_world',
            node_executable='listener', 
            output='screen',
            node_name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'listener']),
    ])