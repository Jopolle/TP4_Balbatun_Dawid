#include "arm.h"
#define _USE_MATH_DEFINES
#include <cmath>

arm::arm()
{
    x1 = 0.f;
    y1 = 0.f;
    l = 50.f;
    l = 10.f;
    x2 = 0.f;
    y2 = 0.f;
}

arm::arm(float x1, float y1, float l, float r, float x2, float y2)
{
    arm::x1 = x1;
    arm::y1 = y1;
    arm::l = l;
    arm::r = r;
    arm::x2 = x2;
    arm::y2 = y2;
}

void arm::calculatePosition() {




}

void arm::moveAnchor(float x, float y)
{
    x1 = x;
    y1 = y;
}

float arm::getX()
{
    return x2;
}

float arm::getY()
{
    return y2;
}

float arm::getAnchorX()
{
    return x1;
}

float arm::getAnchorY()
{
    return y1;
}

float arm::getRadius()
{
    return r;
}
