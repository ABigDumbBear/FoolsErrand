#include "CameraControllerSystem.hpp"

#include <Kuma3D/Scene.hpp>

#include <Kuma3D/Transform.hpp>

#include "CameraController.hpp"

namespace FoolsErrand {

/******************************************************************************/
void CameraControllerSystem::Initialize(Kuma3D::Scene& aScene)
{
  auto signature = aScene.CreateSignature();
  signature[aScene.GetComponentIndex<Kuma3D::Transform>()] = true;
  signature[aScene.GetComponentIndex<CameraController>()] = true;
  SetSignature(signature);
}

/******************************************************************************/
void CameraControllerSystem::Operate(Kuma3D::Scene& aScene, double aTime)
{
  for(const auto& entity : GetEntities())
  {
    auto& cameraTransform = aScene.GetComponentForEntity<Kuma3D::Transform>(entity);
    auto& controller = aScene.GetComponentForEntity<CameraController>(entity);

    auto& targetTransform = aScene.GetComponentForEntity<Kuma3D::Transform>(controller.mFollowedEntity);
    cameraTransform.mPosition = targetTransform.mPosition + controller.mOffset;
  }
}

} // namespace FoolsErrand
