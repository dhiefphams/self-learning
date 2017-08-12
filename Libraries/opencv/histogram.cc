#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {
    std::string imgpath = "~/Pictures/15978041_1223624821018859_7503987904502488479_n.jpg";
    cv::Mat img = cv::imread(imgpath, CV_LOAD_IMAGE_COLOR);
    if (img.empty()) {
        std::cout < "Image cannot be loaded!" << std::endl;
        return -1;
    }

    std::vector<cv::Mat> channels;
    cv::Mat img_hist_equalized;
    cv::cvtColor(img, img_hist_equalized, CV_BGR2YCrCb);
    cv::split(img_hist_equalized, channels);
    cv::equalizeHist(channels[0], channels[0]);

    cv::merge(channels, img_hist_equalized);

    cv::cvtColor(img_hist_equalized, img_hist_equalized, CV_YCrCb2BGR);

    // display image
    cv::namedWindow("Histogram", cv::WINDOW_AUTOSIZE);
}