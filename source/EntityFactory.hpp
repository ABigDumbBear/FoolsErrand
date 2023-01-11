#ifndef ENTITYFACTORY_HPP
#define ENTITYFACTORY_HPP

#include <Kuma3D/Scene.hpp>

#include <Kuma3D/Camera.hpp>
#include <Kuma3D/Mesh.hpp>
#include <Kuma3D/Sprite.hpp>
#include <Kuma3D/Transform.hpp>

#include <Kuma3D/TextureLoader.hpp>
#include <Kuma3D/ShaderLoader.hpp>

#include "CameraController.hpp"
#include "CharacterController.hpp"

namespace FoolsErrand {

/******************************************************************************/
inline Kuma3D::Entity CreateCamera(Kuma3D::Scene& aScene)
{
  auto entity = aScene.CreateEntity();

  aScene.AddComponentToEntity<Kuma3D::Camera>(entity);
  aScene.AddComponentToEntity<Kuma3D::Transform>(entity);
  aScene.AddComponentToEntity<CameraController>(entity);

  return entity;
}

/******************************************************************************/
inline Kuma3D::Entity CreateCharacter(Kuma3D::Scene& aScene)
{
  auto entity = aScene.CreateEntity();

  auto shaderID = Kuma3D::ShaderLoader::LoadShaderFromFiles("resources/shaders/BasicShader.vert",
                                                            "resources/shaders/BasicShader.frag");

  Kuma3D::Mesh mesh;
  mesh.mShaders.emplace_back(shaderID);

  Kuma3D::MeshVertex vertex;
  vertex.mPosition = Kuma3D::Vec3(0, 0, 0);
  mesh.mVertices.emplace_back(vertex);
  vertex.mPosition = Kuma3D::Vec3(0.5, 0, 0);
  mesh.mVertices.emplace_back(vertex);
  vertex.mPosition = Kuma3D::Vec3(0.5, 0.5, 0);
  mesh.mVertices.emplace_back(vertex);
  vertex.mPosition = Kuma3D::Vec3(0, 0.5, 0);
  mesh.mVertices.emplace_back(vertex);

  mesh.mIndices.emplace_back(0);
  mesh.mIndices.emplace_back(1);
  mesh.mIndices.emplace_back(3);
  mesh.mIndices.emplace_back(3);
  mesh.mIndices.emplace_back(1);
  mesh.mIndices.emplace_back(2);

  mesh.mDirty = true;

  aScene.AddComponentToEntity<Kuma3D::Mesh>(entity, mesh);
  aScene.AddComponentToEntity<Kuma3D::Transform>(entity);
  aScene.AddComponentToEntity<CharacterController>(entity);

  return entity;
}

/******************************************************************************/
inline Kuma3D::Entity CreateWall(Kuma3D::Scene& aScene)
{
  auto entity = aScene.CreateEntity();

  auto textureID = Kuma3D::TextureLoader::LoadTextureFromFile("resources/tileset.png");
  auto shaderID = Kuma3D::ShaderLoader::LoadShaderFromFiles("resources/shaders/SpriteShader.vert",
                                                            "resources/shaders/SpriteShader.frag");

  aScene.AddComponentToEntity<Kuma3D::Transform>(entity);

  Kuma3D::Mesh mesh;
  mesh.mTextures.emplace_back(textureID);
  mesh.mShaders.emplace_back(shaderID);
  aScene.AddComponentToEntity<Kuma3D::Mesh>(entity, mesh);

  Kuma3D::Sprite sprite;
  sprite.mSpritesheetTextureID = textureID;
  sprite.mWidth = 1;
  sprite.mHeight = 1;
  sprite.mFixedWidth = true;
  sprite.mFixedHeight = true;

  Kuma3D::Animation anim;
  Kuma3D::TextureClip clip;
  clip.mBottom = 48;
  clip.mTop = 56;
  clip.mLeft = 8;
  clip.mRight = 16;
  anim.mFrames.emplace_back(clip);
  sprite.mAnimations.emplace("default", anim);
  sprite.mCurrentAnimation = "default";
  sprite.mDirty = true;
  aScene.AddComponentToEntity<Kuma3D::Sprite>(entity, sprite);

  return entity;
}

} // namespace FoolsErrand

#endif
