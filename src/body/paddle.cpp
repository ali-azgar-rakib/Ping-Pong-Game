#include "../headers/paddle.h"
#include "../headers/ball.h"
#include <iostream>
#include <raylib.h>

Paddle::Paddle(int x, int y, int width, int height, int speed, Color color)
    : x{x}, y{y}, width{width}, height{height}, speed{speed}, color{color} {}

void Paddle::Draw() { DrawRectangleRounded(Rectangle{x, y, width, height},0.8,0,WHITE); }

void Paddle::KeyInput() {

  if (IsKeyDown(KEY_UP)) {
    y -= speed;
  }
  if (IsKeyDown(KEY_DOWN)) {
    y += speed;
  }
  MovementLimit();
}

void Paddle::MovementLimit() {

  if (y <= 0) {
    y = 0;
  }

  if (y + height >= GetScreenHeight()) {
    y = GetScreenHeight() - height;
  }
}

void Paddle::CheckCollision(Ball *ball) {
  if (CheckCollisionCircleRec(
          Vector2{static_cast<float>(ball->x), static_cast<float>(ball->y)}, ball->radius,
          Rectangle{static_cast<float>(x), static_cast<float>(y),
                    static_cast<float>(width), static_cast<float>(height)})) {
    ball->speed_x *= -1;
  }
}
