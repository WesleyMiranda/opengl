#include<SDL2/SDL.h>

const int LARGURA=800;
const int ALTURA=600;

SDL_Window *janela = NULL;

int main(int argc, char *argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	janela = SDL_CreateWindow( "UFMT - ICAT - Eng.Mecanica", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		LARGURA, ALTURA, 
		SDL_WINDOW_SHOWN );	
	SDL_Delay(5000);
	SDL_DestroyWindow(janela);
	SDL_Quit();	
}
