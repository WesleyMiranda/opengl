#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>

using namespace cv;
using namespace std;

int Masc(uchar V[2]);
uchar Grad(uchar X[2], uchar Y[2]);
const uchar Tresh = 8;

int main()
{

	VideoCapture cap(0);
	
	while (char(waitKey(1)) != 'q')
	{
		Mat frame;
		cap >> frame;
		cvtColor(frame, frame, CV_RGB2GRAY);
		frame = Blur(frame);

		if (frame.empty())
		{
			cout << "Video over" << endl;
			break;
		}

		imshow("Video", frame);
	}
	
	return 0;
	

}


uchar Grad(uchar X[2], uchar Y[2])
{
	int x = Masc(X);
	int y = Masc(Y);
	return (uchar)pow(x*x + y*y, 0.5);
	
}

int Masc(uchar V[2])
{
	short M[2];

	M[0] = 1;
	M[1] = -1;

	return  abs(V[0] * M[0] + V[1] * M[1]);
}