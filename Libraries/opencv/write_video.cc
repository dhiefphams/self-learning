#include <iostream>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, const char** argv) {
    cv::VideoCapture cap(0); // open the video camera 0

    if (!cap.isOpened()) {
        std::cout << "Error cannot open the video file" << std::endl;
        return -1;
    }

    cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);

    double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    std::cout << "Frame size " << dWidth << " x " << dHeight << std::endl;

    cv::Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

    cv::VideoWriter vidWriter(
        "myVic.avi",
        cv::VideoWriter::fourcc('P', 'I', 'M', '1'),
        24,
        frameSize,
        true);
    if (!vidWriter.isOpened()) {
        std::cout << "Error: Failed to write the video" << std::endl;
        return -1;
    }

    while (true) {
        cv::Mat frame;
        if (!cap.read(frame)) {
            std::cout << "Error: cannot read a frame from video file" << std::endl;
            break;
        }
        vidWriter.write(frame);
        cv::imshow("Webcam", frame);

        if (cv::waitKey(10) == 27)  {
            std::cout << "esc key is pressed by user" << std::endl;
            break;
        }
    }
    return 0;
}