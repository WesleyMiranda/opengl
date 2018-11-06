#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	
	VideoCapture cap("video.avi");

	
	while (char(waitKey(1)) != 'q')
	{
		Mat frame;
		cap >> frame;
		if (frame.empty())
			break;

		imshow("Video", frame);
	}
	
	return 0;
}