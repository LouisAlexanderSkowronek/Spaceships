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

#include "Spaceship/explosion.hpp"

#include <cmath>

std::vector<sf::Texture> Spaceship::Explosion::textures;

Spaceship::Explosion::Explosion(const sf::Vector2f& position, const float& lifetime) : m_remaining_lifetime(lifetime), m_pos(position) {}

bool Spaceship::Explosion::update(const float& delta) {
    m_remaining_lifetime -= delta;

    return m_remaining_lifetime <= .0f;
}

void Spaceship::Explosion::draw(sf::RenderTarget& window, sf::RenderStates render_states) const {

    const uint32_t texture_idx = (m_remaining_lifetime < .3f) ? 2u : ((m_remaining_lifetime < .6f) ? 1u : 0u);

    if (texture_idx > textures.size() - 1) return;

    sf::Sprite sprite(textures[texture_idx]);
    sprite.setOrigin(textures[texture_idx].getSize().x / 2u, textures[texture_idx].getSize().y / 2u);
    sprite.setPosition(m_pos);
    window.draw(sprite);
}