#include<iostream>
#include<opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("boy.jpg");
	cout << "Tamanho da Imagem= " <<img.size() << endl;
	// Cria uma Matriz com Zeros com mesma dimensao da Imagem
	Mat mask = Mat::zeros(img.size(), img.type());

	// Agora 
	mask(Range(50, 200), Range(170, 320)).setTo(255);
	
	Mat result;
	bitwise_and(img, mask, result);
	
	/*mat mask2;
	inrange(img, scalar(0, 0, 150), scalar(100, 100, 255), mask2);
	imwrite("maks2.png", mask2);
	*/
	imshow("original", img);
	imshow("Mascara", mask);
	imshow("Resultado", result);

	waitKey(0);
	return 0;
}