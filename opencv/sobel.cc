#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

int main(int, char** argv) {
	cv::Mat src, src_gray;
	cv::Mat grad;

	const char* window_name = "Sobel Demo";
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	src = cv::imread(argv[1], cv::IMREAD_COLOR);
	if (src.empty()) {
		std::cout << "Cannot load image ! " << std::endl;
		return -1;
	}

	cv::GaussianBlur(src, src, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);

	cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);

	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;


	// Becareful: x - vertival, y - horizontal
	cv::Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT);
	cv::Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT);

	cv::convertScaleAbs(grad_x, abs_grad_x);
	cv::convertScaleAbs(grad_y, abs_grad_y);

	cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

	cv::imshow(window_name, grad);

	cv::namedWindow("X");
	cv::imshow("X", abs_grad_x);

	cv::namedWindow("Y");
	cv::imshow("Y", abs_grad_y);

	cv::waitKey(0);
	return 0;
}