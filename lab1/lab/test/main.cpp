// #include "Util.hpp"

// int main(){
//     struct Point point(0,0);
//     struct Point point1(15,15);
//     struct Point point2(0,15);
//     struct Point point3(7,7);
//     struct Point point4(10,10);
//     Draw(point,point1,point2,point3,point4);
// }

#include "../include/Blinky.hpp"
#include "../include/Character.hpp"
#include "../include/Clyde.hpp"
#include "../include/Inky.hpp"
#include "../include/Pacman.hpp"
#include "../include/Pinky.hpp"
#include "../include/Util.hpp"
#include <iostream>

// void TestCharacterMovement() {
//     std::cout << "--- Testing Character Movement ---\n";

//     Blinky blinky;
//     Inky inky;
//     Pinky pinky;
//     Clyde clyde;
//     Pacman pacman;

//     Draw(blinky.GetPosition(), inky.GetPosition(), pinky.GetPosition(),
//          clyde.GetPosition(), pacman.GetPosition());
// }

// void TestCollisionDetection() {
//     std::cout << "--- Testing Collision Detection ---\n";

//     Pacman pacman("Pacman");
//     Blinky blinky("Blinky");

//     // Move characters to the same position
//     blinky.SetPosition(pacman.GetPosition());

//     std::cout << "Pacman Position: (" << pacman.GetPosition().x << ","
//               << pacman.GetPosition().y << ")\n";
//     std::cout << "Blinky Position: (" << blinky.GetPosition().x << ","
//               << blinky.GetPosition().y << ")\n";

//     std::cout << "Collision: " << (pacman.IsColliding(&blinky) ? "Yes" :
//     "No")
//               << std::endl;
// }

// void TestBoundaryChecking() {
//     std::cout << "--- Testing Boundary Checking ---\n";

//     Pacman pacman;

//     std::cout << "Initial Position: (" << pacman.GetPosition().x << ","
//               << pacman.GetPosition().y << ")\n";

//     // Try to move beyond boundaries
//     pacman.SetPosition(-5, -5);
//     std::cout << "After setting to (-5,-5): (" << pacman.GetPosition().x <<
//     ","
//               << pacman.GetPosition().y << ")\n";

//     pacman.SetPosition(20, 20);
//     std::cout << "After setting to (20,20): (" << pacman.GetPosition().x <<
//     ","
//               << pacman.GetPosition().y << ")\n";
// }

// void TestGameInteraction() {
//     std::cout << "--- Testing Game Interaction ---\n";

//     Pacman pacman("Pacman");
//     Blinky blinky("Blinky");
//     Inky inky("Inky");
//     Pinky pinky("Pinky");
//     Clyde clyde("Clyde");

//     int turns = 0;
//     bool gameOver = false;

//     while (!gameOver && turns < 50) {
//         std::cout << "\n--- Turn " << turns + 1 << " ---\n";

//         // Draw current positions
//         Draw(blinky.GetPosition(), inky.GetPosition(), pinky.GetPosition(),
//              clyde.GetPosition(), pacman.GetPosition());

//         // Pacman move with cin input
//         std::cout << "Enter move (W/A/S/D): ";
//         char input;
//         std::cin >> input;
//         pacman.Move(input);

//         // Clyde needs Pacman's position
//         clyde.SetPacmanPosition(pacman.GetPosition());

//         // Move enemies
//         blinky.DoBehavior();
//         inky.DoBehavior();
//         pinky.DoBehavior();
//         clyde.DoBehavior();

//         std::cout << "- blinky Positions:\n";
//         std::cout << blinky.GetPosition().x << ",";
//         std::cout << blinky.GetPosition().y << std::endl;

//         std::cout << "- inky Positions:\n";
//         std::cout << inky.GetPosition().x << ",";
//         std::cout << inky.GetPosition().y << std::endl;

//         std::cout << "- pinky Positions:\n";
//         std::cout << pinky.GetPosition().x << ",";
//         std::cout << pinky.GetPosition().y << std::endl;

//         std::cout << "- clyde Positions:\n";
//         std::cout << clyde.GetPosition().x << ",";
//         std::cout << clyde.GetPosition().y << std::endl;

//         std::cout << "- pacman Positions:\n";
//         std::cout << pacman.GetPosition().x << ",";
//         std::cout << pacman.GetPosition().y << std::endl;

//         // Check collisions
//         if (blinky.IsColliding(&pacman) || inky.IsColliding(&pacman) ||
//             pinky.IsColliding(&pacman) || clyde.IsColliding(&pacman)) {
//             std::cout << "Game Over! You were caught!\n";
//             gameOver = true;
//         }

//         turns++;
//     }

//     if (!gameOver) {
//         std::cout << "Congratulations! You survived 50 turns!\n";
//     }
// }

// int main() {
//     // TestCharacterMovement();
//     // TestCollisionDetection();
//     // TestBoundaryChecking();
//     TestGameInteraction();
//     return 0;
// }

#include <vector>

void TestGameInteraction() {
    std::cout << "--- Testing Game Interaction ---\n";

    std::vector<Character *> characters;
    Pacman *pacman = new Pacman("Pacman");
    characters.push_back(new Blinky("Blinky"));
    characters.push_back(new Inky("Inky"));
    characters.push_back(new Pinky("Pinky"));
    characters.push_back(new Clyde("Clyde"));
    characters.push_back(pacman);

    int turns = 0;
    bool gameOver = false;

    while (!gameOver && turns < 50) {
        std::cout << "\n--- Turn " << turns + 1 << " ---\n";

        Draw(characters[0]->GetPosition(), characters[1]->GetPosition(),
             characters[2]->GetPosition(), characters[3]->GetPosition(),
             characters[4]->GetPosition());

        // Clyde needs Pacman's position
        characters[3]->SetPacmanPosition(pacman->GetPosition());

        std::cout << "Enter move (W/A/S/D): ";
        char input;
        std::cin >> input;
        pacman->Move(input);

        // Move enemies
        for (auto *character : characters) {
            if (character != pacman) {
                character->DoBehavior();
            }
        }

        std::cout << "- blinky Positions:\n";
        std::cout << characters[0]->GetPosition().x << ",";
        std::cout << characters[0]->GetPosition().y << std::endl;

        std::cout << "- inky Positions:\n";
        std::cout << characters[1]->GetPosition().x << ",";
        std::cout << characters[1]->GetPosition().y << std::endl;

        std::cout << "- pinky Positions:\n";
        std::cout << characters[2]->GetPosition().x << ",";
        std::cout << characters[2]->GetPosition().y << std::endl;

        std::cout << "- clyde Positions:\n";
        std::cout << characters[3]->GetPosition().x << ",";
        std::cout << characters[3]->GetPosition().y << std::endl;

        std::cout << "- pacman Positions:\n";
        std::cout << pacman->GetPosition().x << ",";
        std::cout << pacman->GetPosition().y << std::endl;

        // Check collisions
        for (auto *character : characters) {
            if (character != pacman && character->IsColliding(pacman)) {
                std::cout << "Game Over! You were caught!\n";
                gameOver = true;
                break;
            }
        }

        turns++;
    }

    if (!gameOver) {
        std::cout << "Congratulations! You survived 50 turns!\n";
    }

    // 釋放記憶體
    for (auto *character : characters) {
        delete character;
    }
}

int main() {
    TestGameInteraction();
    return 0;
}
