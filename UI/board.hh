#ifndef __UI_BOARD_MASTERMIND_HH__
#define __UI_BOARD_MASTERMIND_HH__

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable
{
public:
    Board();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates);
};

#endif
