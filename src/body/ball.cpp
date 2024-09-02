#include "../headers/ball.h"
#include <raylib.h>

extern int player_score;
extern int opponent_score;

Ball::Ball(int x, int y, int radius, Color color)
    : x{x}, y{y}, radius{radius}, color{color} {}

void Ball::Draw() { DrawCircle(x, y, radius, color); }

void Ball::Update() {
  this->x += speed_x;
  this->y += speed_y;

  if (x + radius >= GetScreenWidth()) {
    player_score++;
    speed_x *= -1;
  }

  if (x - radius <= 0) {
    opponent_score++;
    speed_x *= -1;
  }

  if (y - radius <= 0 || y + radius >= GetScreenHeight()) {
    speed_y *= -1;
  }
}
