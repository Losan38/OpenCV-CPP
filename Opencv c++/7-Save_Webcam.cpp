#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
	VideoCapture vid_capture(0);

	int Frame_Height = vid_capture.get(CAP_PROP_FRAME_HEIGHT);
	cout << "Hight of Frame: " << Frame_Height << endl;

	int Frame_Width = vid_capture.get(CAP_PROP_FRAME_WIDTH);
	cout << "Width of Frame: " << Frame_Width << endl;
	
	Size frame_size(Frame_Width, Frame_Height);
    VideoWriter output("Record.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'),10, frame_size);

	while (vid_capture.isOpened()){
		Mat frame;
		bool framefound = vid_capture.read(frame);

		if(framefound == true){
            namedWindow("Frame", WINDOW_AUTOSIZE);
			imshow("Frame", frame);
			output.write(frame);
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
	output.release();
	destroyAllWindows();
	return 0;
}