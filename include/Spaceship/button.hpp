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

namespace Spaceship
{
    class Button : public sf::Drawable {
        sf::Text m_text;
        sf::RectangleShape m_shape;
        sf::Color m_color, m_color_hovered;
        void(*m_on_click)(sf::Music*, unsigned int&);
    public:

        Button() = delete;
        Button(const sf::Text&, const sf::RectangleShape&, void(*on_click)(sf::Music*, unsigned int&));

        void set_position(const sf::Vector2f&);
        void set_bg_color(const sf::Color&);
        void set_hovered_bg_color(const sf::Color&);
        void click(sf::Music*, unsigned int&);
        void update(const sf::RenderWindow& window);

        bool is_clicked(const sf::Vector2i&) const;

        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    };

} // namespace Spaceship