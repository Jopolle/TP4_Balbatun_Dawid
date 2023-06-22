//
// Created by pablitto on 09.06.23.
//

#include "robotArm.h"
robotArm::robotArm(sf::Vector2f origin, sf::Vector2f destination)
        : origin(origin), destination(destination), a1(origin, mid), a2(mid, destination), a3(origin, destination)
{
    mid = {WIDTH_CONST, HEIGHT_CONST};
    a1.setLength(ARM_LENGTH);
    a2.setLength(ARM_LENGTH);
    c1.setRadius(15.f);
    c1.setFillColor(sf::Color(100,100,100));
    c2.setRadius(15.f);
    c2.setFillColor(sf::Color(100,100,100));
    claw.setPointCount(6);

}
void robotArm::calculatePosition() {
    float teta = std::abs(a3.getTheta())*0.0174532925199433f;
    a=(sqrt(std::pow(origin.x-destination.x,2)+std::pow(origin.y-destination.y, 2)))/2;
    beta = asin(a/a1.getLength()-0.01);
    alpha = 1.570796326795f - teta + beta;
    x1 = cos(alpha)*a1.getLength();
    y1 = sin(alpha)*a1.getLength();
    mid = {origin.x - x1, origin.y - y1};
    destination2 = {destination.x+5, destination.y};
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
    c1.setPosition(mid.x-10 , mid.y-10);
    c2.setPosition(destination.x - 10, destination.y -10);
    clawUpdate();

}

void robotArm::draw(sf::RenderWindow& window) {
    a1.draw(window);
    a2.draw(window);
    window.draw(claw);
    window.draw(c1);
    window.draw(c2);
      //drawGrip(window);
};

void robotArm::clawUpdate() {
    claw.setPoint(0, destination2);
    claw.setPoint(1, {destination2.x+15, destination2.y+25});
    claw.setPoint(2, {destination2.x+30, destination2.y+45});
    claw.setPoint(3, {destination2.x, destination2.y+10});
    claw.setPoint(4, {destination2.x-30, destination2.y+45});
    claw.setPoint(5, {destination2.x-15, destination2.y+25});
    claw.setFillColor(sf::Color(80,80,80));
};

void robotArm::drawGrip(sf::RenderWindow &window) {
    sf::Vector2f gripSize(20.0f, 60.0f); // Rozmiar uchwytu
    sf::Vector2f gripOffset(gripSize.x / 2.0f, gripSize.y); // Przesunięcie uchwytu względem końca ramienia

    // Obliczanie pozycji uchwytu
    sf::Vector2f gripPosition = destination - gripOffset;

    // Tworzenie prostokątnego kształtu uchwytu
    sf::RectangleShape gripShape(gripSize);
    gripShape.setPosition(gripPosition);
    gripShape.setFillColor(sf::Color::Yellow);
}