// Change brightness of Video.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	String path = "E:/Pics/Vid/Haachama Fuck you.mp4";
	VideoCapture video(path);

	if (!video.isOpened())
	{
		cout << "Can't load video" << endl;
		return -1;
	}
	else
	{
		double fps = video.get(CAP_PROP_FPS);
		cout << "Video fps: " << fps << endl;

		bool isRunning = true;
		while (isRunning)
		{
			Mat frame;
			bool isSuccess = video.read(frame);
			if (!isSuccess)
			{
				cout << "End of the video" << endl;
				isRunning = false;
			}
			else
			{
				Mat brighterVideo;
				frame.convertTo(brighterVideo, -1, 1, 50);
				imshow("Brighter Bomman", brighterVideo);

				if (waitKey((int)fps) == 27)
				{
					cout << "Video forced stop" << endl;
					isRunning = false;
				}
			}
		}
		return 0;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
