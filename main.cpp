#include "./src/headers/ai_paddle.h"
#include "./src/headers/ball.h"
#include "./src/headers/paddle.h"
#include <iostream>
#include <raylib.h>

int player_score = 0;
int opponent_score = 0;

Color green {38,185,154,255};
Color dark_green {20,160,133,255};
Color light_green {129,204,184,255};
Color yellow {243,213,91,255};

int main(int argc, char *argv[]) {

  const int screen_height = 800;
  const int screen_width = 1280;

  Ball ball(screen_width / 2, screen_height / 2, 20, yellow);
  ball.speed_x = 7;
  ball.speed_y = 7;

  Paddle player(10, screen_height / 2 - 60);

  AiPaddle opponent(screen_width - 35, screen_height / 2 - 60);

  InitWindow(screen_width, screen_height, "Ping Pong");

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(dark_green);
    DrawRectangle(0, 0, screen_width/2, screen_height, green);
    DrawCircle(screen_width/2, screen_height/2, 150, light_green);
    ball.Draw();
    ball.Update();
    player.Draw();
    player.KeyInput();
    player.CheckCollision(&ball);
    opponent.Draw();
    opponent.AiMovement(ball.y);
    opponent.CheckCollision(&ball);
    DrawText(TextFormat("Player: %i", player_score), screen_width / 4.5, 20, 55,
             WHITE);
    DrawText(TextFormat("Computer: %i", opponent_score), screen_width / 1.75,
             20, 55, WHITE);
    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
