#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;


Mat img = imread("lena.jpg");
Mat result_gauss;
Mat result_salt_pepper;

void submat(Mat image)
{
	Rect box;
	box.width = 3;
	box.height = 3;
	box.x = image.cols/2;
	box.y = image.rows/2;
	Mat subMat(image, box);
	cout << subMat << endl;
}

void gauss()
{
	Mat noise = img.clone();
	randn(noise, 100, 30);

	addWeighted(img, 1, noise, 1, 0, result_gauss);

	cout << "--- Ruido Gaussiano---" << endl;
	submat(noise);
	cout << "--- Resultado---" << endl;
	submat(result_gauss);

}


int main()
{
	
	cout << "--- Imagem ---" << endl;
	submat(img);
	
	gauss();
	salt_pepper();
	
	imshow("Imagem", img);
	imshow("Gaussiano", result_gauss);
	imshow("Salt_Pepper", result_salt_pepper);

	waitKey(0);
	
	return 0;
}