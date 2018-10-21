#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
private:
  SDL_Window* win;
  SDL_Renderer* rend;
  SDL_Surface* surface;
  SDL_Texture* tex;
public:
  Window();
  void initialize_graphics();
  void initialize_render();
  void initialize_surface();
  void initialize_texture();
  void resize(int width, int height);
  void query_texture(SDL_Rect dest);
  void refresh_window(SDL_Rect dest);
  void destroy();
};

#endif
