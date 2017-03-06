#include <iostream>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, const char** argv) {
    cv::VideoCapture cap(0); // open the cam no 0

    if (!cap.isOpened()) {
        std::cout << "Cannot open the video cam" << std::endl;
        return -1;
    }

    double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    std::cout << "Frame size: " << dWidth << " x " << dHeight << std::endl;

    cv::namedWindow("VideoCam", cv::WINDOW_AUTOSIZE);

    while(1) {
        cv::Mat frame;
        bool bSuccess = cap.read(frame); 

        if (!bSuccess) {
            std::cout << "Cannot read a frame from video stream" << std::endl;
            break;
        }

        cv::imshow("VideoCam", frame);

        if (cv::waitKey(33) == 27) {
            std::cout << "Stop" << std::endl;
            break;
        }
    }
    return 0;
}