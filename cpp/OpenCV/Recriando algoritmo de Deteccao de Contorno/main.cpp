#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>

using namespace cv;
using namespace std;

int Masc(uchar V[2]);
uchar Grad(uchar X[2], uchar Y[2]);
Mat Blur(Mat M);
Mat Threshold(Mat M);
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

Mat Blur(Mat M)
{
	uchar X[2], Y[2];
	Mat Aux(M.rows, M.cols, CV_8U);

	for (int i = 0; i < M.rows; i++)
	{
		for (int j = 0; j < M.cols; j++)
		{
			if (i == 0 || i == M.rows - 1|| j == 0 || j == M.cols - 1)
			{
				Aux.at<uchar>(i, j) = 0;
			}
			else
			{
				X[0] = M.at<uchar>(i, j - 1);
				X[1] = M.at<uchar>(i, j + 1);
				Y[0] = M.at<uchar>(i - 1, j);
				Y[1] = M.at<uchar>(i + 1, j);

				Aux.at<uchar>(i, j) = Grad(X, Y);
			}
		}
	}

	Aux = Threshold(Aux);

	return Aux;
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

Mat Threshold(Mat M)
{
	uchar aux;

	for (int i = 0; i < M.rows; i++)
	{
		for (int j = 0; j < M.cols; j++)
		{
			aux = M.at<uchar>(i, j);
			if (aux >= Tresh)
				M.at<uchar>(i, j) = 0;
			else
				M.at<uchar>(i, j) = 255;
		}
	}
	return M;
}