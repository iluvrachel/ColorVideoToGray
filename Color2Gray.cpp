#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "opencv2/opencv.hpp"
#include<opencv2\core\core.hpp>  
#include<opencv2\imgproc\imgproc.hpp>  
#include<opencv2\highgui\highgui.hpp>  
#include<iostream>  
#include<stdio.h>  
#include <time.h> 

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{


	cv::VideoCapture capture("E:\\VS2015\\myProject\\RussianEVM\\RussianEVM\\data\\003.mp4");//读入视频文件
										   //cv::Mat size_img;
										   //capture.read(size_img);
	double rate = capture.get(CV_CAP_PROP_FPS);
	int w = capture.get(CV_CAP_PROP_FRAME_WIDTH);
	int h = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
	bool stop(false);
	Mat frame;
	std::cout << w;
	std::cout << h;
										   /*视频写入.avi*/
	cv::VideoWriter w_cap("gray003.avi", -1, rate, cv::Size(w, h),0);//初始化
//第五个参数isColor，在输出灰度图像时要手动设为0，表示输出单通道
//否则会报assertion failed的错误

	if (!capture.isOpened()) {
		std::cout << "fail to load video";
		return 1;
	}


	namedWindow("Gray Video");
	int delay = 1000 / rate;

	while (capture.read(frame))
	{
		Mat result;
		cvtColor(frame,result,CV_BGR2GRAY);
		//threshold(result, result, 128, 255, THRESH_BINARY);
		imshow("Gray Video", result);
		cv::resize(result, result, cv::Size(w ,h));
		w_cap.write(result);
		if (waitKey(delay) >= 0)
			break;

	}

	return 0;
}
