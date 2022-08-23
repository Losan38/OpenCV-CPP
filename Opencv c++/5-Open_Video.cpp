#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
	VideoCapture vid_capture("MVid.mp4");

    //not neccesery 
	if (!vid_capture.isOpened()){
		cout << "Couldnt Open Video!" << endl;
	}
	else {
		int fps = vid_capture.get(CAP_PROP_FPS);
		cout << "FPS: " << fps << endl;

		int frame_count = vid_capture.get(CAP_PROP_FRAME_COUNT);
		cout << "Frame count: " << frame_count << endl;
	}
    //till here
    
	while (vid_capture.isOpened()){
		Mat frame;
		bool framefound = vid_capture.read(frame);

		if(framefound == true){
            namedWindow("Frame", WINDOW_AUTOSIZE);
			imshow("Frame", frame);
    		int key = waitKey(20);
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