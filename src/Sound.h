#ifndef _SOUND_H
#define _SOUND_H

#include <string>
#include <SDL2/SDL.h>
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.h"

class Sound : public Component{
private:
  Mix_Chunk* chunk;
  int channel;
public:
  Sound(GameObject& associated);
  Sound(GameObject& associated, std::string file);
  ~Sound();
  void Play(int times = 1);
  void Stop();
  void Open(std::string file);
  bool IsOpen();
  void Update(float dt);
  void Render();
  bool Is(std::string type);
};

#endif
