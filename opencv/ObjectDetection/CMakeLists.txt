cmake_minimum_required(VERSION 3.10)

project(ObjectDetection)

set(OpenCV_DIR C:/openCV/opencv/build)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} src/reconocerColores.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})