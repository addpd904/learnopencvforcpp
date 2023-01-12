#include<opencv2\opencv.hpp>
#include<iostream>
#include<string>
using namespace std;
using namespace cv;
//a.inRange:image binaryzation
void funciran() {
	Mat src = imread("E:/programme/cpp/practice/image/photo.jpg");
	Mat m1;
	//1.understand the func
	//we have better converte the color space to HSV then start image binaryzation
	cvtColor(src, m1, COLOR_RGB2HSV);
	imshow("mywin1", m1);
	Mat m2;
	//binaryzation
	//Scalar(100,43,46) and Scalar(124, 255, 255) is a range.pixel that is in the range will be set 1.
	inRange(m1,Scalar(100,43,46),Scalar(124, 255, 255) ,m2);
	imshow("mywin2", m2);
	//2.app change background
	Mat m3 = Mat::zeros(src.size(), src.type());
	m3 = Scalar(30, 30, 255);
	copyTo(src, m3, m2);
	imshow("mywin3", m3);
	waitKey(0);
}
//b.statistics math feature:mean ,standard deviation,min,max
void ufncsta1() {
	Mat src = imread("E:/programme/cpp/practice/image/photo.jpg");
	double min, max;
	Point minLoc, maxLoc;
	vector<Mat> v1;
	split(src, v1);
	//max and min:just can pass single channel image
	minMaxLoc(v1[0], &min, &max, &minLoc, &maxLoc, Mat());
	//mean standard deviation
	Mat mean, stddec;
	meanStdDev(src, mean, stddec);
}
//c.random and color
void funcran() {
	Mat canvas = imread("E:/programme/cpp/practice/image/photo.jpg");
	RNG ran(1232);
	cout << canvas.size();
	//generate uniform distribution
	while (true)
	{
		int k=waitKey(30);
		if (k == 27) {
			break;
		}
		int x1 = ran.uniform(0, 480);
		int y1 = ran.uniform(0, 640);
		int x2 = ran.uniform(0, 480);
		int y2 = ran.uniform(0, 640);
		int r = ran.uniform(0, 255);
		int g = ran.uniform(0, 255);
		int b = ran.uniform(0, 255);
		canvas= imread("E:/programme/cpp/practice/image/photo.jpg");
		line(canvas, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 4, LINE_8);
		imshow("mywin1", canvas);
	}
}
//d.normalize
int main() {
	//funciran();
	funcran();
	system("pause");
	return 0;
}