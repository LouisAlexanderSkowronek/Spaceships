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

#include <random>

#include <iostream>

#include "button.hpp"
#include "bg.hpp"

namespace Spaceship
{

    class MainMenu : public sf::Drawable
    {
        Bg m_bg;
        std::vector<Button> m_buttons;

    public:

        MainMenu(const sf::Font& font, Bg&);

        void poll_events(sf::RenderWindow& window, sf::Music* musics_ptr, uint32_t& game_stage);

        inline void update(const float& dt) { m_bg.update(dt); }

        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    };

} // namespace Spaceship
