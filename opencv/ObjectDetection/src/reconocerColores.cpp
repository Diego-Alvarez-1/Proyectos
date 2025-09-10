#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cout << "No se pudo abrir la cámara." << std::endl;
        return -1;
    }
    cv::Mat frame, mask, result;
    // Rango de color café en BGR (puedes ajustar estos valores según tu iluminación)
    cv::Scalar lower_brown(10, 40, 80);   // Azul mínimo, Verde mínimo, Rojo mínimo
    cv::Scalar upper_brown(60, 120, 200); // Azul máximo, Verde máximo, Rojo máximo

    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        cv::inRange(frame, lower_brown, upper_brown, mask); // Crear la máscara usando el rango definido
        cv::bitwise_and(frame, frame, result, mask);        // Aplicar la máscara al frame original
        cv::imshow("Camara", frame);
        cv::imshow("Mascara Cafe (BGR)", mask);
        cv::imshow("Color Cafe Detectado", result);
        char key = (char)cv::waitKey(30);
        if (key == 'q' || key == 27) break;
    }
    cap.release();
    cv::destroyAllWindows();
    return 0;
}
