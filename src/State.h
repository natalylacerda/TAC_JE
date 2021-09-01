#ifndef _STATE_H
#define _STATE_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Music.h"

using namespace std;

class State{

private:
  Sprite bg;
  Music music;
  bool quitRequested;

public:
  State();
  ~State();
  bool QuitRequested();
  void LoadAssets();
  void Update(float dt);
  void Render();
};

#endif
