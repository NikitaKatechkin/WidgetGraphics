#include "Button.h"

/*Button::Button()
{
    m_backgroundWarp.setFillColor(sf::Color::Red);

    for(int index = 0; index < 4; index++)
    {
        m_roundAngles[index].setFillColor(sf::Color::Blue);
        m_roundAngles[index].setRadius(20.f);
    }

    //Vertical
    m_fillers[0].setSize(m_backgroundWarp.getSize() - sf::Vector2f(m_roundAngles[0].getRadius() * 2.f, 0.f));
    m_fillers[0].setFillColor(sf::Color::Blue);
    //Horizontal
    m_fillers[1].setSize(m_backgroundWarp.getSize() - sf::Vector2f(0.f, m_roundAngles[0].getRadius() * 2.f));
    m_fillers[1].setFillColor(sf::Color::Blue);

    //Must be
    SetPosition(GetPosition());
}*/

Button::Button(const sf::Vector2f& l_buttonSize,  const float& l_roundingRadius, const sf::Color& l_color)
{
    SetPosition(l_buttonSize);
    m_backgroundWarp.setFillColor(sf::Color::Transparent);

    ConfigureCorners(l_roundingRadius, l_color);
    /*for(int index = 0; index < 4; index++)
    {
        m_roundAngles[index].setFillColor(sf::Color::Blue);
        m_roundAngles[index].setRadius(l_roundingRadius);
    }*/

    /*//Vertical
    m_fillers[0].setSize(m_backgroundWarp.getSize() - sf::Vector2f(m_roundAngles[0].getRadius() * 2.f, 0.f));
    m_fillers[0].setFillColor(sf::Color::Blue);
    //Horizontal
    m_fillers[1].setSize(m_backgroundWarp.getSize() - sf::Vector2f(0.f, m_roundAngles[0].getRadius() * 2.f));
    m_fillers[1].setFillColor(sf::Color::Blue);*/

    ConfigureFillers(l_color);
    //Must be
    SetPosition(GetPosition());
}

Button::~Button()
{

}

void Button::SetPosition(const sf::Vector2f& l_pos)
{
    // Настроили подложку кнопки
    m_backgroundWarp.setPosition(l_pos);
    //Настроить скругленные края
    sf::Vector2f wrap_pos = m_backgroundWarp.getPosition();
    sf::Vector2f wrap_size = m_backgroundWarp.getSize();
    //Left Up
    m_roundAngles[0].setPosition(wrap_pos + sf::Vector2f(0.f,
                                                         0.f));
    //Left Down
    m_roundAngles[1].setPosition(wrap_pos + sf::Vector2f(0.f,
                                                         wrap_size.y - 2.f * m_roundAngles[1].getRadius()));
    //Right Up
    m_roundAngles[2].setPosition(wrap_pos + sf::Vector2f(wrap_size.x - 2.f * m_roundAngles[2].getRadius(),
                                                         0.f));
    //Right Down
    m_roundAngles[3].setPosition(wrap_pos + sf::Vector2f(wrap_size.x - 2.f * m_roundAngles[3].getRadius(),
                                                         wrap_size.y - 2.f * m_roundAngles[3].getRadius()));

    m_fillers[0].setPosition(wrap_pos + sf::Vector2f(m_roundAngles[0].getRadius(), 0.f));
    m_fillers[1].setPosition(wrap_pos + sf::Vector2f(0.f, m_roundAngles[0].getRadius()));
}

sf::Vector2f Button::GetPosition()
{
    return m_backgroundWarp.getPosition();
}

void Button::SetSize(const sf::Vector2f& l_size)
{
    m_backgroundWarp.setSize(l_size);

    ConfigureFillers(m_roundAngles[0].getFillColor());
}

sf::Vector2f Button::GetSize()
{
    return m_backgroundWarp.getSize();
}

void Button::Update()
{

}

void Button::Draw(sf::RenderWindow& l_window)
{
    l_window.draw(m_backgroundWarp);

    for (int index = 0; index < 4; index++)
    {
        l_window.draw(m_roundAngles[index]);
    }

    for (int index = 0; index < 2; index++)
    {
        l_window.draw(m_fillers[index]);
    }
}

void Button::ConfigureCorners(const float& l_roundingRadius, const sf::Color& l_color)
{
    for(int index = 0; index < 4; index++)
    {
        m_roundAngles[index].setFillColor(l_color);
        m_roundAngles[index].setRadius(l_roundingRadius);
    }
}

void Button::ConfigureFillers(const sf::Color& l_color)
{
    //Vertical
    m_fillers[0].setSize(m_backgroundWarp.getSize() - sf::Vector2f(m_roundAngles[0].getRadius() * 2.f, 0.f));
    m_fillers[0].setFillColor(l_color);
    //Horizontal
    m_fillers[1].setSize(m_backgroundWarp.getSize() - sf::Vector2f(0.f, m_roundAngles[0].getRadius() * 2.f));
    m_fillers[1].setFillColor(l_color);
}
