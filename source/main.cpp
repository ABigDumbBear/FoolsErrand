#include <Kuma3D/Game.hpp>
#include <Kuma3D/Scene.hpp>
#include <Kuma3D/WindowOptions.hpp>

int main()
{
  Kuma3D::WindowOptions options;
  options.mWidth = 1280;
  options.mHeight = 720;
  options.mTitle = "Fool's Errand";

  Kuma3D::Game::Initialize(options);

  Kuma3D::Game::SetScene(std::make_unique<Kuma3D::Scene>());
  Kuma3D::Game::Run();

  Kuma3D::Game::Uninitialize();

  return 0;
}
