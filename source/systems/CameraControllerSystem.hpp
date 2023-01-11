#ifndef CAMERACONTROLLERSYSTEM_HPP
#define CAMERACONTROLLERSYSTEM_HPP

#include <Kuma3D/System.hpp>

namespace FoolsErrand {

class CameraControllerSystem : public Kuma3D::System
{
  public:
    void Initialize(Kuma3D::Scene& aScene) override;
    void Operate(Kuma3D::Scene& aScene, double aTime) override;
};

} // namespace FoolsErrand

#endif
