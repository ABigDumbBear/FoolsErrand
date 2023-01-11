#ifndef CHARACTERCONTROLLERSYSTEM_HPP
#define CHARACTERCONTROLLERSYSTEM_HPP

#include <Kuma3D/System.hpp>

#include <Kuma3D/InputSignals.hpp>
#include <Kuma3D/Observer.hpp>

namespace FoolsErrand {

class CharacterControllerSystem : public Kuma3D::System
{
  public:
    void Initialize(Kuma3D::Scene& aScene) override;
    void Operate(Kuma3D::Scene& aScene, double aTime) override;

  private:
    void HandleKeyPressed(Kuma3D::KeyCode aKey, int aMods);
    void HandleKeyReleased(Kuma3D::KeyCode aKey, int aMods);

    std::vector<Kuma3D::KeyCode> mPressedKeys;

    Kuma3D::Observer mObserver;
};

} // namespace FoolsErrand

#endif
