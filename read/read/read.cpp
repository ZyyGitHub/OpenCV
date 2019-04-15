#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//openvc 头文件
#include "opencv2/core.hpp"     
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
using namespace cv;

int main(int argc, char *argv[])
{
	//读图像
	Mat color = imread("C:/Users/ZhangYanyu/Desktop/mao.jpg");
	Mat gray = imread("C:/Users/ZhangYanyu/Desktop/mao.jpg", 0);

	//写图像
	imwrite("maoGray.jpg", gray);

	//通过opencv函数获取相同的像素
	int myRow = color.rows - 1;
	int myCol = color.cols - 1;

	Vec3b pixel = color.at<Vec3b>(myRow, myCol);
	cout << "Pixel value (R G B): (" << (int)pixel[0] << "," << (int)pixel[1] <<
		"," << (int)pixel[2] << ")" << endl;

	imshow("Lean BGR", color);
	imshow("Lean Gray", gray);

	waitKey(0);

	return 0;
}