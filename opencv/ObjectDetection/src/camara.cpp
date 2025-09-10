#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cout << "Error al abrir la camara" << std::endl;
        return -1;
    }
    cv::namedWindow("Camara", cv::WINDOW_AUTOSIZE);
    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            std::cout << "Error al capturar el frame" << std::endl;
            break;
        }
        cv::imshow("Camara", frame);
        char key = (char)cv::waitKey(30);
        if (key == 'q' || key == 27) break; // Salir si se presiona 'q' o 'ESC'
    }
    cap.release();
    cv::destroyAllWindows();
    return 0;
}