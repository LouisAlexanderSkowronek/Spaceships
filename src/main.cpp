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

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tuple>
#include <array>
#include <vector>
#include <random>

#include "Spaceship/main_menu.hpp"
#include "Spaceship/loader.hpp"
#include "Spaceship/game.hpp"
#include "Spaceship/xwing.hpp"
#include "Spaceship/obstacle.hpp"
#include "Spaceship/explosion.hpp"
#include "Spaceship/bg.hpp"

std::mt19937 randint(time(nullptr));
sf::VideoMode window_size(1200u, 700u);

int main()
{
    #ifdef COPYRIGHT_LIMITED
        puts("Note: Due to copyright limitations several assets are not going to be loaded. More details see in README.md file.");
    #endif

    sf::RenderWindow window(window_size, "Spaceships", sf::Style::Close);

    #ifndef COPYRIGHT_LIMITED
        Spaceship::set_window_icon(window, "../assets/icon.png");
    #endif

    sf::Clock clock;
    unsigned game_stage = 0u; // 0 = main menu, 1 = main game, 2 = Multiplayer, 3 = Settings
    unsigned space_key_status = 0u;

    const sf::Font font                     = Spaceship::load_font("../assets/fonts/FreeSans.ttf");
    const std::vector<sf::Texture> textures = Spaceship::load_textures("../assets/textures/textures.txt");
    sf::Music* musics_ptr;

    #ifndef COPYRIGHT_LIMITED
        musics_ptr = Spaceship::load_musics("../assets/music/musics.txt");
    #else
        musics_ptr = nullptr;
    #endif

    Spaceship::Bg bg(textures[6]);
    Spaceship::MainMenu menu = Spaceship::MainMenu(font, bg);

    Spaceship::Obstacle::init(textures[1]);
    Spaceship::Explosion::init(&textures[2], 3u);

    std::vector<Spaceship::Obstacle> obstacles;
    obstacles.reserve(3u);

    std::vector<sf::RectangleShape> bullets;
    bullets.reserve(8u);

    std::vector<Spaceship::Explosion> explosions;
    explosions.reserve(8u); 

    Spaceship::XWing xwing(sf::Vector2f(window_size.width / 2 - 50.0f, window_size.height / 2 - 50.0f), textures[0]);


    #ifndef COPYRIGHT_LIMITED
        musics_ptr[0].play(); // play menu music
    #endif

    while (window.isOpen()) {
        const float elapsed_time = clock.restart().asSeconds();

        Spaceship::run(elapsed_time, game_stage, xwing, font, space_key_status, window, musics_ptr, menu, bg, bullets, obstacles, explosions);
    }

    // Clean up
    delete[] musics_ptr;
}