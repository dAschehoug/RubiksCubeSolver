#ifndef Rotation.h
#define Rotation_h
#include "Arduino.h"

int up[9]  = {2, 6, 5, 3, 2, 6, 4, 1, 6}; //BLUE = 2
int front[9] = {3, 4, 5, 5, 1, 5, 6, 4, 2}; //WHITE = 1
int down[9] = {5, 2, 6, 4, 3, 5, 1, 5, 4}; //GREEN = 3
int left[9] = {5, 1, 6, 1, 4, 1, 2, 6, 2}; //ORANGE = 4
int right[9] = {3, 3, 1, 3, 5, 3, 4, 6, 1}; //RED = 5
int back[9] = {3, 2, 1, 4, 6, 2, 3, 2, 4}; //YELLOW = 6
/*int up[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
int front[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
int down[9] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
int left[9] = {4, 4, 4, 4, 4, 4, 4, 4, 4};
int right[9] = {5, 5, 5, 5, 5, 5, 5, 5, 5};
int back[9] = {6, 6, 6, 6, 6, 6, 6, 6, 6};*/
int upBUF[9] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
int frontBUF[9] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
int downBUF[9] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
int leftBUF[9] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
int rightBUF[9] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
int backBUF[9] = {7, 7, 7, 7, 7, 7, 7, 7, 7};

