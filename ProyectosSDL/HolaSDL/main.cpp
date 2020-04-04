
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "SDLApp.h"
using namespace std;


int main(int argc, char* argv[]){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SDLApp g(1280, 720);
	g.run();
	g.closeSDL();
	//_CrtDumpMemoryLeaks(); //esta instruccion le vale a Diego para ver la basura. No quiteis el comentario pls T_T
	return 0;
}