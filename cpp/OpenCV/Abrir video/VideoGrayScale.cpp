#include <opencv2/opencv.hpp>

using namespace cv;

uchar media9(uchar n1, uchar n2, uchar n3, uchar n4, uchar n5, uchar n6, uchar n7, uchar n8, uchar n9)
{
	return (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9) / 9;
}

Mat suav(Mat M)
{
	Mat Aux(M.rows, M.cols, CV_8U);
	for (int i = 1; i < M.rows-1; i++)
		{
			for (int j = 1; j < M.cols-1; j++)
			{
			Aux.at<uchar>(i, j) = media9(M.at<uchar>(i, j), M.at<uchar>(i, j - 1), M.at<uchar>(i, j + 1), M.at<uchar>(i - 1, j), M.at<uchar>(i - 1, j - 1), M.at<uchar>(i - 1, j + 1), M.at<uchar>(i + 1, j), M.at<uchar>(i + 1, j - 1), M.at<uchar>(i + 1, j + 1));
			}
		}
	return Aux;
}

int main()
{
	VideoCapture vcap(0);

	int largura = vcap.get(CV_CAP_PROP_FRAME_WIDTH);
	int altura = vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
	VideoWriter video("video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, Size(largura, altura), false);

	while (char(waitKey(1)) != 'q')
	{
		Mat frame;
		vcap >> frame;

		cvtColor(frame, frame, CV_RGB2GRAY);

		for(int i=0; i<5; i++)
		frame = suav(frame);

		imshow("Video", frame);
		video << frame;
	}
	return 0;
}