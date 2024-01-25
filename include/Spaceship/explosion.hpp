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

#include <vector>

namespace Spaceship
{
    class Explosion : public sf::Drawable {
        float m_remaining_lifetime;
        sf::Vector2f m_pos;
        static std::vector<sf::Texture> textures;

    public:

        static inline void init(const sf::Texture* texture_ptr, const uint32_t& size) {
            textures.reserve(size);
            for (register uint32_t i = 0u; i < size; i++) { textures.push_back(*(texture_ptr + i)); }
        }

        Explosion(const sf::Vector2f& position=sf::Vector2f(), const float& lifetime=1.0f);

        bool update(const float&);

        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    };

} // namespace Spaceship