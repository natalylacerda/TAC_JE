#ifndef _STATE_H
#define _STATE_H

#include <vector>
#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Music.h"
#include "GameObject.h"

class State{

private:
  Sprite bg;
  Music music;
  void Input();
  void AddObject(int mouseX, int mouseY);
  bool quitRequested;
  std::vector<std::unique_ptr<GameObject>> objectArray;

public:
  State();
  ~State();
  bool QuitRequested();
  void LoadAssets();
  void Update(float dt);
  void Render();
};

#endif
