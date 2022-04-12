#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
Mat C_img;
Point p1, p2;
extern int c = 0;
void on_mouse(int event, int x, int y, int flags, void*);

int main(void)
{
	img = imread("dog.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", on_mouse);

	imshow("img", img);
	waitKey();

	return 0;
}

void showNewImg() {
	int wdth = p2.x - p1.x;
	int hgt = p2.y - p1.y;
	Rect roi(p1.x, p1.y, wdth, hgt);
	Mat C_image= img.clone();
	/*테두리 넣기*/
	rectangle(C_image, Rect(Point(p1.x-1, p1.y-1), Point(p2.x+1, p2.y+1)), Scalar(0, 0, 255), 1, 8, 0);
	/*문자입력*/
	putText(C_image, "DOG", Point(144, 144),FONT_HERSHEY_SIMPLEX,1,Scalar(0,0,0));
	Mat newimg = C_image(roi);

	Scalar white(255, 255, 255);
	newimg = white - newimg;
	imshow("img",C_image);
}

void on_mouse(int event, int x, int y, int flags, void*)
{
	if (event == EVENT_LBUTTONDOWN && c == 0) {
		p1 = Point(x, y);
		cout << "1 EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
		c++;
	}
	else if (event == EVENT_LBUTTONDOWN && c == 1) {
		p2 = Point(x, y);
		cout << "2 EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
		c--;
		showNewImg();
		
	}
	
}