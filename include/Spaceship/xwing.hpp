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

#include <array>
#include <vector>

#include "obstacle.hpp"

namespace Spaceship {

    class XWing : public sf::Drawable {
        bool m_is_rotating_left;
        float m_drive_counter;
        sf::Vector2f m_vel;
        sf::Texture m_texture;
        sf::Sprite m_shape;
        bool m_bullet_is_left;

    public:

        XWing(const sf::Vector2f&, const sf::Texture&);
        
        void update(const float&, unsigned int&, std::vector<sf::RectangleShape>&);

        inline void add_velocity(const sf::Vector2f& vel) { m_vel += vel; }

        inline bool is_colliding(const Obstacle& obstacle) { return obstacle.is_colliding(m_shape); }

        inline const sf::Vector2f& get_position() const { return m_shape.getPosition(); }
        
        inline virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const { window.draw(m_shape, states); }

    };

} // namespace TankGame