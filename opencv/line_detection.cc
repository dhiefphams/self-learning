#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char** argv) {
    // Load image
    cv::Mat src = cv::imread(argv[1]);
    // Check if image is loaded fine
    if (src.empty()) {
        std::cout << "Failed to load the image" << std::endl;
        return -1;
    }
    // Show origin image
    cv::namedWindow("Origin", cv::WINDOW_AUTOSIZE);
    cv::imshow("Origin", src);

    // Transform source image to gray
    cv::Mat gray;
    if (src.channels() == 3) {
        cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    } else {
        gray = src;
    }

    // show gray image
    cv::namedWindow("Gray", cv::WINDOW_AUTOSIZE);
    cv::imshow("Gray", gray);

    // Apply adaptiveThreshold at the bitwise_not of gray, notice the ~ symbol
    cv::Mat bw;
    cv::adaptiveThreshold(~gray, bw, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 15, -2);
    // Show the binoary image
    cv::namedWindow("Binary", cv::WINDOW_AUTOSIZE);
    cv::imshow("Binary", bw);

    // Create the images that will use to extract the horizontal and vertical lines
    cv::Mat horizontal = bw.clone();
    cv::Mat vertical = bw.clone();

    // Specify size on horizontal axis
    int horizontalsize = horizontal.cols / 30;

    // create structure element for extracting horizontal lines through morphology operators
    cv::Mat horizontalStructure = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(horizontalsize, 1));
    // Apply morphology operations
    cv::erode(horizontal, horizontal, horizontalStructure);
    cv::dilate(horizontal, horizontal, horizontalStructure);

    // SHow extract horizontal lines
    cv::namedWindow("horizontal", cv::WINDOW_AUTOSIZE);
    cv::imshow("horizontal", horizontal);

    // Specific size on veritical axis
    int verticalSize = vertical.rows / 30;

    // create structure element for extracting vertical lines through morphology operations
    cv::Mat verticalStructure = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, verticalSize));

    // Apply morphology operations
    cv::erode(vertical, vertical, verticalStructure);
    cv::dilate(vertical, vertical, verticalStructure);

    // Show extracted vertical lines
    cv::namedWindow("veritical", cv::WINDOW_AUTOSIZE);
    cv::imshow("veritical", vertical);

    // inverse vertical image
    cv::bitwise_not(vertical, vertical);
    cv::namedWindow("vertical_bit", cv::WINDOW_AUTOSIZE);
    cv::imshow("vertical_bit", vertical);

    // Extract edges and smooth image according to the logic
    // 1. extract (edges)
    // 2. dilate (edges)
    // 3. src.copyTo(smooth)
    // 4. blur smooth img
    // 5. smooth.copyTo(src, edges)
    
    // Step 1
    cv::Mat edges;
    cv::adaptiveThreshold(vertical, edges, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 3, -2);

    // Step 2
    cv::Mat kernel = cv::Mat::ones(2, 2, CV_8UC1);
    cv::dilate(edges, edges, kernel);
    cv::namedWindow("edges", cv::WINDOW_AUTOSIZE);
    cv::imshow("edges", edges);

    // Step 3
    cv::Mat smooth;
    vertical.copyTo(smooth);

    // Step 4
    cv::blur(smooth, smooth, cv::Size(2, 2));

    // Step 5
    smooth.copyTo(vertical, edges);

    cv::namedWindow("smooth");
    cv::imshow("smooth", vertical);

    cv::waitKey(0);
    return 0;
}