#include "Game.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

using namespace std;

Game *Game::instance = nullptr;

Game& Game::GetInstance(){
  if(instance != nullptr){
    return *instance;
  }
  new Game("Nataly 190093838", 1024, 600);
  return *instance;
}

Game::Game(string title, int width, int height){
  if(instance != nullptr){
    cout << "Instance isn't nullptr" << endl;
    return;
  }
  instance = this;

  // ** Iniciate SDL **
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
    cout << "Couldn't load SDL" << endl;
    cout << SDL_GetError() << endl;
  }

  // ** Iniciate images **
  int img_flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;

  if (IMG_Init(img_flags) != img_flags){
    cout << "Couldn't load images" << endl;
    cout << SDL_GetError() << endl;
  }

  // ** Iniciate audio **
  int audio_flags = MIX_INIT_MP3 | MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_OGG;

  if (Mix_Init(audio_flags) != audio_flags){
    cout << "Couldn't load mixer" << endl;
    cout << SDL_GetError() << endl;
  }
  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
    cout << "Couldn't load audio" << endl;
    cout << SDL_GetError() << endl;
  }
  if(!(Mix_AllocateChannels(32))){
    cout << "Couldn't alocate audio channels" << endl;
    cout << SDL_GetError() << endl;
  }

  // ** Iniciate window **
  this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  
  if (this->window == nullptr){
    cout << "Couldn't load window" << endl;
    cout << SDL_GetError() << endl;
  }

  // ** Iniciate renderer **
  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

  if (this->renderer == nullptr){
    cout << "Couldn't load renderer" << endl;
    cout << SDL_GetError() << endl;
  }

  this->state = new State();
}

Game::~Game(){
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  IMG_Quit();
  SDL_Quit();
}

State& Game::GetState(){
  return *this->state;
}

SDL_Renderer* Game::GetRenderer(){
  return this->renderer;
}

void Game::Run(){
  while (!this->state->QuitRequested()){
    this->state->Update(2.0);
    this->state->Render();
    
    SDL_RenderPresent(this->renderer);
    SDL_Delay(33);
  }
}
