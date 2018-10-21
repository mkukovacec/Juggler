#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "window.h"

int main(void) {
  Window* w = new Window();

  SDL_Rect dest;
  w->query_texture(dest);
  dest.w /= 4;
  dest.h /= 4;

  dest.w = (640 - dest.w) / 14;
  dest.h = (480 - dest.h) / 12;

  dest.x = 280;
  dest.y = 400;

  w->refresh_window(dest);

  SDL_Delay(5000);
  w->destroy();
  return 0;
}
