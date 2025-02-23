#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

struct Point {
    int x = 0;
    int y = 0;
    Point(int x = 0, int y = 0)
        : x(x),
          y(y) {}
};

class Character {
protected:
    std::string id;
    Point position;

public:
    Character(std::string id, Point startPos);
    virtual ~Character() = default;

    virtual void DoBehavior() = 0;

    Point GetPosition() const;
    void SetPosition(int x, int y);
    void SetPosition(Point newPos);

    bool IsColliding(const Character *other) const;

    virtual void SetPacmanPosition(Point pos);
};

#endif