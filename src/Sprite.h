#ifndef _SPRITE_H
#define _SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "Component.h"

using namespace std;

class Sprite : public Component{

private:
  SDL_Texture* texture;
  int width;
  int height;
  SDL_Rect clipRect;

public:
  Sprite(GameObject& associated);
  Sprite(GameObject& associated, string file);
  ~Sprite();
  void Open(string file);
  void SetClip(int x, int y, int w, int h);
  void Render(int x, int y);
  int GetWidth();
  int GetHeight();
  bool IsOpen();
  void Update(float dt);
  void Render();
  bool Is(string type);
};

#endif
