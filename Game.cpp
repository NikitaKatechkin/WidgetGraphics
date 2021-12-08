#include "Game.h"

Game::Game()
{
    m_window = new sf::RenderWindow(sf::VideoMode(640,480), "First window!");
}

Game::~Game()
{
    delete m_window;
}

void Game::Update()
{

}

void Game::Render()
{
    m_window->clear(sf::Color::Black);
    // Draw here.
    Button test_button(sf::Vector2f(0.f, 0.f), 20.f);
    test_button.SetSize(sf::Vector2f(100.f, 100.f));
    test_button.SetPosition(sf::Vector2f(50.f, 50.f));
    test_button.Draw(*m_window);
    // End draw.
    m_window->display();
}

void Game::HandleEvent()
{
    sf::Event event;
    while(m_window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            // Close window button clicked.
            m_window->close();
        }
    }
}

bool Game::IsOver()
{
    return !m_window->isOpen();
}
