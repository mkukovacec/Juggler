#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

Window::Window() {
  this->initialize_graphics();
  this->initialize_render();
}

void Window::initialize_graphics(){
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
      printf("error initializing SDL: %s\n", SDL_GetError());
      return;
  }

  win = SDL_CreateWindow("Juggler", SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     WINDOW_WIDTH, WINDOW_HEIGHT,0);
  if (!win) {
      printf("error creating window: %s\n", SDL_GetError());
      this->destroy();
  }
}

void Window::initialize_render() {
  Uint32 render_flags = SDL_RENDERER_ACCELERATED;
  rend = SDL_CreateRenderer(win, -1, render_flags);
  if (!rend) {
    printf("error creating renderer: %s\n", SDL_GetError());
    this->destroy();
  }
}

SDL_Rect* Window::add_object(std::string name, SDL_Surface * surface, bool has_position){
  ImageObject imageobject(name, rend, surface, has_position);
  objects.push_back(imageobject);
  return imageobject.get_rect();
}

void Window::resize(int width, int height) {
  SDL_SetWindowSize(win, width, height);
}

void Window::refresh_window(int score) {
  SDL_RenderClear(rend);
  for (int i=0; i<objects.size(); i++){
    SDL_RenderCopy(rend, objects[i].get_texture(), NULL, objects[i].get_rect());
  }
  SDL_RenderPresent(rend);
}

void Window::destroy() {
  for (int i=0; i<objects.size(); i++){
    objects[i].destroy();
  }
  if (rend){
    SDL_DestroyRenderer(rend);
    printf("Renderer destroyed\n");
  }
  if (win) {
    SDL_DestroyWindow(win);
    printf("Window destroyed\n");
  }

  SDL_Quit();
}
