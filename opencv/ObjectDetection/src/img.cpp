#include <opencv2/opencv.hpp>
#include <iostream>


int main(){

    cv:: Mat img = cv::imread("C:/openCV/ObjectDetection/mapaDota.jpg");
    namedWindow("OpenCV Fondo", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV Fondo", img);
    cv::moveWindow("OpenCV Fondo", 0,80);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}