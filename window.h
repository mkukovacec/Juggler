#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL2/SDL.h>

class Window {
private:
  SDL_Window* win;
  SDL_Renderer* rend;
  SDL_Surface* soccer_surface;
  SDL_Texture* soccer_texture;
  SDL_Surface* background_surface;
  SDL_Texture* background_texture;

public:
  Window();
  void initialize_graphics();
  void initialize_render();
  void initialize_surface();
  void initialize_texture();
  void resize(int width, int height);
  void refresh_window(SDL_Rect dest, int score);
  void destroy();
};

#endif
