// Save Images and Videos to File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

int main()
{
	String path = "E:/Her/purp dress.jpg";
	Mat image = imread(path);
	if (image.empty())
	{
		cout << "Can't load image" << endl;
		return -1;
	}
	else
	{
		int width = image.cols;
		int height = image.rows;

		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;

		Rect cropRegion(width / 4, height / 6, width / 2, height / 2);
		Mat newImage;
		newImage = image(cropRegion);

		String newImgPath = "E:/Work work/NNLT/Btl/Hello World/Save Images and Videos to File/Demo Image.bmp";
		

		bool isSuccess = imwrite(newImgPath, newImage);
		if (!isSuccess)
		{
			cout << "Can't save image" << endl;
			return -1;
		}
		else
		{

			cout << "Image saved" << endl;
		}

		String windowName = "Demo image";
		namedWindow(windowName, 1);
		imshow(windowName, newImage);
		waitKey(0);
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
