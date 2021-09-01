#ifndef _SPRITE_H
#define _SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

class Sprite{

private:
  SDL_Texture* texture;
  int width;
  int height;
  SDL_Rect clipRect;

public:
  Sprite();
  Sprite(string file);
  ~Sprite();
  void Open(string file);
  void SetClip(int x, int y, int w, int h);
  void Render(int x, int y);
  int GetWidth();
  int GetHeight();
  bool IsOpen();
};

#endif
