#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main (){
    Mat Image = imread("IMG1.png");
    Mat GrayImage = imread("IMG1.png",IMREAD_GRAYSCALE);
    
    namedWindow("IMAGE", WINDOW_AUTOSIZE);
    namedWindow("GRAYIMAGE", WINDOW_AUTOSIZE);
    
    imshow("IMAGE", Image);
    imshow("GRAYIMAGE", GrayImage);
    int key = waitKey(0);
    if (key == 'Q'){
        destroyAllWindows();
    }
}
