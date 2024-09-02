#pragma once
#include <raylib.h>

class Paddle {
public:
  int x{};
  int y{};
  int width{};
  int height{};
  int speed{};
  Color color;
  Paddle(int x = 400, int y = 625, int width = 25, int height = 120,
         int speed = 6, Color color = WHITE);
  void Draw();

  void KeyInput();
  void CheckCollision(class Ball *ball);

protected:
  void MovementLimit();
};
