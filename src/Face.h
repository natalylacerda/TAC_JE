#ifndef _FACE_H
#define _FACE_H

#include "GameObject.h"
#include <string>

class Face : public Component{
private:
  int hitpoints;
public:
  Face(GameObject& associated);
  void Damage(int damage);
  void Update(float dt);
  void Render();
  bool Is(std::string type);
};

#endif
