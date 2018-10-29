#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"
#include "window.h"

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

void Game::play_game() {
  int game_finish = 0;
  SDL_Rect dest;

  window->query_texture(dest);
  dest.w = 40;
  dest.h = 40;
  dest.x = 280;
  dest.y = 400;

  float vx = 0.0;
  float vy = -250.0;

  float grav = 9.81;

  float x_pos = 280;
  float y_pos = 400;
  //
  while (game_finish != 1){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT)
        {
            window->destroy();
            exit(0);
        }
    }

    // get cursor position relative to window
    int mouse_x, mouse_y;
    int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

    vy+=9.81;
    // reverse velocity if mouse button 1 pressed
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        // vx = -400.0;
        vy = -400.0;
    }

    y_pos += vy / 60;
    x_pos += vx / 60;

    // collision detection with bounds
    if (y_pos <= 0) y_pos = 0;

    if (y_pos >= WINDOW_HEIGHT - dest.h) {
      y_pos = WINDOW_HEIGHT - dest.h;
      printf("GAME OVER");
      game_finish=1;
    }
    // set the positions in the struct
    dest.y = (int) y_pos;
    dest.x = (int) x_pos;

    window->refresh_window(dest);
    SDL_Delay(1000/60);
  }

}
