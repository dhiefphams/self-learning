#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

cv::Mat src, erosion_dst, dilation_dst;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;

void Erosion(int, void*);
void Dilation(int, void*);

int main(int, char** argv) {
    src = cv::imread(argv[1], cv::IMREAD_COLOR);
    if (src.empty()) {
        return -1;
    }

    cv::namedWindow("Erosion", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Invertion", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Dilation", cv::WINDOW_AUTOSIZE);
    cv::moveWindow("Dilation", src.cols, 0);

    cv::createTrackbar(
        "Element: \n 0: Rect \n 1: Cross \n 2: Ellipse",
        "Erosion",
        &erosion_elem,
        max_elem,
        Erosion);

    cv::createTrackbar(
        "Kernel size:\n 2+1",
        "Erosion",
        &dilation_elem,
        max_elem,
        Erosion);
    cv::createTrackbar(
        "Elem:\n 0: Rect \n 1: Cross \n 2: Ellipse",
        "Dilation",
        &dilation_elem,
        max_elem,
        Dilation);
    cv::createTrackbar(
        "Kernel size:\n 2n + 1",
        "Dilation",
        &dilation_size,
        max_kernel_size,
        Dilation);

    Erosion(0, 0);
    Dilation(0, 0);
    cv::waitKey(0);
    return 0;
}

void Erosion(int, void*) {
    int erosion_type = 0;
    if (erosion_elem == 0) {
        erosion_type = cv::MORPH_RECT;
    } else if (erosion_elem == 1) {
        erosion_type = cv::MORPH_CROSS;
    } else if (erosion_elem == 2) {
        erosion_type = cv::MORPH_ELLIPSE;
    }

    cv::Mat element = cv::getStructuringElement(
        erosion_type,
        cv::Size(2 * erosion_type + 1, 2 * erosion_type + 1),
        cv::Point(erosion_size, erosion_size));

    cv::erode(src, erosion_dst, element);
    cv::imshow("Erosion", erosion_dst);
}

void Dilation(int, void*) {
    int dilation_type = 0;
    if (dilation_elem == 0) {
        dilation_type = cv::MORPH_RECT;
    } else if (dilation_type == 1) {
        dilation_type = cv::MORPH_CROSS;
    } else if (dilation_elem == 2) {
        dilation_type = cv::MORPH_ELLIPSE;
    }

    cv::Mat element = cv::getStructuringElement(
        dilation_type,
        cv::Size(2* dilation_size + 1, 2 * dilation_size + 1),
        cv::Point(dilation_size, dilation_size));

    cv::dilate(src, dilation_dst, element);
    cv::imshow("Dilation", dilation_dst);
}