#include "../include/Util.hpp"
#include <iostream>
#include <string>

void Draw(Point BlinkyPoint, Point InkyPoint, Point PinkyPoint,
          Point ClydePoint, Point PacmanPoint, Point AmbusherPoint) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            std::string name = ".....";
            if (BlinkyPoint.x == j && BlinkyPoint.y == i) {
                name = "..B..";
            }
            if (InkyPoint.x == j && InkyPoint.y == i) {
                name = "..I..";
            }
            if (PinkyPoint.x == j && PinkyPoint.y == i) {
                name = "..P..";
            }
            if (ClydePoint.x == j && ClydePoint.y == i) {
                name = "..C..";
            }
            if (PacmanPoint.x == j && PacmanPoint.y == i) {
                name = "..O..";
            }
            if (AmbusherPoint.x == j && AmbusherPoint.y == i)
                name = "..A..";
            std::cout << "|" << name;
            if (j == 15)
                std::cout << "|\n";
        }
    }
}
