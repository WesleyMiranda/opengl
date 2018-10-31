#include <opencv2\opencv.hpp>

using namespace cv;

unsigned char media(unsigned char n1, unsigned char n2, unsigned char n3)
{
	return (n1 + n2 + n3) / 3;
}

Mat grayScale(Mat M)
{
	Mat gray(M.rows, M.cols, CV_8UC1);
	for (int linha = 0; linha < M.rows; linha++)
		for (int coluna = 0; coluna < M.cols; coluna++)
		{
			gray.at<uchar>(linha, coluna) = media(M.at<Vec3b>(linha, coluna)[0], M.at<Vec3b>(linha, coluna)[1], M.at<Vec3b>(linha, coluna)[2]);
		}
	return gray;
}

int main()
{
	Mat img = imread("space.jpg");
	img = grayScale(img);
	imshow("GrayScale", img);

	waitKey(0);
	return 0;
}