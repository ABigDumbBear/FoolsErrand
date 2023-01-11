#include "CharacterControllerSystem.hpp"

#include <Kuma3D/Scene.hpp>

#include <Kuma3D/Transform.hpp>

#include "CharacterController.hpp"

namespace FoolsErrand {

/******************************************************************************/
void CharacterControllerSystem::Initialize(Kuma3D::Scene& aScene)
{
  auto signature = aScene.CreateSignature();
  signature[aScene.GetComponentIndex<Kuma3D::Transform>()] = true;
  signature[aScene.GetComponentIndex<CharacterController>()] = true;
  SetSignature(signature);

  Kuma3D::KeyPressed.Connect(mObserver, [this](Kuma3D::KeyCode aKey, int aMods)
  {
    this->HandleKeyPressed(aKey, aMods);
  });

  Kuma3D::KeyReleased.Connect(mObserver, [this](Kuma3D::KeyCode aKey, int aMods)
  {
    this->HandleKeyReleased(aKey, aMods);
  });
}

/******************************************************************************/
void CharacterControllerSystem::Operate(Kuma3D::Scene& aScene, double aTime)
{
  for(const auto& entity : GetEntities())
  {
    auto& transform = aScene.GetComponentForEntity<Kuma3D::Transform>(entity);

    for(const auto& key : mPressedKeys)
    {
      switch(key)
      {
        case Kuma3D::KeyCode::eKEY_LEFT:
        {
          transform.mPosition.x -= 0.1;
          break;
        }
        case Kuma3D::KeyCode::eKEY_RIGHT:
        {
          transform.mPosition.x += 0.1;
          break;
        }
        case Kuma3D::KeyCode::eKEY_UP:
        {
          transform.mPosition.z -= 0.1;
          break;
        }
        case Kuma3D::KeyCode::eKEY_DOWN:
        {
          transform.mPosition.z += 0.1;
          break;
        }
        default: { break; }
      }
    }
  }
}

/******************************************************************************/
void CharacterControllerSystem::HandleKeyPressed(Kuma3D::KeyCode aKey, int aMods)
{
  mPressedKeys.emplace_back(aKey);
}

/******************************************************************************/
void CharacterControllerSystem::HandleKeyReleased(Kuma3D::KeyCode aKey, int aMods)
{
  auto foundKey = std::find(mPressedKeys.begin(), mPressedKeys.end(), aKey);
  if(foundKey != mPressedKeys.end())
  {
    mPressedKeys.erase(foundKey);
  }
}

} // namespace FoolsErrand
