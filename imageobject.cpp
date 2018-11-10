#include "imageobject.h"
#include <SDL2/SDL.h>
#include <iostream>

ImageObject::ImageObject(std::string name, SDL_Renderer* rend, SDL_Surface * surface, bool has_position){
  object_name = name;
  object_surface = surface;
  object_texture = SDL_CreateTextureFromSurface(rend, surface);
  if (!object_texture){
    std::cout << name + ": " + SDL_GetError() << std::endl;
  }
  this->has_position = has_position;
  if (has_position){
    object_rectangle = new SDL_Rect();
  }
}

SDL_Rect* ImageObject::get_rect(){
  return object_rectangle;
}

SDL_Texture* ImageObject::get_texture(){
  return object_texture;
}

void ImageObject::destroy(){
  if (object_rectangle){
    std::cout << object_name + ": rectangle deleted\n";
    delete object_rectangle;
  }

  if (object_surface){
    SDL_FreeSurface(object_surface);
    std::cout << object_name + ": Object surface freed\n";
  }

  if (object_texture) {
    SDL_DestroyTexture(object_texture);
    std::cout << object_name + ": Object texture destroyed\n";
  }
}
