#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Button.h"

class Game
{
public:
    Game();
    ~Game();

    void Update();
    void Render();
    void HandleEvent();

    bool IsOver();
private:
    sf::RenderWindow* m_window;
};

#endif // GAME_H_INCLUDED
