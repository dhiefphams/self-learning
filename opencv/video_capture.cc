// g++ cv.cc  $(pkg-config --libs --cflags opencv) -o cv
// #include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>


int main() {
    cv::Mat image;

    cv::VideoCapture cap;
    cap.open(0);

    cv::namedWindow("window", 1);

    while(1) {
        cap >> image;
        // print image
        cv::imshow("window", image);

        // delay 33ms
        cv::waitKey(33);
    }
}   