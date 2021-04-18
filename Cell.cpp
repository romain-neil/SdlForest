//
// Created by Romain Neil on 18/04/2021.
//

#include "Cell.h"

Cell::Cell(int x, int y, CellStatus status) : m_x(x), m_y(y), m_rect({x, y, BLOCK_SIZE, BLOCK_SIZE}), m_status(status) {}

void Cell::draw(SDL_Renderer *renderer, SDL_Window *window) {
	switch(m_status) {
		case YOUNG:
			SDL_SetRenderDrawColor(renderer, 0, 0x15, 0, 0);
			break;
		case MATURE:
			SDL_SetRenderDrawColor(renderer, 0x01, 0x93, 0, 0);
			break;
		case START_BURNING:
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0, 0);
			break;
		case BURNING:
			SDL_SetRenderDrawColor(renderer, 0xFF, 0, 0, 0);
			break;
		case END_BURNING:
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xA5, 0x00, 0);
			break;
		case ASHES:
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			break;
	}

	SDL_RenderFillRect(renderer, &m_rect);
}
