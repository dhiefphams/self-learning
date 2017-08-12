#include <iostream>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, const char** argv) {
    // create new image
    cv::Mat img(650, 600, CV_16UC3, cv::Scalar(0, 50000, 50000));

    if (img.empty()) {
        std::cout << "Error: image cannot be loaded!" << std::endl;
        return -1;
    }

    std::vector<int> compression_params;
    // app compression technic
    compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
    compression_params.push_back(98); // the compression quality

    bool bSuccess = cv::imwrite("test.jpg", img, compression_params);

    if (!bSuccess) {
        std::cout << "Failed to save the image" << std::endl;
    }
    cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);

    cv::imshow("Image", img);

    cv::waitKey(0);

    cv::destroyWindow("Image");

    return 0;
}