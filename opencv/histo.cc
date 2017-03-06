#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void grayscaleCvt(const cv::Mat& img) {
	
	cv::Mat grayscale;
	// change the color of the image to grayscale image
	cv::cvtColor(img, grayscale, cv::COLOR_BGR2GRAY);

	cv::Mat img_hist_equalized;
	cv::equalizeHist(grayscale, img_hist_equalized);

	// create windows
	cv::namedWindow("Histogram Equalized", cv::WINDOW_AUTOSIZE);

	// show image
	cv::imshow("Histogram Equalized", img_hist_equalized);
}

void colorCvt(const cv::Mat& img) {
	// load image
	std::vector<cv::Mat> channels;
	cv::Mat img_hist_equalized;

	// convert the color image from BGR to YCrCb format
	cv::cvtColor(img, img_hist_equalized, CV_BGR2YCrCb);

	// split image into channel
	cv::split(img_hist_equalized, channels);
	// equalize histogram on the 1st channel
	cv::equalizeHist(channels[0], channels[0]);
	// merge 3 channels into one image
	cv::merge(channels, img_hist_equalized);
	// convert from YCrCb to BGR format
	cv::cvtColor(img_hist_equalized, img_hist_equalized, CV_YCrCb2BGR);

	// show
	cv::namedWindow("Histogram 3 channels");
	cv::imshow("Histogram 3 channels", img_hist_equalized);
}

int main() {
	std::string imgpath = "/home/dhiefphams/Downloads/golang.png";
	
	cv::Mat img = cv::imread(imgpath, CV_LOAD_IMAGE_COLOR);

	if (img.empty()) {
		std::cout << "Image cannot be loaded!" << std::endl;
		return -1;
	}
	cv::namedWindow("Origin Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Origin Image", img);

	grayscaleCvt(img);
	colorCvt(img);

	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}