#include <iostream>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, const char** argv) {
    cv::Mat img = cv::imread(
        "/home/dhiefphams/Pictures/lamborghini_dark-wallpaper-1920x1080.jpg",
        cv::IMREAD_UNCHANGED);
    if (img.empty()) {
        std::cout << "Error: Image cannot be loaded ... !!!" << std::endl;
        return -1;
    }

    cv::namedWindow("Lamborghini", cv::WINDOW_AUTOSIZE);
    cv::imshow("Lamborghini", img);

    cv::waitKey(0);

    cv::destroyWindow("Lamborghini");
    return 0;
}