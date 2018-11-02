#include <opencv2\opencv.hpp>

using namespace cv;

/*
unsigned char media(unsigned char n1, unsigned char n2, unsigned char n3)
{
	return (n1 + n2 + n3) / 3; 
	
	// aqui todas as cores contribuem igualmente
	// DICA: Estudar o fenômeno de Luz e Cores. O que é luz? O que é Cor? Por que vc enxerga verde, vermelho,...? 
	   Em física isto fica algo como um fenômeno produzido por ondas eletromagnéticas que possuem 
	   // Velocidade, Comprimento de Onda e Frequencia
	   // Seria então algo assim(me perdoem os físicos)
	   //Objetos em azul "emitem" ondas(radiações) com determinada frequencia, velocidade e comprimento de onda
	
	Vermelho Comprimento de onda = 635-700nm  Freq= 430–480 THz
	Verde    Comprimento de onda = 520-560nm  Freq= 540–580 THz
	Azul     Comprimento de onda =  450-495nm Freq=606–668 THz
}
*/ 


uchar mediaPonderada(uchar azul, uchar verde, uchar vermelho) // novo
{
	return (uchar) 0.3*vermelho + 0.6*verde + 0.1*azul; //30%vermelho, 60%verde, 10%azul		
}

Mat grayScale(Mat M)
{
	Mat gray(M.rows, M.cols, CV_8UC1);
	for (int linha = 0; linha < M.rows; linha++)
		for (int coluna = 0; coluna < M.cols; coluna++)
		{
			uchar azul = M.at<Vec3b>(linha, coluna)[0];
			uchar verde = M.at<Vec3b>(linha, coluna)[1];
			uchar vermelho = M.at<Vec3b>(linha, coluna)[2];
			gray.at<uchar>(linha, coluna) = mediaPonderada(azul, verde, vermelho);
			//gray.at<uchar>(linha, coluna) = media(M.at<Vec3b>(linha, coluna)[0], M.at<Vec3b>(linha, coluna)[1], M.at<Vec3b>(linha, coluna)[2]);
		}
	return gray;
}

int main()
{
	Mat img = imread("koala.jpg");
	img = grayScale(img);
	imshow("GrayScale", img);

	waitKey(0);
	return 0;
}
