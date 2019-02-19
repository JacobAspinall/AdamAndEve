#include "Canvas.h"
#include "Window.h"



Canvas::Canvas(Window& window)
	:parentWindow{ window }, width{ window.width }, height{ window.height }
{
	renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
}


Canvas::~Canvas()
{
}


void Canvas::draw(int x, int y, Texture& t, int clipCode) {


	
	SDL_Rect clipLocation = t.getClip(clipCode);

	SDL_Rect renderQuad = { x, y, clipLocation.w, clipLocation.h};

	//Render texture to screen
	if(t.texture != NULL)
		SDL_RenderCopy(renderer, t.texture, &clipLocation, &renderQuad);

}

void Canvas::drawRectangle(int x, int y, int width, int height) {

	SDL_Rect rectLocation = { x, y, width, height };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x0F);
	SDL_RenderFillRect(renderer, &rectLocation);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

}
