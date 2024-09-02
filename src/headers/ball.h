#pragma once

#include <raylib.h>
class Ball {
public:
  int x{};
  int y{};

  int speed_x{};
  int speed_y{};

  int radius{};

  Color color;

  Ball(int x, int y, int radius, Color color);
  void Draw();

  void Update();
};
