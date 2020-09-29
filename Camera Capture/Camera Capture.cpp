// Camera Capture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture camera(0);

	if (camera.isOpened() == false)
	{
		cout << "Can't find camera" << endl;
		system("pause");
		return -1;
	}
	else
	{
		double width = camera.get(CAP_PROP_FRAME_WIDTH);
		double height = camera.get(CAP_PROP_FRAME_HEIGHT);
		cout << "Resolution: " << width << " x " << height << endl;

		string windowName = "Camera Capt";
		namedWindow(windowName, 1);

		bool isRunning = true;
		while (isRunning)
		{
			Mat frame;
			bool isSuccess = camera.read(frame);

			if (isSuccess == false)
			{
				cout << "Camera Dc" << endl;
				system("pause");
				isRunning = false;
			}
			else
			{
				imshow(windowName, frame);
				if (waitKey(30) == 27)
				{
					cout << "Forced stop" << endl;
					isRunning = false;
				}
			}
		}

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
