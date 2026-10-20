#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;

int main() {
  cout << "Hello, World!";

  // Create the main window
  sf::RenderWindow window(sf::VideoMode({1280, 720}), "Bouncing Ball");
  window.setFramerateLimit(60);

  // Circle
  sf::CircleShape shape(30.f);
  shape.setOrigin({30.f, 30.f});
  shape.setFillColor(sf::Color::Green);
  sf::Vector2f circlePos(1280 / 2, 720 / 2);
  shape.setPosition(circlePos);

  float xVelocity = 3;
  float yVelocity = 5;
  float xAcceleration = 0;
  float yAcceleration = 0.5;

  while (window.isOpen()) {
    while (const auto event = window.pollEvent()) {
      // "close requested" event: we close the window
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      
      if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->code == sf::Keyboard::Key::Escape) {
          window.close();
        }
      }
    }
    //physics

    if (circlePos.x < 0 + 40) {
      circlePos.x = 0 + 40;
      xVelocity = -xVelocity;
    } else if (circlePos.x > 1280 - 40) {
      circlePos.x = 1280 - 40;
      xVelocity = -xVelocity;
    }

    if (circlePos.y < 0 + 40) {
      circlePos.y = 0 + 40;
      yVelocity = -yVelocity;
    } else if (circlePos.y > 720 - 40) {
      circlePos.y = 720 - 40;
      yVelocity = -yVelocity;
    }

    xVelocity += xAcceleration;
    yVelocity += yAcceleration;

    circlePos.x += xVelocity;
    circlePos.y += yVelocity;
    shape.setPosition(circlePos);

    window.clear();
    window.draw(shape);
    window.display();
  }
};

// attributes to give to shapes:
// veloctiy
// accelecration
// rotation
// rotation speed
// collision (T/F)
// gravity (T/F), what direction?
// bound by edges (T/F)
// anchored (T/F)
