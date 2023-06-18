#include "robotArm.h"
robotArm::robotArm(sf::Vector2f origin, sf::Vector2f destination)
        : origin(origin), destination(destination), a1(origin, mid), a2(mid, destination), a3(origin, destination)
{

    mid = {WIDTH_CONST, HEIGHT_CONST};
    a1.setLength(ARM_LENGTH);
    a2.setLength(ARM_LENGTH);
}

void robotArm::calculatePosition() {
    float teta = std::abs(a3.getTheta())*0.0174532925199433f;
    a=(sqrt(std::pow(origin.x-destination.x,2)+std::pow(origin.y-destination.y, 2)))/2;
    beta = asin(a/a1.getLength()-0.01);
    alpha = 1.570796326795f - teta + beta;
    x1 = cos(alpha)*a1.getLength();
    y1 = sin(alpha)*a1.getLength();
    mid = {origin.x - x1, origin.y - y1};
}

void robotArm::setDestination(sf::Vector2f newDestination) {
    destination = newDestination;
}

void robotArm::update(){
    a3.setEnd(destination);
    a1.setEnd(mid);
    calculatePosition();
    a2.setOrigin(mid);
    a2.setEnd(destination);

}
void robotArm::draw(sf::RenderWindow& window) {
    a1.draw(window);
    a2.draw(window);
    //std::cout<<a3.getTheta()<<std::endl;
};
