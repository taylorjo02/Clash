#include "character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) :
  windowWidth(winWidth),
  windowHeight(winHeight)
{
  width = texture.width / maxFrames;
  height = texture.height;
}

Vector2 Character::getScreenPos()
{
  return Vector2 {
      static_cast<float>(windowWidth) / 2.0f - characterScale * (0.5f * width),
      static_cast<float>(windowHeight) / 2.0f - characterScale * (0.5f * height)
  };
}

void Character::tick(float deltaTime)
{
  if (!getAlive()) return;

  if (IsKeyDown(KEY_A))
    velocity.x -= 1.0;
  if (IsKeyDown(KEY_D))
    velocity.x += 1.0;
  if (IsKeyDown(KEY_W))
    velocity.y -= 1.0;
  if (IsKeyDown(KEY_S))
    velocity.y += 1.0;

  BaseCharacter::tick(deltaTime);

  Vector2 origin{};
  Vector2 offset{};
  float rotation{};
  if (rightLeft > 0.f)
  {
    origin = {0.f, weapon.height * characterScale};
    offset = {35.f, 55.f};
    weaponCollisionRec = {
      getScreenPos().x + offset.x,
      getScreenPos().y + offset.y - weapon.height * characterScale,
      weapon.width * characterScale,
      weapon.height * characterScale
    };
    rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.f : 0.f;
  }
  else
  {
    rotation = -35.f;
    origin = {weapon.width * characterScale, weapon.height * characterScale};
    offset = {25.f, 55.f};
    weaponCollisionRec = {
      getScreenPos().x + offset.x - weapon.width * characterScale,
      getScreenPos().y + offset.y - weapon.height * characterScale,
      weapon.width * characterScale,
      weapon.height * characterScale
    };
    rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.f : 0.f;
  }

  //draw the sword
  Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
  Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * characterScale, weapon.height * characterScale};

  DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);
}