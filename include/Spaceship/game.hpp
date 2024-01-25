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

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <tuple>
#include <array>
#include <vector>

#include "obstacle.hpp"
#include "xwing.hpp"
#include "explosion.hpp"
#include "main_menu.hpp"

namespace Spaceship
{
    void run(const float& dt, unsigned& game_stage, XWing& communist_tank, const sf::Font& font, unsigned int& space_pressed, sf::RenderWindow& window,
    sf::Music* music_ptr, MainMenu& menu, Bg&, std::vector<sf::RectangleShape>& bullets, std::vector<Obstacle>& obstacles,
    std::vector<Explosion>& explosions);

    namespace main_game {

        void poll_events(sf::RenderWindow&, unsigned&);
        void update(const float&, XWing&, unsigned&, Bg&, std::vector<sf::RectangleShape>&, std::vector<Obstacle>&, std::vector<Explosion>&);
        void draw(sf::RenderWindow&, const Bg&, const XWing&, const std::vector<sf::RectangleShape>&, std::vector<Obstacle>&, const std::vector<Explosion>&);

    } // namespace main_game

    namespace unfinished_menu {

        void poll_events(sf::RenderWindow&, unsigned int&);
        void draw(sf::RenderWindow&, const Bg&, const sf::Font&, const char*);

    } // namespace multiplayer_menu

} // namespace TankGame