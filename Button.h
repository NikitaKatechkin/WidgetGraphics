#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <SFML/Graphics.hpp>

class Button
{
public:
    //Button();
    Button(const sf::Vector2f& l_buttonSize = sf::Vector2f(0.f, 0.f), const float& l_roundingRadius = 0.f,
           const sf::Color& l_color = sf::Color::White);
    ~Button();

    void SetPosition(const sf::Vector2f& l_pos);
    sf::Vector2f GetPosition();

    void SetSize(const sf::Vector2f& l_size);
    sf::Vector2f GetSize();

    void Update();

    void Draw(sf::RenderWindow& l_window);
private:
    sf::RectangleShape m_backgroundWarp;

    sf::RectangleShape m_fillers[2];
    sf::CircleShape m_roundAngles[4];

    void ConfigureCorners(const float& l_roundingRadius, const sf::Color& l_color);
    void ConfigureFillers(const sf::Color& l_color);
};

#endif // BUTTON_H_INCLUDED
