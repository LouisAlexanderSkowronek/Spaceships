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

#include "Spaceship/button.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


Spaceship::Button::Button(const sf::Text& text, const sf::RectangleShape& shape, void(*on_click)(sf::Music*, unsigned&)) :
    m_text(text), m_shape(shape) { m_on_click = on_click; }


void Spaceship::Button::set_position(const sf::Vector2f& new_position) {
    m_shape.setPosition(new_position);
    
    const float new_x_txt = new_position.x + m_shape.getSize().x / 2 - m_text.getLocalBounds().width  / 2;
    const float new_y_txt = new_position.y + m_shape.getSize().y / 2 - m_text.getLocalBounds().height / 2;
    m_text.setPosition(sf::Vector2f(new_x_txt, new_y_txt));
}

void Spaceship::Button::set_bg_color(const sf::Color& color) {
    m_color = color;
}

void Spaceship::Button::set_hovered_bg_color(const sf::Color& color) {
    this->m_color_hovered = color;
}

void Spaceship::Button::click(sf::Music* music_ptrs, unsigned int& stage) {
    m_on_click(music_ptrs, stage);
}

bool Spaceship::Button::is_clicked(const sf::Vector2i& mouse_position) const {
    return 
        mouse_position.x >= this->m_shape.getPosition().x &&
        mouse_position.x <= this->m_shape.getPosition().x + this->m_shape.getLocalBounds().width &&
        mouse_position.y >= this->m_shape.getPosition().y &&
        mouse_position.y <= this->m_shape.getPosition().y + this->m_shape.getLocalBounds().height;
}

void Spaceship::Button::update(const sf::RenderWindow& window) {
    if (this->is_clicked(sf::Mouse::getPosition(window))) m_shape.setFillColor(m_color_hovered);
    else                                                  m_shape.setFillColor(m_color);    
}

void Spaceship::Button::draw(sf::RenderTarget& window, sf::RenderStates states) const {    
    window.draw(m_shape);
    window.draw(m_text);
}