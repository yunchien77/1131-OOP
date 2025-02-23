#include "Util/RuntimeFramework.hpp"
#include <iostream>
int main() {
  std::cout << "Game starting..." << std::endl;

  Util::RuntimeFramework runtime;
  runtime.Initial();
  runtime.Render();

  while (runtime.GetState() != Util::RuntimeState::END) {
    runtime.Running();
    runtime.Render();
  }

  runtime.End();

  return 0;
}
