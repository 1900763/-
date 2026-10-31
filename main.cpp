#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/videoio.hpp>


int main(){
    cv::VideoCapture cap(0, cv::CAP_V4L2); 
    cap.open(0); 
    if (!cap.isOpened()) { 
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }
    cv::Mat frame;
    cv::namedWindow("摄像头", cv::WINDOW_NORMAL); 
    while (true) {
        cap >> frame; 
        if (frame.empty()) { 
            std::cerr << "Error: Could not capture frame." << std::endl;
            break;
        }
        cv::imshow("摄像头", frame); 
        if (cv::waitKey(1) == 27) { 
            break;
        }
    }
    cap.release();
    cv::destroyAllWindows(); 
    return 0;
}
