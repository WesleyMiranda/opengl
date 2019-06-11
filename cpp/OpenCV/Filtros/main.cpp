#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>


using namespace cv;

int main()
{
	Mat img = imread("salt_pepper_noise.png");
	//Mat img = imread("gaussian_noise.png");
	int kernel_size = 5;
	Mat img_medianBlurred;
	Mat img_gaussian;

	//GaussianBlur(img, img_gaussian, Size(kernel_size, kernel_size), 0, 0);
	GaussianBlur(img, img_gaussian, Size(kernel_size, kernel_size),50,50);
	medianBlur(img, img_medianBlurred, kernel_size);

	// Bilateral
	//diameter of the pixel neighbourhood used during filtering
	int diameter = 15;

	double sigmaColor = 80;
	double sigmaSpace = 80;

	Mat img_bilateral;
	bilateralFilter(img, img_bilateral, diameter, sigmaColor, sigmaSpace);


	imshow("Original", img);
	imshow("Median Blur", img_medianBlurred);
	imshow("Gassian Blur", img_gaussian);
	imshow("Bilateral", img_bilateral);
	waitKey(0);
	return 0;
}