#ifndef _COMPONENT_H
#define _COMPONENT_H

class GameObject;

#include <string>

class Component{

protected:
  GameObject& associated;

public:
  Component(GameObject& associated);
  virtual ~Component();
  virtual void Update(float dt) = 0;
  virtual void Render() = 0;
  virtual bool Is(std::string type) = 0;
};

#endif
