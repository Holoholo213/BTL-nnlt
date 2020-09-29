// Hello World.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

int main()
{
	string path = "E:/Pics/Peach cat/images.jpg";
	Mat image = imread(path);
	if (image.empty())
	{
		cout << "Could not open image" << endl;
		system("pause"); //wait for any key pressed
	}
	String windowName = "Hello World";
	namedWindow(windowName, WINDOW_AUTOSIZE); //create a window
	imshow(windowName, image); //show image inside window
	waitKey(0); //wait for any key
	//destroyWindow(windowName);


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
