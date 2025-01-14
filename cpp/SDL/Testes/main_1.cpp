#include <SDL2/SDL.h>
#include<iostream>
// https://www.widgetworx.com/spritelib/
//-lmingw32 -lSDL2main -lSDL2

const int LARGURA = 640;
const int ALTURA = 426;

using namespace std;

bool inicializa();


bool carregaImagem();


void fecha();


SDL_Window* janela = NULL;
	
SDL_Surface* tela = NULL;

SDL_Surface* img = NULL;

bool inicializa()
{
	bool tudoCerto = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout<< "SDL nao inicializou! SDL_Error: "<< SDL_GetError() <<endl;
		tudoCerto = false;
	}
	else
	{
		
		janela = SDL_CreateWindow( "UFMT - ICAT - Eng.Mecanica", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGURA, ALTURA, SDL_WINDOW_SHOWN );
		if( janela == NULL )
		{
			cout<<"Janela nao criada! SDL_Error: "<<SDL_GetError()<<endl;
			tudoCerto = false;
		}
		else
		{
			tela = SDL_GetWindowSurface( janela );
		}
	}

	return tudoCerto;
}

bool carregaImagem()
{
	bool tudoCerto = true;

	//LoadBMP funcao que retorna uma Surface
	img = SDL_LoadBMP( "onca.bmp" );
	if( img == NULL )
	{
		cout<<"Nao foi possivel carregar a imagem "<< "onca.bmp "<<SDL_GetError() <<endl;
		tudoCerto = false;
	}

	return tudoCerto;
}

void fecha()
{
	SDL_FreeSurface( img );
	img= NULL;

	//Fecha Janela
	SDL_DestroyWindow( janela );
	janela = NULL;

	//Encerrar
	SDL_Quit();
}

int main( int argc, char* args[] )
{

	if( !inicializa() )
	{
		cout<<"Falha ao iniciar!"<<endl;
	}
	else
	{
		//Imagem
		if( !carregaImagem() )
		{
			cout<<"Falha ao carregar a imagem!"<<endl;
		}
		else
		{
			// cola img na tela
			SDL_BlitSurface( img, NULL, tela, NULL );
			
			SDL_UpdateWindowSurface( janela );

			SDL_Delay( 5000 );
		}
	}

	
	fecha();

	return 0;
}
