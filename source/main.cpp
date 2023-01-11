#include <Kuma3D/Game.hpp>
#include <Kuma3D/Scene.hpp>
#include <Kuma3D/WindowOptions.hpp>

#include <Kuma3D/SpriteSystem.hpp>
#include <Kuma3D/RenderSystem.hpp>

#include <Kuma3D/Camera.hpp>
#include <Kuma3D/Mesh.hpp>
#include <Kuma3D/Sprite.hpp>
#include <Kuma3D/Transform.hpp>

#include <Kuma3D/TextureLoader.hpp>
#include <Kuma3D/ShaderLoader.hpp>

#include "CameraController.hpp"
#include "CharacterController.hpp"

#include "CameraControllerSystem.hpp"
#include "CharacterControllerSystem.hpp"

#include "EntityFactory.hpp"

/******************************************************************************/
std::unique_ptr<Kuma3D::Scene> CreateScene()
{
  auto scene = std::make_unique<Kuma3D::Scene>();

  scene->RegisterComponentType<Kuma3D::Camera>(1);
  scene->RegisterComponentType<Kuma3D::Mesh>();
  scene->RegisterComponentType<Kuma3D::Sprite>();
  scene->RegisterComponentType<Kuma3D::Transform>();
  scene->RegisterComponentType<FoolsErrand::CameraController>(1);
  scene->RegisterComponentType<FoolsErrand::CharacterController>(1);

  auto character = FoolsErrand::CreateCharacter(*scene);

  auto camera = FoolsErrand::CreateCamera(*scene);
  auto& transform = scene->GetComponentForEntity<Kuma3D::Transform>(camera);
  transform.mRotation.x = -25;
  auto& cameraController = scene->GetComponentForEntity<FoolsErrand::CameraController>(camera);
  cameraController.mFollowedEntity = character;

  for(int i = 0; i < 5; ++i)
  {
    auto wall = FoolsErrand::CreateWall(*scene);
    auto& wallTransform = scene->GetComponentForEntity<Kuma3D::Transform>(wall);
    wallTransform.mPosition.x = i;
    wallTransform.mPosition.z = -10;
  }

  scene->AddSystem(std::make_unique<FoolsErrand::CameraControllerSystem>());
  scene->AddSystem(std::make_unique<FoolsErrand::CharacterControllerSystem>());
  scene->AddSystem(std::make_unique<Kuma3D::SpriteSystem>());
  scene->AddSystem(std::make_unique<Kuma3D::RenderSystem>());

  return std::move(scene);
}

/******************************************************************************/
int main()
{
  Kuma3D::WindowOptions options;
  options.mWidth = 1280;
  options.mHeight = 720;
  options.mTitle = "Fool's Errand";

  Kuma3D::Game::Initialize(options);

  Kuma3D::TextureLoader::LoadTextureFromFile("resources/tileset.png");
  Kuma3D::ShaderLoader::LoadShaderFromFiles("resources/shaders/BasicShader.vert",
                                            "resources/shaders/BasicShader.frag");
  Kuma3D::ShaderLoader::LoadShaderFromFiles("resources/shaders/SpriteShader.vert",
                                            "resources/shaders/SpriteShader.frag");

  Kuma3D::Game::SetScene(CreateScene());
  Kuma3D::Game::Run();

  Kuma3D::ShaderLoader::UnloadShaders();
  Kuma3D::TextureLoader::UnloadTextures();
  Kuma3D::Game::Uninitialize();

  return 0;
}
