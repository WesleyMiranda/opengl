#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat img = imread("olho.png");
	Mat blur;
	GaussianBlur(img, blur, Size(5, 5), 0);

	Mat result;
	addWeighted(img, 2, blur, -1, 0, result);
	

	imshow("Imagem", img);
	imshow("Result", result);
	waitKey(0);
	return 0;
}