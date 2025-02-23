#include "Util/Map.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

namespace Map {
// Function declaration
std::string getColoredName(const std::string &name);

void Draw(const std::vector<std::shared_ptr<Object::GameObject>> &object) {
  std::vector<Rendered> rendered_list;

  for (auto i = 0; i < WIDTH; ++i) {
    for (auto j = 0; j < HEIGHT; ++j) {
      std::string name = "     ";

      for (const auto &elem : object) {
        bool state = false;

        for (const auto &r_elem : rendered_list) {
          if (elem->GetPosition() == Object::GamePosition{j, HEIGHT - i - 1} &&
              r_elem.pos == elem->GetPosition()) {
            // name = " " + elem->GetName() + "/" + r_elem.name + " ";
            name = " " + getColoredName(elem->GetName()) + "/" +
                   getColoredName(r_elem.name) + " ";
            state = true;
          }
        }

        if (elem->GetPosition() == Object::GamePosition{j, HEIGHT - i - 1} &&
            !state) {
          // name = "  " + elem->GetName() + "  ";
          name = "  " + getColoredName(elem->GetName()) + "  ";

          rendered_list.push_back(
              Rendered{{j, HEIGHT - i - 1}, elem->GetName()});
        }
      }

      std::cout << "|" << name;

      if (j == WIDTH - 1)
        std::cout << "|\n";
    }
  }
  printf("next: ---------------------------------------------\n");
}

// Function definition
std::string getColoredName(const std::string &name) {
  if (name == "P")
    return RED + name + RESET;
  if (name == "d")
    return GREEN + name + RESET;
  if (name == "x")
    return YELLOW + name + RESET;
  return name;
}
} // namespace Map