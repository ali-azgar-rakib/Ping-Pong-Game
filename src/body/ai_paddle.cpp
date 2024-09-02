#include "../headers/ai_paddle.h"

void AiPaddle::AiMovement(int ball_y) {
  if (y + height / 2 > ball_y) {
    y -= speed;
  }
  if (y + height / 2 <= ball_y) {
    y += speed;
  }
}
