#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {
	// create 2 empty windows
	cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Smoothed Image", cv::WINDOW_AUTOSIZE);

	// load image from file
	cv::Mat src = cv::imread("/home/dhiefphams/Downloads/golang.png", 1);
	// show the original image
	cv::imshow("Original Image", src);

	cv::Mat dst;
	char zBuffer[35];

	for (int i = 1; i < 31; i += 2) {
		// copy the text to the zbuffer
		snprintf(zBuffer, 35, "Kernel size: %d x %d", i, i);
		// blur the image
		// cv::blur(src, dst, cv::Size(i, i));
		// cv::GaussianBlur(src, dst, cv::Size(i, i), 0);
		cv::bilateralFilter(src, dst, i, i, i);
		cv::putText(dst, zBuffer, cv::Point(src.cols/4, src.rows/8), CV_FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0, 0, 0));

		cv::imshow("Smoothed Image", dst);

		int c = cv::waitKey(2000);

		if (c == 27) {
			return 0;
		}
	}

	// Make the dst image black
	dst = cv::Mat::zeros(src.size(), src.type());

	// copy the text to the buffer
	snprintf(zBuffer, 35, "Press Any key to Exit");

	// put the text in the zBuffer to the dist image
	cv::putText(dst, zBuffer, cv::Point(src.cols/4, src.rows/2), CV_FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0, 0, 0));
	cv::imshow("Smoothed Image", dst);
	return 0;
}