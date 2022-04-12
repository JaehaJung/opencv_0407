#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void mask_setTo();
void mask_copyTo();
void time_inverse();
void useful_func();

int main(void)
{
	mask_copyTo();
	return 0;
}

void mask_setTo()
{
	Mat src = imread("lenna.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);

	if (src.empty() || mask.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	src.setTo(Scalar(0, 255, 255), mask);

	imshow("src", src);
	imshow("mask", mask);

	waitKey();
	destroyAllWindows();
}

void mask_copyTo()
{
	Mat src = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("field.bmp", IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	TickMeter tm;
	tm.start();
	src.copyTo(dst, mask);
	tm.stop();
	cout << "time" << tm.getTimeMilli() << "ms." << endl;

	imshow("src", src);
	imshow("dst", dst);
	imshow("mask", mask);

	waitKey();
	destroyAllWindows();
}