class Position {
  public:
  void FCW() //Front rotation clockwise
  {
    frontBUF[0] = front[6];
    frontBUF[1] = front[3];
    frontBUF[2] = front[0];
    frontBUF[3] = front[7];
    frontBUF[4] = front[4];
    frontBUF[5] = front[1];
    frontBUF[6] = front[8];
    frontBUF[7] = front[5];
    frontBUF[8] = front[2];
    upBUF[6] = left[8];
    upBUF[7] = left[5];
    upBUF[8] = left[2];
    leftBUF[2] = down[0];
    leftBUF[5] = down[1];
    leftBUF[8] = down[2];
    rightBUF[0] = up[6];
    rightBUF[3] = up[7];
    rightBUF[6] = up[8];
    downBUF[0] = right[6];
    downBUF[1] = right[3];
    downBUF[2] = right[0];
    for(int i = 0; i < 9; i++)
    {
      front[i] = frontBUF[i];
    }
    up[6] = upBUF[6];
    up[7] = upBUF[7];
    up[8] = upBUF[8];
    left[2] = leftBUF[2];
    left[5] = leftBUF[5];
    left[8] = leftBUF[8];
    right[0] = rightBUF[0];
    right[3] = rightBUF[3];
    right[6] = rightBUF[6];
    down[0] = downBUF[0];
    down[1] = downBUF[1];
    down[2] = downBUF[2];

    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;

    Serial.println("F");
  }
  void FCCW() //Front rotation counter-clockwise
  {
    frontBUF[0] = front[2];
    frontBUF[1] = front[5];
    frontBUF[2] = front[8];
    frontBUF[3] = front[1];
    frontBUF[4] = front[4];
    frontBUF[5] = front[7];
    frontBUF[6] = front[0];
    frontBUF[7] = front[3];
    frontBUF[8] = front[6];
    upBUF[6] = right[0];
    upBUF[7] = right[3];
    upBUF[8] = right[6];
    rightBUF[0] = down[2];
    rightBUF[3] = down[1];
    rightBUF[6] = down[0];
    downBUF[0] = left[2];
    downBUF[1] = left[5];
    downBUF[2] = left[8];
    leftBUF[2] = up[8];
    leftBUF[5] = up[7];
    leftBUF[8] = up[6];
    for(int i = 0; i < 9; i++) {
      front[i] = frontBUF[i];
    }
    up[6] = upBUF[6];
    up[7] = upBUF[7];
    up[8] = upBUF[8];
    right[0] = rightBUF[0];
    right[3] = rightBUF[3];
    right[6] = rightBUF[6];
    down[0] = downBUF[0];
    down[1] = downBUF[1];
    down[2] = downBUF[2];
    left[2] = leftBUF[2];
    left[5] = leftBUF[5];
    left[8] = leftBUF[8];

    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;

    Serial.println("F'");
  }
  void BCW() //Back rotation clockwise
  {
    backBUF[0] = back[6];
    backBUF[1] = back[3];
    backBUF[2] = back[0];
    backBUF[3] = back[7];
    backBUF[4] = back[4];
    backBUF[5] = back[1];
    backBUF[6] = back[8];
    backBUF[7] = back[5];
    backBUF[8] = back[2];
    upBUF[0] = right[2];
    upBUF[1] = right[5];
    upBUF[2] = right[8];
    leftBUF[0] = up[2];
    leftBUF[3] = up[1];
    leftBUF[6] = up[0];
    downBUF[6] = left[0];
    downBUF[7] = left[3];
    downBUF[8] = left[6];
    rightBUF[2] = down[8];
    rightBUF[5] = down[7];
    rightBUF[8] = down[6];
    for(int i = 0; i < 9; i++)
    {
      back[i] = backBUF[i];
    }
    up[0] = upBUF[0];
    up[1] = upBUF[1];
    up[2] = upBUF[2];
    left[0] = leftBUF[0];
    left[3] = leftBUF[3];
    left[6] = leftBUF[6];
    down[6] = downBUF[6];
    down[7] = downBUF[7];
    down[8] = downBUF[8];
    right[2] = rightBUF[2];
    right[5] = rightBUF[5];
    right[8] = rightBUF[8];


    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("B");
  }
  void BCCW() //Back rotation counter-clockwise
  {
    backBUF[0] = back[2];
    backBUF[1] = back[5];
    backBUF[2] = back[8];
    backBUF[3] = back[1];
    backBUF[4] = back[4];
    backBUF[5] = back[7];
    backBUF[6] = back[0];
    backBUF[7] = back[3];
    backBUF[8] = back[6];
    upBUF[0] = left[6];
    upBUF[1] = left[3];
    upBUF[2] = left[0];
    leftBUF[0] = down[6];
    leftBUF[3] = down[7];
    leftBUF[6] = down[8];
    downBUF[6] = right[8];
    downBUF[7] = right[5];
    downBUF[8] = right[2];
    rightBUF[2] = up[0];
    rightBUF[5] = up[1];
    rightBUF[8] = up[2];
    for(int i = 0; i < 9; i++)
    {
      back[i] = backBUF[i];
    }
    up[0] = upBUF[0];
    up[1] = upBUF[1];
    up[2] = upBUF[2];
    left[0] = leftBUF[0];
    left[3] = leftBUF[3];
    left[6] = leftBUF[6];
    down[6] = downBUF[6];
    down[7] = downBUF[7];
    down[8] = downBUF[8];
    right[2] = rightBUF[2];
    right[5] = rightBUF[5];
    right[8] = rightBUF[8];

    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("B'");
  }
  void UCW() //Top rotation clockwise
  {
    upBUF[0] = up[6];
    upBUF[1] = up[3];
    upBUF[2] = up[0];
    upBUF[3] = up[7];
    upBUF[4] = up[4];
    upBUF[5] = up[1];
    upBUF[6] = up[8];
    upBUF[7] = up[5];
    upBUF[8] = up[2];
    frontBUF[0] = right[0];
    frontBUF[1] = right[1];
    frontBUF[2] = right[2];
    leftBUF[0] = front[0];
    leftBUF[1] = front[1];
    leftBUF[2] = front[2];
    backBUF[0] = left[0];
    backBUF[1] = left[1];
    backBUF[2] = left[2];
    rightBUF[0] = back[0];
    rightBUF[1] = back[1];
    rightBUF[2] = back[2];
    for(int i = 0; i < 9; i++)
    {
      up[i] = upBUF[i];
      if(i < 3)
      {
        front[i] = frontBUF[i];
        left[i] = leftBUF[i];
        back[i] = backBUF[i];
        right[i] = rightBUF[i];
      }
    }

    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("U");
  }
  void UCCW() //Top rotation counter-clockwise
  {
    frontBUF[0] = left[0];
    frontBUF[1] = left[1];
    frontBUF[2] = left[2];
    frontBUF[3] = front[3];
    frontBUF[4] = front[4];
    frontBUF[5] = front[5];
    frontBUF[6] = front[6];
    frontBUF[7] = front[7];
    frontBUF[8] = front[8];
    upBUF[0] = up[2];
    upBUF[1] = up[5];
    upBUF[2] = up[8];
    upBUF[3] = up[1];
    upBUF[4] = up[4];
    upBUF[5] = up[7];
    upBUF[6] = up[0];
    upBUF[7] = up[3];
    upBUF[8] = up[6];
    downBUF[0] = down[0];
    downBUF[1] = down[1];
    downBUF[2] = down[2];
    downBUF[3] = down[3];
    downBUF[4] = down[4];
    downBUF[5] = down[5];
    downBUF[6] = down[6];
    downBUF[7] = down[7];
    downBUF[8] = down[8];
    leftBUF[0] = back[0];
    leftBUF[1] = back[1];
    leftBUF[2] = back[2];
    leftBUF[3] = left[3];
    leftBUF[4] = left[4];
    leftBUF[5] = left[5];
    leftBUF[6] = left[6];
    leftBUF[7] = left[7];
    leftBUF[8] = left[8];
    rightBUF[0] = front[0];
    rightBUF[1] = front[1];
    rightBUF[2] = front[2];
    rightBUF[3] = right[3];
    rightBUF[4] = right[4];
    rightBUF[5] = right[5];
    rightBUF[6] = right[6];
    rightBUF[7] = right[7];
    rightBUF[8] = right[8];
    rightBUF[9] = right[9];
    backBUF[0] = right[0];
    backBUF[1] = right[1];
    backBUF[2] = right[2];
    backBUF[3] = back[3];
    backBUF[4] = back[4];
    backBUF[5] = back[5];
    backBUF[6] = back[6];
    backBUF[7] = back[7];
    backBUF[8] = back[8];
    for(int i= 0; i < 9; i++)
    {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      left[i] = leftBUF[i];
      right[i] = rightBUF[i];
      back[i] = backBUF[i];
    }

    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("U'");
  }
  void DCW() //Down rotation clockwise
  {
    downBUF[0] = down[6];
    downBUF[1] = down[3];
    downBUF[2] = down[0];
    downBUF[3] = down[7];
    downBUF[4] = down[4];
    downBUF[5] = down[1];
    downBUF[6] = down[8];
    downBUF[7] = down[5];
    downBUF[8] = down[2];
    frontBUF[6] = left[6];
    frontBUF[7] = left[7];
    frontBUF[8] = left[8];
    rightBUF[6] = front[6];
    rightBUF[7] = front[7];
    rightBUF[8] = front[8];
    leftBUF[6] = back[6];
    leftBUF[7] = back[7];
    leftBUF[8] = back[8];
    backBUF[6] = right[6];
    backBUF[7] = right[7];
    backBUF[8] = right[8];
    for(int i = 0; i < 9; i++)
    {
      down[i] = downBUF[i];
      if(i > 5)
      {
        front[i] = frontBUF[i];
        right[i] = rightBUF[i];
        left[i] = leftBUF[i];
        back[i] = backBUF[i];
      }
    }

    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("D");
  }
  void DCCW() //Down rotation counter-clockwise
  {
    downBUF[0] = down[2];
    downBUF[1] = down[5];
    downBUF[2] = down[8];
    downBUF[3] = down[1];
    downBUF[4] = down[4];
    downBUF[5] = down[7];
    downBUF[6] = down[0];
    downBUF[7] = down[3];
    downBUF[8] = down[6];
    frontBUF[6] = right[6];
    frontBUF[7] = right[7];
    frontBUF[8] = right[8];
    rightBUF[6] = back[6];
    rightBUF[7] = back[7];
    rightBUF[8] = back[8];
    leftBUF[6] = front[6];
    leftBUF[7] = front[7];
    leftBUF[8] = front[8];
    backBUF[6] = left[6];
    backBUF[7] = left[7];
    backBUF[8] = left[8];
    for(int i = 0; i < 9; i++)
    {
      down[i] = downBUF[i];
      if(i > 5)
      {
        front[i] = frontBUF[i];
        right[i] = rightBUF[i];
        left[i] = leftBUF[i];
        back[i] = backBUF[i];
      }
    }
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("D'");
  }
  void RCW() //Right rotation clockwise
  {
    rightBUF[0] = right[6];
    rightBUF[1] = right[3];
    rightBUF[2] = right[0];
    rightBUF[3] = right[7];
    rightBUF[4] = right[4];
    rightBUF[5] = right[1];
    rightBUF[6] = right[8];
    rightBUF[7] = right[5];
    rightBUF[8] = right[2];
    frontBUF[2] = down[2];
    frontBUF[5] = down[5];
    frontBUF[8] = down[8];
    upBUF[2] = front[2];
    upBUF[5] = front[5];
    upBUF[8] = front[8];
    backBUF[0] = up[8];
    backBUF[3] = up[5];
    backBUF[6] = up[2];
    downBUF[2] = back[6];
    downBUF[5] = back[3];
    downBUF[8] = back[0];
    for(int i = 0; i < 9; i++)
    {
      right[i] = rightBUF[i];
      if(i == 2 || i == 5 || i == 8)
      {
        front[i] = frontBUF[i];
        up[i] = upBUF[i];
        down[i] = downBUF[i];
      }      
    }
    back[0] = backBUF[0];
    back[3] = backBUF[3];
    back[6] = backBUF[6];

    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("R");
  }
  void RCCW() //Right rotation counter-clockwise
  {
    rightBUF[0] = right[2];
    rightBUF[1] = right[5];
    rightBUF[2] = right[8];
    rightBUF[3] = right[1];
    rightBUF[4] = right[4];
    rightBUF[5] = right[7];
    rightBUF[6] = right[0];
    rightBUF[7] = right[3];
    rightBUF[8] = right[6];
    frontBUF[2] = up[2];
    frontBUF[5] = up[5];
    frontBUF[8] = up[8];
    upBUF[2] = back[6];
    upBUF[5] = back[3];
    upBUF[8] = back[0];
    backBUF[0] = down[8];
    backBUF[3] = down[5];
    backBUF[6] = down[2];
    downBUF[2] = front[2];
    downBUF[5] = front[5];
    downBUF[8] = front[8];
    for(int i = 0; i < 9; i++)
    {
      right[i] = rightBUF[i];
      if(i == 2 || i == 5 || i == 8)
      {
        front[i] = frontBUF[i];
        up[i] = upBUF[i];
        down[i] = downBUF[i];
      }
    }
    back[0] = backBUF[0];
    back[3] = backBUF[3];
    back[6] = backBUF[6];
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("R'");
  }
  void LCW() //Left rotation clockwise
  {
    leftBUF[0] = left[6];
    leftBUF[1] = left[3];
    leftBUF[2] = left[0];
    leftBUF[3] = left[7];
    leftBUF[4] = left[4];
    leftBUF[5] = left[1];
    leftBUF[6] = left[8];
    leftBUF[7] = left[5];
    leftBUF[8] = left[2];
    frontBUF[0] = up[0];
    frontBUF[3] = up[3];
    frontBUF[6] = up[6];
    upBUF[0] = back[8];
    upBUF[3] = back[5];
    upBUF[6] = back[2];
    backBUF[2] = down[6];
    backBUF[5] = down[3];
    backBUF[8] = down[0];
    downBUF[0] = front[0];
    downBUF[3] = front[3];
    downBUF[6] = front[6];
    for(int i = 0; i < 9; i++)
    {
      left[i] = leftBUF[i];
      if(i == 0 || i == 3 || i == 6)
      {
        front[i] = frontBUF[i];
        up[i] = upBUF[i];
        down[i] = downBUF[i];
      }
    }
    back[2] = backBUF[2];
    back[5] = backBUF[5];
    back[8] = backBUF[8];
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("L");
  }
  void LCCW() //Left rotation counter-clockwise
  {
    leftBUF[0] = left[2];
    leftBUF[1] = left[5];
    leftBUF[2] = left[8];
    leftBUF[3] = left[1];
    leftBUF[4] = left[4];
    leftBUF[5] = left[7];
    leftBUF[6] = left[0];
    leftBUF[7] = left[3];
    leftBUF[8] = left[6];
    upBUF[0] = front[0];
    upBUF[3] = front[3];
    upBUF[6] = front[6];
    frontBUF[0] = down[0];
    frontBUF[3] = down[3];
    frontBUF[6] = down[6];
    downBUF[0] = back[8];
    downBUF[3] = back[5];
    downBUF[6] = back[2];
    backBUF[2] = up[6];
    backBUF[5] = up[3];
    backBUF[8] = up[0];
    for(int i = 0; i < 9; i++)
    {
      left[i] = leftBUF[i];
      if(i == 0 || i == 3 || i == 6)
      {
        up[i] = upBUF[i];
        front[i] = frontBUF[i];
        down[i] = downBUF[i];
      }
    }
    back[2] = backBUF[2];
    back[5] = backBUF[5];
    back[8] = backBUF[8];
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("L'");
  }
  void XCW()
  {
    for(int i = 0; i < 9; i++)
    {
      frontBUF[i] = down[i];
      upBUF[i] = front[i];
    }
    downBUF[0] = back[8];
    downBUF[1] = back[7];
    downBUF[2] = back[6];
    downBUF[3] = back[5];
    downBUF[4] = back[4];
    downBUF[5] = back[3];
    downBUF[6] = back[2];
    downBUF[7] = back[1];
    downBUF[8] = back[0];
    leftBUF[0] = left[2];
    leftBUF[1] = left[5];
    leftBUF[2] = left[8];
    leftBUF[3] = left[1];
    leftBUF[4] = left[4];
    leftBUF[5] = left[7];
    leftBUF[6] = left[0];
    leftBUF[7] = left[3];
    leftBUF[8] = left[6];
    rightBUF[0] = right[6];
    rightBUF[1] = right[3];
    rightBUF[2] = right[0];
    rightBUF[3] = right[7];
    rightBUF[4] = right[4];
    rightBUF[5] = right[1];
    rightBUF[6] = right[8];
    rightBUF[7] = right[5];
    rightBUF[8] = right[2];
    backBUF[0] = up[8];
    backBUF[1] = up[7];
    backBUF[2] = up[6];
    backBUF[3] = up[5];
    backBUF[4] = up[4];
    backBUF[5] = up[3];
    backBUF[6] = up[2];
    backBUF[7] = up[1];
    backBUF[8] = up[0];
    for(int i = 0; i < 9; i++)
    {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      left[i] = leftBUF[i];
      right[i] = rightBUF[i];
      back[i] = backBUF[i];
    }
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("X");
  }
  void XCCW()
  {
    for(int i = 0; i < 9; i++)
    {
      frontBUF[i] = up[i];
      downBUF[i] = front[i];
      backBUF[i] = down[8-i];
      upBUF[i] = back[8-i];
    }
    leftBUF[0] = left[6];
    leftBUF[1] = left[3];
    leftBUF[2] = left[0];
    leftBUF[3] = left[7];
    leftBUF[4] = left[4];
    leftBUF[5] = left[1];
    leftBUF[6] = left[8];
    leftBUF[7] = left[5];
    leftBUF[8] = left[2];
    rightBUF[0] = right[2];
    rightBUF[1] = right[5];
    rightBUF[2] = right[8];
    rightBUF[3] = right[1];
    rightBUF[4] = right[4];
    rightBUF[5] = right[7];
    rightBUF[6] = right[0];
    rightBUF[7] = right[3];
    rightBUF[8] = right[6];
    for(int i = 0; i < 9; i++) {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      right[i] = rightBUF[i];
      left[i] = leftBUF[i];
      back[i] = backBUF[i];
    }
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
      sum += front[i];
      sum += up[i];
      sum += down[i];
      sum += left[i];
      sum += right[i];
      sum += back[i];
    }
    if(sum != 189) {
      Serial.println("problem");
    }
    sum = 0;
    Serial.println("X'");
  }
  void YCW()
  {
    for(int i = 0; i < 9; i++) {
      frontBUF[i] = right[i];
      leftBUF[i] = front[i];
      rightBUF[i] = back[i];
      backBUF[i] = left[i];
    }
    upBUF[0] = up[6];
    upBUF[1] = up[3];
    upBUF[2] = up[0];
    upBUF[3] = up[7];
    upBUF[4] = up[4];
    upBUF[5] = up[1];
    upBUF[6] = up[8];
    upBUF[7] = up[5];
    upBUF[8] = up[2];
    downBUF[0] = down[2];
    downBUF[1] = down[5];
    downBUF[2] = down[8];
    downBUF[3] = down[1];
    downBUF[4] = down[4];
    downBUF[5] = down[7];
    downBUF[6] = down[0];
    downBUF[7] = down[3];
    downBUF[8] = down[6];
    for(int i = 0; i < 9; i++) {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      left[i] = leftBUF[i];
      right[i] = rightBUF[i];
      back[i] = backBUF[i];
    }
    Serial.println("Y");
  }
  void YCCW()
  {
    for(int i = 0; i < 9; i++)
    {
      frontBUF[i] = left[i];
      leftBUF[i] = back[i];
      rightBUF[i] = front[i];
      backBUF[i] = right[i];
    }
    upBUF[0] = up[2];
    upBUF[1] = up[5];
    upBUF[2] = up[8];
    upBUF[3] = up[1];
    upBUF[4] = up[4];
    upBUF[5] = up[7];
    upBUF[6] = up[0];
    upBUF[7] = up[3];
    upBUF[8] = up[6];
    downBUF[0] = down[6];
    downBUF[1] = down[3];
    downBUF[2] = down[0];
    downBUF[3] = down[7];
    downBUF[4] = down[4];
    downBUF[5] = down[1];
    downBUF[6] = down[8];
    downBUF[7] = down[5];
    downBUF[8] = down[2];
    for(int i = 0; i < 9; i++) {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      left[i] = leftBUF[i];
      right[i] = rightBUF[i];
      back[i] = backBUF[i];
    }
    Serial.println("Y'");
  }
  void rCW()
  {
    frontBUF[0] = front[0];
    frontBUF[1] = down[1];
    frontBUF[2] = down[2];
    frontBUF[3] = front[3];
    frontBUF[4] = down[4];
    frontBUF[5] = down[5];
    frontBUF[6] = front[6];
    frontBUF[7] = down[7];
    frontBUF[8] = down[8];

    upBUF[0] = up[0];
    upBUF[1] = front[1];
    upBUF[2] = front[2];
    upBUF[3] = up[3];
    upBUF[4] = front[4];
    upBUF[5] = front[5];
    upBUF[6] = up[6];
    upBUF[7] = front[7];
    upBUF[8] = front[8];

    downBUF[0] = down[0];
    downBUF[1] = back[7];
    downBUF[2] = back[6];
    downBUF[3] = down[3];
    downBUF[4] = back[4];
    downBUF[5] = back[3];
    downBUF[6] = down[6];
    downBUF[7] = back[1];
    downBUF[8] = back[0];

    rightBUF[0] = right[6];
    rightBUF[1] = right[3];
    rightBUF[2] = right[0];
    rightBUF[3] = right[7];
    rightBUF[4] = right[4];
    rightBUF[5] = right[1];
    rightBUF[6] = right[8];
    rightBUF[7] = right[5];
    rightBUF[8] = right[2];

    backBUF[0] = up[8];
    backBUF[1] = up[7];
    backBUF[2] = back[2];
    backBUF[3] = up[5];
    backBUF[4] = up[4];
    backBUF[5] = back[5];
    backBUF[6] = up[2];
    backBUF[7] = up[1];
    backBUF[8] = back[8];
    for(int i = 0; i < 9; i++) {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      right[i] = rightBUF[i];
      back[i] = backBUF[i];
    }
    Serial.println("r");
  }
  void rCCW()
  {
    frontBUF[0] = front[0];
    frontBUF[1] = up[1];
    frontBUF[2] = up[2];
    frontBUF[3] = front[3];
    frontBUF[4] = up[4];
    frontBUF[5] = up[5];
    frontBUF[6] = front[6];
    frontBUF[7] = up[7];
    frontBUF[8] = up[8];

    upBUF[0] = up[0];
    upBUF[1] = back[7];
    upBUF[2] = back[6];
    upBUF[3] = up[3];
    upBUF[4] = back[4];
    upBUF[5] = back[3];
    upBUF[6] = up[6];
    upBUF[7] = back[1];
    upBUF[8] = back[0];

    downBUF[0] = down[0];
    downBUF[1] = front[1];
    downBUF[2] = front[2];
    downBUF[3] = down[3];
    downBUF[4] = front[4];
    downBUF[5] = front[5];
    downBUF[6] = down[6];
    downBUF[7] = front[7];
    downBUF[8] = front[8];

    rightBUF[0] = right[2];
    rightBUF[1] = right[5];
    rightBUF[2] = right[8];
    rightBUF[3] = right[1];
    rightBUF[4] = right[4];
    rightBUF[5] = right[7];
    rightBUF[6] = right[0];
    rightBUF[7] = right[3];
    rightBUF[8] = right[6];

    backBUF[0] = down[8];
    backBUF[1] = down[7];
    backBUF[2] = back[2];
    backBUF[3] = down[5];
    backBUF[4] = down[4];
    backBUF[5] = back[5];
    backBUF[6] = down[2];
    backBUF[7] = down[1];
    backBUF[8] = back[8];
    for(int i = 0; i < 9; i++) {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      right[i] = rightBUF[i];
      back[i] = backBUF[i];
    }
    Serial.println("r'");
  }
  void lCW()
  {
    frontBUF[0] = up[0];
    frontBUF[1] = up[1];
    frontBUF[2] = front[2];
    frontBUF[3] = up[3];
    frontBUF[4] = up[4];
    frontBUF[5] = front[5];
    frontBUF[6] = up[6];
    frontBUF[7] = up[7];
    frontBUF[8] = front[8];

    upBUF[0] = back[8];
    upBUF[1] = back[7];
    upBUF[2] = up[2];
    upBUF[3] = back[5];
    upBUF[4] = back[4];
    upBUF[5] = up[5];
    upBUF[6] = back[2];
    upBUF[7] = back[1];
    upBUF[8] = up[8];

    downBUF[0] = front[0];
    downBUF[1] = front[1];
    downBUF[2] = down[2];
    downBUF[3] = front[3];
    downBUF[4] = front[4];
    downBUF[5] = down[5];
    downBUF[6] = front[6];
    downBUF[7] = front[7];
    downBUF[8] = down[8];

    leftBUF[0] = left[6];
    leftBUF[1] = left[3];
    leftBUF[2] = left[0];
    leftBUF[3] = left[7];
    leftBUF[4] = left[4];
    leftBUF[5] = left[1];
    leftBUF[6] = left[8];
    leftBUF[7] = left[5];
    leftBUF[8] = left[2];

    backBUF[0] = back[0];
    backBUF[1] = down[7];
    backBUF[2] = down[6];
    backBUF[3] = back[3];
    backBUF[4] = down[4];
    backBUF[5] = down[3];
    backBUF[6] = back[6];
    backBUF[7] = down[1];
    backBUF[8] = down[0];
    for(int i = 0; i < 9; i++) {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      left[i] = leftBUF[i];
      back[i] = backBUF[i];
    }
    Serial.println("l");
  }
  void lCCW()
  {
    frontBUF[0] = down[0];
    frontBUF[1] = down[1];
    frontBUF[2] = front[2];
    frontBUF[3] = down[3];
    frontBUF[4] = down[4];
    frontBUF[5] = front[5];
    frontBUF[6] = down[6];
    frontBUF[7] = down[7];
    frontBUF[8] = front[8];

    upBUF[0] = front[0];
    upBUF[1] = front[1];
    upBUF[2] = up[2];
    upBUF[3] = front[3];
    upBUF[4] = front[4];
    upBUF[5] = up[5];
    upBUF[6] = front[6];
    upBUF[7] = front[7];
    upBUF[8] = up[8];

    downBUF[0] = back[8];
    downBUF[1] = back[7];
    downBUF[2] = down[2];
    downBUF[3] = back[5];
    downBUF[4] = back[4];
    downBUF[5] = down[5];
    downBUF[6] = back[2];
    downBUF[7] = back[1];
    downBUF[8] = down[8];

    leftBUF[0] = left[2];
    leftBUF[1] = left[5];
    leftBUF[2] = left[8];
    leftBUF[3] = left[1];
    leftBUF[4] = left[4];
    leftBUF[5] = left[7];
    leftBUF[6] = left[0];
    leftBUF[7] = left[3];
    leftBUF[8] = left[6];

    backBUF[0] = back[0];
    backBUF[1] = up[7];
    backBUF[2] = up[6];
    backBUF[3] = back[3];
    backBUF[4] = up[4];
    backBUF[5] = up[3];
    backBUF[6] = back[6];
    backBUF[7] = up[1];
    backBUF[8] = up[0];
    for(int i = 0; i < 9; i++) {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      left[i] = leftBUF[i];
      back[i] = backBUF[i];
    }
    Serial.println("l'");
  }
  void MCW()
  {
    frontBUF[1] = up[1];
    frontBUF[4] = up[4];
    frontBUF[7] = up[7];
    upBUF[1] = back[7];
    upBUF[4] = back[4];
    upBUF[7] = back[1];
    downBUF[1] = front[1];
    downBUF[4] = front[4];
    downBUF[7] = front[7];
    backBUF[1] = down[7];
    backBUF[4] = down[4];
    backBUF[7] = down[1];
    for(int i = 1; i < 8;)
    {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      back[i] = backBUF[i];
      i += 3;
    }
    Serial.println("M");
  }
  void MCCW()
  {
    frontBUF[1] = down[1];
    frontBUF[4] = down[4];
    frontBUF[7] = down[7];
    upBUF[1] = front[1];
    upBUF[4] = front[4];
    upBUF[7] = front[7];
    downBUF[1] = back[7];
    downBUF[4] = back[4];
    downBUF[7] = back[1];
    backBUF[1] = up[7];
    backBUF[4] = up[4];
    backBUF[7] = up[1];
    for(int i = 1; i < 8;) {
      front[i] = frontBUF[i];
      up[i] = upBUF[i];
      down[i] = downBUF[i];
      back[i] = backBUF[i];
      i += 3;
    }
    Serial.println("M'");
  }
};

#endif