#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

Window::Window() {
  this->initialize_graphics();
  this->initialize_render();
  this->initialize_surface();
  this->initialize_texture();
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

void Window::initialize_surface() {
  soccer_surface = IMG_Load("resources/soccer.png");
  background_surface = IMG_Load("resources/background.png");
  if (!soccer_surface || !background_surface) {
      printf("error creating surface\n");
      this->destroy();
  }
}

void Window::initialize_texture() {
  soccer_texture = SDL_CreateTextureFromSurface(rend, soccer_surface);
  background_texture = SDL_CreateTextureFromSurface(rend, background_surface);
  if (!soccer_texture || !background_texture)
  {
      printf("error creating texture: %s\n", SDL_GetError());
      this->destroy();
  }
}

void Window::resize(int width, int height) {
  SDL_SetWindowSize(win, width, height);
}

void Window::refresh_window(SDL_Rect dest, int score) {
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, background_texture, NULL, NULL);
  SDL_RenderCopy(rend, soccer_texture, NULL, &dest);
  SDL_RenderPresent(rend);
}

void Window::destroy() {
  if (soccer_surface){
    SDL_FreeSurface(soccer_surface);
  }
  if (background_surface){
    SDL_FreeSurface(background_surface);
  }
  if (soccer_texture) {
    SDL_DestroyTexture(soccer_texture);
    printf("Soccer texture destroyed\n");
  }
  if (background_texture) {
    SDL_DestroyTexture(soccer_texture);
    printf("Background texture destroyed\n");
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
