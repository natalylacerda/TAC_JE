#include "Music.h"

Music::Music(){
  this->music = nullptr;
}

Music::Music(string file){
  Music::Open(file);
}

Music::~Music(){
  this->Stop();
  Mix_FreeMusic(this->music);
}

void Music::Play(int times){
  if (this->music != nullptr){
    Mix_PlayMusic(this->music, times);
  }
}

void Music::Stop(int msToStop){
  Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
  this->music = Mix_LoadMUS(file.c_str());
  if (this->music == nullptr){
    cout << "Couldn't load music" << endl;
    cout << SDL_GetError() << endl;
  }
}

bool Music::IsOpen(){
  if (this->music == nullptr){
    return true;
  }
  return false;
}
