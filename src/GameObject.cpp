#include "GameObject.h"
#include <algorithm>
#include <iostream>

using namespace std;

GameObject::GameObject(){
  this->isDead = false;
}

GameObject::~GameObject(){
  this->components.clear();
}

void GameObject::Update(float dt){
  for (int i = 0; i < (int)components.size(); i++)
    this->components[i]->Update(dt);
  
}

void GameObject::Render(){
  for (int i = 0; i < (int)components.size(); i++){
    this->components[i]->Render();
  }
}

bool GameObject::IsDead(){
  return this->isDead;
}

void GameObject::RequestDelete(){
  this->isDead = true;
}

void GameObject::AddComponent(Component* cpt){
  this->components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
  for (int i = 0; i < (int)components.size(); i++){
    if (this->components[i].get() == cpt)
      this->components.erase(this->components.begin() + 1);
  }
}

Component* GameObject::GetComponent(string type){
  for (int i = 0; i < (int)components.size(); i++){
    if (this->components[i]->Is(type))
      return this->components[i].get();
  }
  
  return nullptr;
}
