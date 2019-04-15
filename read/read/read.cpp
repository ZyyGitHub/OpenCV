#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//openvc ͷ�ļ�
#include "opencv2/core.hpp"     
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
using namespace cv;

int main(int argc, char *argv[])
{
	//��ͼ��
	Mat color = imread("C:/Users/ZhangYanyu/Desktop/mao.jpg");
	Mat gray = imread("C:/Users/ZhangYanyu/Desktop/mao.jpg", 0);

	//дͼ��
	imwrite("maoGray.jpg", gray);

	//ͨ��opencv������ȡ��ͬ������
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