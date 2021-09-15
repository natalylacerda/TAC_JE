#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

// class GameObject;

#include "Component.h"
#include "Rect.h"
#include <vector>
#include <string>
#include <memory>

class GameObject{
  
private:
  std::vector<std::unique_ptr<Component>> components;
  bool isDead;

public:
  GameObject();
  ~GameObject();
  void Update(float dt);
  void Render();
  bool IsDead();
  void RequestDelete();
  void AddComponent(Component* cpt);
  void RemoveComponent(Component* cpt);
  Component* GetComponent(std::string type);

  Rect box;
};

#endif
