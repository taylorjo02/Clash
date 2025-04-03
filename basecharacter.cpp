#include "basecharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
  width = texture.width / maxFrames;
  height = texture.height;
}

void BaseCharacter::undoMovement()
{
  worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
  return Rectangle{
    getScreenPos().x,
    getScreenPos().y,
    width * characterScale,
    height * characterScale
  };
}

void BaseCharacter::tick(float deltaTime)
{
  worldPosLastFrame = worldPos;
  // update animation frame
  runningTime += deltaTime;
  if (runningTime >= updateTime)
  {
    frame++;
    runningTime = 0.f;
    if (frame > maxFrames)
      frame = 0;
  }

  if (Vector2Length(velocity) != 0.0)
  {
    // set worldPos = worldPos + velocity

    worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
    velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
    texture = run;
  }
  else
  {
    texture = idle;
  }

  velocity = {};

  // draw the character
  Rectangle source{frame * width, 0.f, rightLeft * width, height};
  Rectangle dest{getScreenPos().x, getScreenPos().y, characterScale * width, characterScale * height};
  DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}