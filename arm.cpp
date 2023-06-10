#include "arm.h"
#include <cmath>

arm::arm(){
    x1 = SCREEN_WIDTH/2;
    y1 = SCREEN_HEIGHT - 10;
    l = 50.f;
    x2 = 0.f;
    y2 = 0.f;
}

arm::arm(float x1, float y1, float l, float x2, float y2){
    arm::x1 = x1;
    arm::y1 = y1;
    arm::l = l;
    arm::x2 = x2;
    arm::y2 = y2;
}


float arm::getX(){
    return x2;
}

float arm::getY(){
    return y2;
}

float arm::getAnchorX(){
    return x1;
}

float arm::getAnchorY(){
    return y1;
}

float arm::getLength() {
    return l;
}