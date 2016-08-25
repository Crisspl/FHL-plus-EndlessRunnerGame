#include "Sphere.h"

#define REGISTER_SPHERE_STATES(stateName) \
   m_onEnter[State_##stateName] \
     = &Sphere::stateName##_onEnter; \
   m_onExit[State_##stateName] \
     = &Sphere::stateName##_onExit; \
   m_update[State_##stateName] \
     = &Sphere::stateName##_update;

Sphere::Sphere(Hero* _owner)
         : m_sprite(fhl::ResMgr::loadTexture("Resources/Tex/ball2.png", "sphereTex")),
           m_startVelociy(30.f),
           m_velocity(m_startVelociy),
           m_owner(_owner),
           m_currentState(StateCount)
{
   REGISTER_SPHERE_STATES(Idle)
   REGISTER_SPHERE_STATES(Thrown)
   REGISTER_SPHERE_STATES(Return)

   m_sprite.setOrigin({32.f, 32.f});
   changeState(State_Idle);
}

std::shared_ptr<Collider> Sphere::getCollider(CollideableObjType _objType)
{
   glm::vec2 center = m_sprite.getPosition();

   return std::shared_ptr<Collider>(new CircleCollider(center, 32.f));
}

void Sphere::draw(const fhl::DrawConf &) const
{
	fhl::draw(m_sprite);
}

void Sphere::update(float dt)
{
   (this->*m_update[m_currentState])(dt);
}

void Sphere::changeState(const State _newState)
{
   if(m_currentState < StateCount &&
      m_currentState != _newState)
   {
         (this->*m_onExit[m_currentState])(_newState);
   }

   const State prevState(m_currentState);

   m_currentState = _newState;

   (this->*m_onEnter[m_currentState])(prevState);
}

/* State Idle Methods */

void Sphere::Idle_onEnter(const Sphere::State _prevState)
{
   m_sprite.setPosition(m_owner->getPosition());
   m_velocity = 0;
}

void Sphere::Idle_onExit(const Sphere::State _newState)
{

}

void Sphere::Idle_update(float dt)
{
   m_sprite.setPosition(m_owner->getPosition());
}

/* State Thrown Methods */

void Sphere::Thrown_onEnter(const Sphere::State _prevState)
{
   m_velocity = m_startVelociy;
}

void Sphere::Thrown_onExit(const Sphere::State _newState)
{
   m_direction = glm::vec2();
}

void Sphere::Thrown_update(float dt)
{
   m_velocity -= m_startVelociy * dt;
   if(m_velocity < 0)
   {
      changeState(State_Return);
      return;
   }
   glm::vec2 moveOffset = m_direction * m_velocity;
   m_sprite.move(moveOffset);
}

/* State Return Methods */

void Sphere::Return_onEnter(const Sphere::State _prevState)
{

}

void Sphere::Return_onExit(const Sphere::State _newState)
{

}

void Sphere::Return_update(float dt)
{
   m_velocity -= m_startVelociy * dt;

   glm::vec2 myPos = m_sprite.getPosition();
   glm::vec2 ownerPos = m_owner->getPosition();

   glm::vec2 dir(myPos.x - ownerPos.x, myPos.y - ownerPos.y);
   dir = glm::normalize(dir);

   glm::vec2 moveOffset = dir * m_velocity;
   m_sprite.move(moveOffset);
}
