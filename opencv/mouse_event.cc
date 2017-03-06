#include <iostream>
#include <opencv2/highgui/highgui.hpp>

void mouseCallback(int event, int x, int y, int flags, void* userdata) {
	if (event == cv::EVENT_LBUTTONDOWN) {
		std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
	} else if (event == cv::EVENT_RBUTTONDOWN) {
		std::cout << "Right button the the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
	} else if (event == cv::EVENT_MBUTTONDOWN)  {
		std::cout << "Middle button if the mouse is clicked - position (" << x << ", " << y << ")"  << std::endl;
	} else if (event == cv::EVENT_MOUSEMOVE) {
		std::cout << "Mouse move over the windows - position (" << x << ", " << y << ")" << std::endl;
	}
}

void mouseKeyCallback(int event, int x, int y, int flags, void* userdata) {
	if (flags == (cv::EVENT_FLAG_CTRLKEY + cv::EVENT_FLAG_LBUTTON)) {
		std::cout << "Left mouse button is clicked while pressing CTRL key - position (" << x << ", " << ")" << std::endl;
	} else if (flags == (cv::EVENT_FLAG_RBUTTON + cv::EVENT_FLAG_SHIFTKEY)) {
		std::cout << "Right mouse button is clicked while pressing Shift key - position (" << x << ", " << ")" << std::endl;
	} else if (event == cv::EVENT_MOUSEMOVE && flags == cv::EVENT_FLAG_ALTKEY) {
		std::cout << "Moust is moved over the window while pressing ALT key - position (" << x << ", " << y << ")" << std::endl;
	} 
}

int main() {
	// Read image
	cv::Mat img = cv::imread("/home/dhiefphams/Downloads/golang.png");
	if (img.empty()) {
		std::cout << "Image cannot be loaded!" << std::endl;
		return -1;
	}

	// create windows
	cv::namedWindow("Mouse", cv::WINDOW_AUTOSIZE);
	// set event
	// cv::setMouseCallback("Mouse", mouseCallback);
	cv::setMouseCallback("Mouse", mouseKeyCallback, NULL);

	cv::imshow("Mouse", img);

	cv::waitKey(0);
	return 0;
}