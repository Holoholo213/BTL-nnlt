#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture camera(0);
	camera.open(0);
	if (!camera.isOpened())
	{
		cout << "Can't load camera" << endl;
		return -1;
	}
	else
	{
		String filepath = "E:/Work work/NNLT/Btl/Hello World/Save Images and Videos to File/Demo Video Capture.avi";
		double height = camera.get(CAP_PROP_FRAME_HEIGHT);
		double width = camera.get(CAP_PROP_FRAME_WIDTH);
		Size frameSize(height, width);
		waitKey(1000);

		VideoWriter videoWriter(filepath, VideoWriter::fourcc('H', '2', '6', '4'), 10, frameSize, true);

		if (!videoWriter.isOpened())
		{
			cout << "Can't save video" << endl;
			return -1;
		}
		else
		{
			bool isRunning = true;
			while (isRunning)
			{
				Mat frame;
				bool isSuccess = camera.read(frame);
				if (!isSuccess)
				{
					cout << "Can't load webcam" << endl;
					isRunning = false;
					return -1;
				}
				else
				{
					waitKey(1000);
					videoWriter.write(frame);
					imshow("Webcam feed", frame);
					if (waitKey(10) == 27)
					{
						cout << "Video forced stopped" << endl;
						isRunning = false;
						return -1;
					}
				}

			}
			videoWriter.release();
			return 0;
		}
	}

}