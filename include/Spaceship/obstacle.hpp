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

namespace Spaceship
{
    class Obstacle
    {
        static const sf::Texture* texture_ptr;
        static float secs_until_spawn;

        sf::Vector2f m_vel;
        sf::Sprite m_sprite;        

    public:

        static void init(const sf::Texture&);

        static void update(const float&, std::vector<Obstacle>&);

        static void spawn(std::vector<Obstacle>&);

        Obstacle(const sf::Vector2f&, const sf::Vector2f&);

        inline const sf::Vector2f& get_velocity() const { return m_vel; }

        inline bool is_colliding(const sf::RectangleShape& other) const { return m_sprite.getGlobalBounds().intersects(other.getGlobalBounds()); }
        inline bool is_colliding(const sf::Sprite& other)         const { return m_sprite.getGlobalBounds().intersects(other.getGlobalBounds()); }

        inline const sf::Vector2f& get_position() const { return m_sprite.getPosition(); }

        void draw(sf::RenderWindow&) const;
    };
    
} // namespace Spaceship