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