#include "Sprite.h"
#include "Game.h"
#include "GameObject.h"

using namespace std;

Sprite::Sprite(GameObject& associated) : Component(associated){
  this->texture = nullptr;
}

Sprite::Sprite(GameObject& associated, string file) : Component(associated){
  this->texture = nullptr;
  this->Open(file);
}

Sprite::~Sprite(){
  if (this->texture != nullptr)
    SDL_DestroyTexture(this->texture);
}

void Sprite::Open(string file){
  if (this->texture != nullptr)
    SDL_DestroyTexture(this->texture);

  this->texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
  if (this->texture == nullptr){
    cout << "Couldn't load texture" << endl;
    cout << SDL_GetError() << endl;
  }

  if (SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height) != 0){
    cout << "Couldn't load query texture" << endl;
    cout << SDL_GetError() << endl;
  }
  this->SetClip(0, 0, this->width, this->height);
}

void Sprite::SetClip(int x, int y, int w, int h){
  this->clipRect.x = x;
  this->clipRect.y = y;
  this->clipRect.w = w;
  this->clipRect.h = h;
}

void Sprite::Render(){
  SDL_Rect dstrect;

  dstrect.x = this->associated.box.x;
  dstrect.y = this->associated.box.y;
  dstrect.w = this->clipRect.w;
  dstrect.h = this->clipRect.h;
  if (SDL_RenderCopy(Game::GetInstance().GetRenderer(), this->texture, &this->clipRect, &dstrect) != 0){
    cout << "Couldn't render img" << endl;
    cout << SDL_GetError() << endl;
  }
}

int Sprite::GetWidth(){
  return this->width;
}

int Sprite::GetHeight(){
  return this->height;
}

bool Sprite::IsOpen(){
  if (this->texture != nullptr)
    return true;
  
  return false;
}

void Sprite::Update(float dt){}

bool Sprite::Is(string type){
  if(type == "Sprite"){
    return true;
  }
  return false;
}
