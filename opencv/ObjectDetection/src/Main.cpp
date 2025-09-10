#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    const int w = 500;
    Mat scene = Mat::zeros(w, w, CV_8UC3);

    // Colores
    Scalar sky(255, 230, 200);       // Cielo claro
    Scalar groundColor(0, 180, 0);   // Césped
    Scalar shoeColor(40, 30, 80);    // Zapatos
    Scalar overallBlue(255, 0, 0);   // Overol
    Scalar shirtRed(0, 0, 255);      // Camisa y gorra
    Scalar skin(70, 190, 230);       // Piel
    Scalar moustache(30, 30, 30);    // Bigote
    Scalar hair(30, 30, 30);         // Cabello
    Scalar gold(0, 220, 255);        // Botones

    // Fondo
    scene.setTo(sky);
    rectangle(scene, Point(0, w - 70), Point(w, w), groundColor, FILLED);

    // Centro de Mario
    int mx = w / 2;
    int my = w - 110;

    // --- ZAPATOS ---
    ellipse(scene, Point(mx - 14, my + 45), Size(18, 10), 0, 0, 360, shoeColor, FILLED);
    ellipse(scene, Point(mx + 14, my + 45), Size(18, 10), 0, 0, 360, shoeColor, FILLED);

    // --- PIERNAS ---
    rectangle(scene, Point(mx - 18, my), Point(mx - 2, my + 35), overallBlue, FILLED);
    rectangle(scene, Point(mx + 2, my), Point(mx + 18, my + 35), overallBlue, FILLED);

    // --- CUERPO ---
    rectangle(scene, Point(mx - 25, my - 40), Point(mx + 25, my), shirtRed, FILLED);

    // Tirantes del overol
    rectangle(scene, Point(mx - 20, my - 40), Point(mx - 12, my), overallBlue, FILLED);
    rectangle(scene, Point(mx + 12, my - 40), Point(mx + 20, my), overallBlue, FILLED);

    // Botones con borde
    circle(scene, Point(mx - 16, my - 20), 5, gold, FILLED);
    circle(scene, Point(mx + 16, my - 20), 5, gold, FILLED);
    circle(scene, Point(mx - 16, my - 20), 5, Scalar(0, 0, 0), 1);
    circle(scene, Point(mx + 16, my - 20), 5, Scalar(0, 0, 0), 1);

    // --- BRAZOS ---
    rectangle(scene, Point(mx - 42, my - 35), Point(mx - 25, my - 5), shirtRed, FILLED);
    rectangle(scene, Point(mx + 25, my - 35), Point(mx + 42, my - 5), shirtRed, FILLED);

    // Guantes
    circle(scene, Point(mx - 42, my - 20), 11, Scalar(255, 255, 255), FILLED);
    circle(scene, Point(mx + 42, my - 20), 11, Scalar(255, 255, 255), FILLED);

    // --- CABEZA ---
    circle(scene, Point(mx, my - 55), 23, skin, FILLED);

    // Cabello (detrás)
    ellipse(scene, Point(mx, my - 52), Size(24, 26), 0, 180, 360, hair, FILLED);

    // --- GORRA ---
    ellipse(scene, Point(mx, my - 65), Size(30, 15), 0, 0, 180, shirtRed, FILLED);
    rectangle(scene, Point(mx - 30, my - 65), Point(mx + 30, my - 60), shirtRed, FILLED);

    // Letra "M"
    putText(scene, "M", Point(mx - 8, my - 62), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 2);

    // --- OJOS ---
    circle(scene, Point(mx - 7, my - 58), 5, Scalar(255, 255, 255), FILLED);
    circle(scene, Point(mx + 7, my - 58), 5, Scalar(255, 255, 255), FILLED);
    circle(scene, Point(mx - 7, my - 58), 2, Scalar(0, 0, 0), FILLED);
    circle(scene, Point(mx + 7, my - 58), 2, Scalar(0, 0, 0), FILLED);

    // --- BIGOTE ---
    ellipse(scene, Point(mx, my - 50), Size(14, 5), 0, 0, 180, moustache, FILLED);


    imshow("Mario Bros ", scene);
    waitKey(0);
    return 0;
}
