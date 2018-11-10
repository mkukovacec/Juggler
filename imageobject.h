#ifndef __IMAGE_OBJECT_H__
#define __IMAGE_OBJECT_H__
#include <SDL2/SDL.h>
#include <string>

class ImageObject {
private:
  std::string object_name;
  SDL_Surface* object_surface;
  SDL_Texture* object_texture;
  SDL_Rect* object_rectangle = NULL;
  bool has_position;
public:
  ImageObject(std::string name, SDL_Renderer* rend, SDL_Surface * surface, bool has_position);
  SDL_Rect* get_rect();
  SDL_Texture* get_texture();
  void destroy();
};

#endif
