#include "enemy.h"
#include "character.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
  worldPos = pos;
  texture = idle_texture;
  idle = idle_texture;
  run = run_texture;
  width = texture.width / maxFrames;
  height = texture.height;
  speed = 3.5f;
}

void Enemy::tick(float deltaTime)
{
  // get toTarget vector
  Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos);
  // normalize vector so it has a length of 1
  toTarget = Vector2Normalize(toTarget);
  // multiply toTarget by enemy speed
  toTarget = Vector2Scale(toTarget, speed);
  // move enemy toward character by set world pos
  worldPos = Vector2Add(worldPos, toTarget);
  screenPos = Vector2Subtract(worldPos, target->getWorldPos());
  BaseCharacter::tick(deltaTime);

}