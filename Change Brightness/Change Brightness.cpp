// Change Brightness.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat RandomColorImage(Mat image)
{
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			image.at<Vec3b>(i, j)[0] = rand() % 255;
			image.at<Vec3b>(i, j)[1] = rand() % 255;
			image.at<Vec3b>(i, j)[2] = rand() % 255;
		}
	}
	return image;
}

int main()
{
	Mat image(500, 500, CV_8UC3);

	imshow("Test image", image);
	waitKey(0);

	Mat randomColorImage = RandomColorImage(image);
	imshow("Random Color",randomColorImage);
	bool isSuccess = imwrite("Random Color.bmp", randomColorImage);
	if (!isSuccess)
	{
		cout << "Can't save Random Color image" << endl;
	}
	waitKey(0);

	String path = "E:/Pics/Peach cat/images.jpg";
	Mat peachCatImg = imread(path);
	imshow("Peach Cat", peachCatImg);
	waitKey(0);

	Mat brighterPeachCat;
	peachCatImg.convertTo(brighterPeachCat, -1, 1, 50);
	imshow("Brighter", brighterPeachCat);
	bool brighterSuccess = imwrite("Brighter Peach Cat.bmp", brighterPeachCat);
	if (!brighterSuccess)
	{
		cout << "Can't save Peach Cat" << endl;
	}
	waitKey(0);

	Mat greyImage;
	cvtColor(peachCatImg, greyImage, COLOR_BGR2GRAY);
	imshow("Grey scale", greyImage);
	bool greySuccess = imwrite("Grey scale.bmp", greyImage);
	if (!greySuccess)
	{
		cout << "Can't save grey scale image" << endl;
	}
	waitKey(0);

	String path1 = "E:/Her/purp dress.jpg";
	Mat Her = imread(path1);
	if (Her.empty())
	{
		cout << "Can't load image" << endl;
		return -1;
	}
	Mat contrastIncrease;
	Her.convertTo(contrastIncrease, -1, 2, 0);
	imshow("Peach cat with increased contrast", contrastIncrease);
	bool isContrast = imwrite("Increase contrast.bmp", contrastIncrease);
	if (!isContrast)
	{
		cout << "Can't save contrast image" << endl;
	}
	waitKey(0);
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
