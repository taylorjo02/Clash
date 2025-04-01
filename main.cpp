#include "raylib.h"
#include <raymath.h>

int main()
{
  // window dimensions
  int windowDimensions[2];
  windowDimensions[0] = 384;
  windowDimensions[1] = 384;

  InitWindow(windowDimensions[0], windowDimensions[1], "Clash");

  // load map texture
  Texture2D gameMap = LoadTexture("nature_tileset/OpenWorldMap.png");
  Vector2 gmPos{0.0, 0.0};
  float speed{4.0};

  Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
  Vector2 knightPos{
    (float)windowDimensions[0] / 2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f),
    (float)windowDimensions[1] / 2.0f - 4.0f * (0.5f * (float)knight.height)
  };

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    BeginDrawing();

    ClearBackground(WHITE);
    
    Vector2 direction{};
    if (IsKeyDown(KEY_A)) direction.x -= 1.0;
    if (IsKeyDown(KEY_D)) direction.x += 1.0;
    if (IsKeyDown(KEY_W)) direction.y -= 1.0;
    if (IsKeyDown(KEY_S)) direction.y += 1.0;
    
    
    if (Vector2Length(direction) != 0.0)
    {
      // set map pos = gmPos - direction
      gmPos = Vector2Subtract(gmPos, Vector2Scale(Vector2Normalize(direction), speed));
    }
    
    // draw the knight
    Rectangle source = {
      0.f, 0.f, (float)knight.width / 6.f, (float)knight.height
    };
  
    Rectangle dest = {
      knightPos.x, knightPos.y, 4.f * (float)knight.width/6.f , 4.f * (float)knight.height
    };

    DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);
    // draw the map
    DrawTextureEx(gameMap, gmPos, 0.0, 4.0, WHITE);

    EndDrawing();
  }
  UnloadTexture(gameMap);
  CloseWindow();
}