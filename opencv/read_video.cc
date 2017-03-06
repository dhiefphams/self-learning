#include <iostream>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, const char** argv) {
    cv::VideoCapture capture("duyenphan.mp4");

    if (!capture.isOpened()) {
        std::cout << "Cannot open the video file !" << std::endl;
        return -1;
    }

    // start the video at 300ms
    capture.set(cv::CAP_PROP_POS_MSEC, 300);

    // get frames per second
    double fps = capture.get(cv::CAP_PROP_FPS);
    std::cout << "Frame per seconds: " << fps << std::endl;

    cv::namedWindow("VideoCam", cv::WINDOW_NORMAL);

    while (1) {
        cv::Mat frame;
        // read a new frame from video
        bool bSuccess = capture.read(frame);
        if (!bSuccess) {
            // break loop when failed
            std::cout << "Cannot read the frame from the video file!" << std::endl;
            break;
        }
        // Show the frame
        cv::imshow("VideoCam", frame);
        // wait for 'esc' key press for 30ms.
        if (cv::waitKey(33) == 27) {
            std::cout << "ESC key is pressed by user" << std::endl;
            break;
        }
    }
    return 0;
}