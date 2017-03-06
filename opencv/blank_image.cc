#include <iostream>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, const char** argv) {
    cv::Mat img(500, 1000, CV_8UC3, cv::Scalar(122, 0, 0));

    if (img.empty()) {
        std::cout << "Error: Image cannot be loaded...!" << std::endl;
        return -1;
    }

    cv::namedWindow("Just", cv::WINDOW_AUTOSIZE);
    cv::imshow("Just", img);

    cv::waitKey(0);

    cv::destroyWindow("Just");
    return 0;
}