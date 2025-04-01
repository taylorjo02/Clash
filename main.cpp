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
  float gmX{};
  float speed{4.0};

  SetTargetFPS(60);

  while (!WindowShouldClose())
  { 
    const float dT(GetFrameTime());

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

    // draw the map
    DrawTextureEx(gameMap, gmPos, 0.0, 4.0, WHITE);

    EndDrawing();
  }
  UnloadTexture(gameMap);
  CloseWindow();
}