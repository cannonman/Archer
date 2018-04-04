#ifndef ARROW_H
#define ARROW_H
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Arrow : public sf::Drawable
{
    public:
        Arrow (float x, float y);
        Arrow()=delete;
        virtual ~Arrow() = default;

    protected:

    private:
        RectangleShape arrow;
};

#endif // ARROW_H
