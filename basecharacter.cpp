#include "basecharacter.h"

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
    screenPos.x,
    screenPos.y,
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

  // draw the character
  Rectangle source{frame * width, 0.f, rightLeft * width, height};
  Rectangle dest{screenPos.x, screenPos.y, characterScale * width, characterScale * height};
  DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}