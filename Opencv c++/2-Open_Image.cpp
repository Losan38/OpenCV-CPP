#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main (){
    Mat Image = imread("IMG1.png");

    namedWindow("IMAGE", WINDOW_AUTOSIZE);
    imshow("IMAGE", Image);
    int key = waitKey(0);
    if (key == 'Q'){
        destroyAllWindows();
    }
}
