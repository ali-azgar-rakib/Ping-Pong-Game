
#pragma once
#include "./paddle.h"
class AiPaddle : public Paddle {

public:
  using Paddle::Paddle;
  void AiMovement(int ball_y);
};
