#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL2/SDL.h>
#include "imageobject.h"
#include <vector>
#include <string>

class Window {
private:
  SDL_Window* win;
  SDL_Renderer* rend;
  std::vector<ImageObject> objects;

public:
  Window();
  void initialize_graphics();
  void initialize_render();
  SDL_Rect* add_object(std::string name, SDL_Surface * surface, bool has_position);
  void resize(int width, int height);
  void refresh_window(int score);
  void destroy();
};

#endif
