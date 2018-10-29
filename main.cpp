#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "game.h"

int main(void) {
  Window* w = new Window();

  new Game(w);

  SDL_Delay(500);
  w->destroy();
  return 0;
}
