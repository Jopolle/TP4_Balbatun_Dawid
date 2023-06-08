#pragma once

class arm
{
private:
    float x1, y1, l, r, x2, y2;
public:
    arm();
    arm(float x1, float y1, float l, float r, float x2, float y2);
    void calculatePosition();
    void moveAnchor(float x2, float y2);
    float getX();
    float getY();
    float getAnchorX();
    float getAnchorY();
    float getRadius();
};