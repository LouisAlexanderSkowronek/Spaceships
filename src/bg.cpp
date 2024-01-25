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

#include "Spaceship/bg.hpp"

#include <random>

extern std::mt19937 randint;
extern sf::VideoMode window_size;

Spaceship::Bg::Bg(const sf::Texture& big_star_texture) : m_nxt_star_spawn(2.0f), m_big_star_texture(big_star_texture)
{
    sf::RenderTexture rt;
    rt.create(1, 1);
    rt.clear(sf::Color::White);
    rt.display();
    m_small_star_texture = rt.getTexture();
    
    m_nxt_star_spawn += static_cast<float>(randint() % 10) / 10;

    unsigned n = 1096u + randint() % 568u;

    stars.reserve(n);  // reserve small stars first

    for (unsigned i = 0u; i < n; i++)
    {
        stars.emplace_back(
            sf::Vector2f(randint() % window_size.width, randint() % window_size.height),
            sf::Vector2f(randint()%100 - 50.0f, randint()%100 - 50.0f),
            m_small_star_texture
        );
    }


    n = 70 + randint() % 80;

    stars.reserve(n);  // reserve big stars

    for (unsigned i = 0u; i < n; i++)
    {
        stars.emplace_back(
            sf::Vector2f(randint() % window_size.width, randint() % window_size.height),
            sf::Vector2f(randint()%100 - 50.0f, randint()%100 - 50.0f),
            m_big_star_texture
        );
    }
}

void Spaceship::Bg::update(const float& dt){


    // Clean up stars out of image

    for (unsigned i = stars.size() - 1u; i > stars.size(); i--)
    {
        const sf::Vector2f star_position = stars[i].get_position();
        if (star_position.x < .0f
            || star_position.x > window_size.width
            || star_position.y < .0f
            || star_position.y > window_size.height) { stars.erase(stars.begin() + i); }
    }


    // Update spawn timer

    m_nxt_star_spawn -= dt;


    // Spawn new stars
    if (m_nxt_star_spawn < .0f)
    {
        m_nxt_star_spawn = .2f + static_cast<float>(randint() % 5) / 10.0f;

        // Amount of new spawned stars
        unsigned q = 1u + randint() % 3;

        for (unsigned i = 0u; i < q; i++)
        {
            if (randint() % 4)
            {
                stars.emplace_back(
                    sf::Vector2f(window_size.width / 2.0f, window_size.height / 2.0f),
                    sf::Vector2f(randint()%100 - 50.0f, randint()%100 - 50.0f),
                    m_small_star_texture
                );
            }
            else
            {
                stars.emplace_back(
                    sf::Vector2f(window_size.width / 2.0f, window_size.height / 2.0f),
                    sf::Vector2f(randint()%100 - 50.0f, randint()%100 - 50.0f),
                    m_big_star_texture
                );
            }
        }
    }


    // Move stars

    for (auto& star : stars)
    {
        star.update(dt);
    }
}


// Draw stars

void Spaceship::Bg::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for (const Star& star : stars)
    {

        window.draw(star, states);
    }
}
