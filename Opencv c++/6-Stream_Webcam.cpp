#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
	VideoCapture vid_capture(0);

    //not neccesery 
	if (!vid_capture.isOpened()){
		cout << "Couldnt Open Webcam!" << endl;
	}
	else {
		int Frame_Hight = vid_capture.get(CAP_PROP_FRAME_HEIGHT);
		cout << "Hight of Frame: " << Frame_Hight << endl;

		int Frame_Width = vid_capture.get(CAP_PROP_FRAME_WIDTH);
		cout << "Width of Frame: " << Frame_Width << endl;
	}
    //till here
    
	while (vid_capture.isOpened()){
		Mat frame;
		bool framefound = vid_capture.read(frame);

		if(framefound == true){
            namedWindow("Frame", WINDOW_AUTOSIZE);
			imshow("Frame", frame);
    		int key = waitKey(1);
    		if (key == 'q'){
    			cout << "Stopping... " << endl;
    			break;
    		}
		}
		else {
            break;
        }
    }
	
	vid_capture.release();
	destroyAllWindows();
	return 0;
}