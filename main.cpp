#include "raylib.h"

int main()
{
  // window dimensions
  int windowDimensions[2];
  windowDimensions[0] = 384;
  windowDimensions[1] = 384;

  InitWindow(windowDimensions[0], windowDimensions[1], "Clash");

  // load map texture
  Texture2D gameMap = LoadTexture("nature_tileset/OpenWorldMap.png");
  float gmX{};

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    const float dT(GetFrameTime());

    BeginDrawing();

    ClearBackground(WHITE);

    // draw the map
    Vector2 gmPos{0.0, 0.0};
    DrawTextureEx(gameMap, gmPos, 0.0, 4.0, WHITE);

    EndDrawing();
  }
  UnloadTexture(gameMap);
  CloseWindow();
}