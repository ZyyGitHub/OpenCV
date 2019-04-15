#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <io.h>
using namespace std;

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
using namespace cv;


string FileLocation(string Location, int num, string EndLocationType);    //获取摄像头图片的函数


int main(int argc, const char * argv[]) {

	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		return -1;
	}
	namedWindow("video");
	for (; ;)
	{
		Mat frame;
		cap >> frame;
		imshow("Video", frame);
		if (waitKey(30) >= 0)
		{
			break;
		}
	}
	cap.release();
#if 0
	//使用摄像头获取图片
	//程序说明：1.按下ESC程序退出，2.按下空格键截取图像

	Mat srcImage;
	char c;
	int temp = 0;        //计数器
	VideoCapture cam(0);
	if (!cam.isOpened())
		exit(0);
	namedWindow("【拍摄中......】");
	while (true) {
		cam >> srcImage;
		imshow("【拍摄中......】", srcImage);
		c = waitKey(30);
		if (c == ' ')
		{
			imwrite(FileLocation("image/", temp, ".jpg"), srcImage);
			temp++;
		}
		if (c == 27)
			break;
	}
#endif
	return 0;
}


string FileLocation(string Location, int name, string EndLocationType) {
	string imageFileName;
	std::stringstream StrStm1;
	StrStm1 << name + 1;
	StrStm1 >> imageFileName;
	imageFileName += EndLocationType;
	return Location + imageFileName;
}



#if 0
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

const char* keys = {
	"{help h usage ? || print this message}"
	"{@vedio || Vedio file, if not defined try to use webcamera}"
};

int main(int argc, char **argv)
{
#if 0
	CommandLineParser parser(argc, argv, keys);
	parser.about("Chapter 2. v1.1.0");

	if (parser.has("help"))
	{
		parser.printMessage();
		return 0;
	}
	String videoFile = parser.get<String>(0);

	if (!parser.check())
	{
		parser.printErrors();
		return 0;
	}
	VideoCapture cap;
	if (videoFile != " ")
	{
		cap.open(videoFile);
	}
	else
		cap.open(0);
	if (!cap.isOpened())
	{
		return -1;
	}
	namedWindow("video", 1);
	for (; ;)
	{
		Mat frame;
		cap >> frame;
		imshow("Video", frame);
		if (waitKey(30) >= 0)
		{
			break;
		}
	}
	cap.release();
#endif
	return 0;
}
#endif