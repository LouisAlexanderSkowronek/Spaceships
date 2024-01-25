/*
MIT License

Copyright (c) 2024 LouisAlexanderSkowronek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Spaceship/copyright_limitations.hpp"

#include "Spaceship/main_menu.hpp"

#include <SFML/Audio.hpp>

extern std::mt19937 randint;
extern sf::VideoMode window_size;

Spaceship::MainMenu::MainMenu(const sf::Font& font, Bg& bg) : m_bg(bg)
{
    m_buttons.reserve(3u);

    // Singleplayer Button
    Button btn_singleplayer(sf::Text("Singleplayer", font, 45), sf::RectangleShape(sf::Vector2f(500.0f, 100.0f)), 
        [](sf::Music* musics_ptr, unsigned int& stage) {
            #ifndef COPYRIGHT_LIMITED
                if (musics_ptr == nullptr) { throw std::runtime_error("Invalid music loaded!"); }
                musics_ptr[stage].stop();
                stage = 1;
                musics_ptr[stage].play();
            #else
                stage = 1;
            #endif
        }
    );

    btn_singleplayer.set_position(sf::Vector2f(window_size.width / 2 - 250.0f, window_size.height / 3 - 75.0f));
    btn_singleplayer.set_bg_color(sf::Color(0xDF, 0, 0));
    btn_singleplayer.set_hovered_bg_color(sf::Color::Red);
    m_buttons.push_back(btn_singleplayer);

    Button btn_multiplayer(sf::Text("Multiplayer", font, 45), sf::RectangleShape(sf::Vector2f(500.0f, 100.0f)),
        [](sf::Music* musics, unsigned int& stage) { stage = 2; }
    );

    btn_multiplayer.set_position(sf::Vector2f(window_size.width / 2 - 250.0f, window_size.height / 3 + 75.0f));
    btn_multiplayer.set_bg_color(sf::Color(0xDF, 0, 0));
    btn_multiplayer.set_hovered_bg_color(sf::Color::Red);
    m_buttons.push_back(btn_multiplayer);

    Button btn_settings(sf::Text("Settings", font, 45), sf::RectangleShape(sf::Vector2f(500.0f, 100.0f)),
        [](sf::Music* musics, unsigned int& stage) { stage = 3; }
    );

    btn_settings.set_position(sf::Vector2f(window_size.width / 2 - 250.0f, window_size.height / 3 + 225.0f));
    btn_settings.set_bg_color(sf::Color(0xDF, 0, 0));
    btn_settings.set_hovered_bg_color(sf::Color::Red);
    m_buttons.push_back(btn_settings);
}


void Spaceship::MainMenu::poll_events(sf::RenderWindow& window, sf::Music* musics_ptr, uint32_t& game_stage) {
    for (sf::Event e; window.pollEvent(e);) {
        switch (e.type)
        {
            case sf::Event::Closed: window.close(); return;
            case sf::Event::Resized: window.setView(sf::View(sf::FloatRect(.0f, .0f, e.size.width, e.size.height))); break;

            case sf::Event::MouseButtonPressed:
               if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                   for (register unsigned int i = 0; i < m_buttons.size(); i++) {
                       if (m_buttons[i].is_clicked(sf::Mouse::getPosition(window))) m_buttons[i].click(musics_ptr, game_stage);
                   }
               } break;
        
            default: break;
        }
    }

    for (register uint32_t i = 0u; i < m_buttons.size(); i++) { m_buttons[i].update(window); }
}


void Spaceship::MainMenu::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(m_bg);

    for (register uint32_t i = 0u; i < m_buttons.size(); i++) { window.draw(m_buttons[i]); }
}
