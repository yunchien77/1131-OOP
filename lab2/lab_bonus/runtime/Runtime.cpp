#include "Interface/MonsterMovable.hpp"
#include "Object/GameObject.hpp"
#include "Util/Map.hpp"
#include "Util/RuntimeFramework.hpp"
#include <iostream>
#include <memory>
#include <vector>

namespace Util {

void RuntimeFramework::Initial() {
  std::cout << "Game initial..." << std::endl;
  std::vector<Object::GamePosition> dotPositions = {
      {2, 8}, {9, 9}, {8, 3}, {5, 7}};
  std::vector<Object::GamePosition> cherryPositions = {{1, 1}, {1, 9}, {9, 1}};

  point_manager = std::make_shared<DotManager>(player, dotPositions);
  cherry_manager = std::make_shared<CherryManager>(player, cherryPositions);

  state = RuntimeState::RUNNING;
}

void RuntimeFramework::Running() {
  // std::cout << "Game running..." << std::endl;
  char input;
  std::cout << "Enter your move: ";
  std::cin >> input;

  switch (input) {
  case 'w':
  case 'a':
  case 's':
  case 'd':
    player->Move(input);

    // Move ghosts
    blinky->Move(player->GetPosition());
    inky->Move(player->GetPosition());
    pinky->Move(player->GetPosition());
    clyde->Move(player->GetPosition());
    break;
  case 'c':
    blinky->SetState(Object::MonsterState::Chase);
    inky->SetState(Object::MonsterState::Chase);
    pinky->SetState(Object::MonsterState::Chase);
    clyde->SetState(Object::MonsterState::Chase);
    break;
  case 'x':
    blinky->SetState(Object::MonsterState::Scatter);
    inky->SetState(Object::MonsterState::Scatter);
    pinky->SetState(Object::MonsterState::Scatter);
    clyde->SetState(Object::MonsterState::Scatter);
    break;
  default:
    break;
  }

  // Check collisions
  std::vector<Object::GamePosition> ghostPositions = {
      blinky->GetPosition(), inky->GetPosition(), pinky->GetPosition(),
      clyde->GetPosition()};

  auto playerPos = player->GetPosition();
  for (const auto &pos : ghostPositions) {
    if (pos == playerPos) {
      state = RuntimeState::END;
      return;
    }
  }

  // Check dots
  if (point_manager->IsOverlapping()) {
    if (point_manager->GetPointListSize() == 0 &&
        cherry_manager->GetPointListSize() == 0) {
      state = RuntimeState::END;
    }
  }

  if (cherry_manager->IsOverlapping()) {
    if (point_manager->GetPointListSize() == 0 &&
        cherry_manager->GetPointListSize() == 0) {
      state = RuntimeState::END;
    }
  }
}

void RuntimeFramework::Render() {
  // std::cout << "Game rendering..." << std::endl;
  std::vector<std::shared_ptr<Object::GameObject>> objects;
  objects.push_back(player);
  objects.push_back(blinky);
  objects.push_back(inky);
  objects.push_back(pinky);
  objects.push_back(clyde);

  auto dots = point_manager->GetPointList();
  auto cherries = cherry_manager->GetPointList();
  objects.insert(objects.end(), dots.begin(), dots.end());
  objects.insert(objects.end(), cherries.begin(), cherries.end());
  // std::cout << "Objects: " << objects.size() << std::endl;
  Map::Draw(objects);
}

void RuntimeFramework::End() {
  if (point_manager->GetPointListSize() == 0) {
    // std::cout << "You Win!\n";
    std::cout << "\n\n";
    std::cout << R"(
#     #  #######  #     #    #     #  ###  #     #   # 
 #   #   #     #  #     #    #     #   #   ##    #   #  
  # #    #     #  #     #    #     #   #   # #   #   #  
   #     #     #  #     #    #     #   #   #  #  #   #  
   #     #     #  #     #    #  #  #   #   #   # #   #  
   #     #     #  #     #    # # # #   #   #    ##     
   #      #####    #####      #   #   ###  #     #  ###  
)" << std::endl;
  } else {
    // std::cout << "Game Over!\n";
    std::cout << "\n\n";
    std::cout << "  ######      ###    ##     ## ########     #######  ##     "
                 "## ######## ########  \n";
    std::cout << " ##    ##    ## ##   ###   ### ##          ##     ## ##     "
                 "## ##       ##     ## \n";
    std::cout << " ##         ##   ##  #### #### ##          ##     ## ##     "
                 "## ##       ##     ## \n";
    std::cout << " ##   #### ##     ## ## ### ## ######      ##     ## ##     "
                 "## ######   ########  \n";
    std::cout << " ##    ##  ######### ##     ## ##          ##     ##  ##   "
                 "##  ##       ##   ##   \n";
    std::cout << " ##    ##  ##     ## ##     ## ##          ##     ##   ## ## "
                 "  ##       ##    ##  \n";
    std::cout << "  ######   ##     ## ##     ## ########     #######     ###  "
                 "  ######## ##     ## \n";
  }
}
}; // namespace Util
