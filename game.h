#ifndef __GAME_H__
#define __GAME_H__

#include <cstdio>
#include <SDL2/SDL.h>
#include "window.h"

class Game {
private:
  int is_finished = 0;
  Window * window;
public:

  Game(Window * window){
    this->window = window;
    this->play_game();
  }
  void play_game();
};


#endif
