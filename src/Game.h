#ifndef _GAME_H
#define _GAME_H

#include "State.h"
#include <string>
#include <SDL2/SDL.h>

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_TTF
#define INCLUDE_SDL_NET
#include "SDL_include.h"

using namespace std;

class Game{

private:
  Game(string title, int width, int height);
  
public:
  ~Game();
  void Run();
  SDL_Renderer* GetRenderer();
  State& GetState();
  static Game& GetInstance();

  static Game* instance;
  SDL_Window* window;
  SDL_Renderer* renderer;
  State* state;
};

#endif
