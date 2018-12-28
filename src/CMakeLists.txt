cmake_minimum_required(VERSION 2.8.3)

project(vision)

find_package(catkin REQUIRED COMPONENTS 
	roscpp
	sensor_msgs
	cv_bridge
	std_msgs
	image_transport
	OpenCV
)

catkin_package()

include_directories(
	${catkin_INCLUDE_DIRS}
)

add_executable(topic_publisher_node
	cvBridge.cpp 
)

target_link_libraries(topic_publisher_node
	${catkin_LIBRARIES} 
	${OpenCV_LIBRARIES}
)
