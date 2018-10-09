#include <SDL2/SDL.h>
#include<iostream>
using namespace std;

// -lmingw32 -lSDL2main -lSDL2

 

//Screen dimension constants
const int LARGURA = 800;
const int ALTURA = 600;


int main(int argc, char *argv[])
{
	//JANELA
	SDL_Window* janela = NULL;
	
	//A superfície dentro da janela
	SDL_Surface* tela = NULL;

	//Inicializa  SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout<< "SDL nao inicializou corretamente! SDL_Error: %s\n"<< SDL_GetError()<<endl ;
	}
	else
	{
		//Criar Janela
		janela = SDL_CreateWindow( "UFMT - Eng.Mecanica - ICAT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGURA, ALTURA, SDL_WINDOW_SHOWN );
		if( janela == NULL )
		{
			cout<< "Janela nao foi criada! SDL_Error: "<< SDL_GetError()<<endl;
		}
		else
		{
			//Coloca a tela na janela
			tela = SDL_GetWindowSurface( janela );

			//Colorir a tela
			SDL_FillRect( tela, NULL, SDL_MapRGB( tela->format, 0, 0, 0) );
			
			//Atualizar a janela
			SDL_UpdateWindowSurface( janela );

			//Espera 5 segundos
			SDL_Delay( 5000 );
			
		}//se a janela foi criada
	}//se SDL inicializou corretamente

	//Destroy window
	SDL_DestroyWindow( janela );

	SDL_Quit();
	return 0;
}
