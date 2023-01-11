#ifndef CAMERACONTROLLER_HPP
#define CAMERACONTROLLER_HPP

#include <Kuma3D/Entity.hpp>
#include <Kuma3D/Vec3.hpp>

namespace FoolsErrand {

struct CameraController
{
  Kuma3D::Entity mFollowedEntity { 0 };
  Kuma3D::Vec3 mOffset { 0, 3, 3 };
};

} // namespace FoolsErrand

#endif
