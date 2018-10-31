#include<opencv2\opencv.hpp>

using namespace cv;

int main()
{
	Mat img = imread("koala.jpg");
	Mat copia = img.clone();
	Mat cinza;
	cvtColor(copia, cinza, CV_RGB2GRAY);

	for (int linha = 0; linha < cinza.rows; linha++)
		for (int coluna = 0; coluna < cinza.cols; coluna++)
		{
			unsigned char valor = cinza.at<unsigned char>(linha, coluna);
			cinza.at<unsigned char>(linha, coluna) = valor * 0.30;
		}

	for (int linha = 0; linha < cinza.rows; linha++)
		for (int coluna = 0; coluna < cinza.cols; coluna++)
		{
			Vec3b canal = copia.at<Vec3b>(linha, coluna);
			canal[0] = 0;// tirar o Azul da imagem BGR c[0]=Azul c[1]=Verde c[2]=Vermelho
			copia.at<Vec3b>(linha, coluna) = canal;
		}

	imshow("GrayScale", cinza);
	imshow("Copia", copia);
	waitKey(0);
	return 0;
}