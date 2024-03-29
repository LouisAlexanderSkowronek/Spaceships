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

#include "Spaceship/loader.hpp"

#include <string>
#include <fstream>
#include <iostream>

sf::Font Spaceship::load_font(const char* filepath) {
    sf::Font font;
    font.loadFromFile(filepath);
    return font;
}


std::vector<sf::Texture> Spaceship::load_textures(const char* filepath) {

    std::vector<sf::Texture> loaded_textures;
    
    std::ifstream file_texture_paths(filepath);

    if (!file_texture_paths.is_open()) { std::cerr << "Couldn't open file: " << filepath << std::endl; return loaded_textures; }

    std::string filename;
    while (std::getline(file_texture_paths, filename)) {
        sf::Texture texture;
        texture.loadFromFile(filename);
        loaded_textures.push_back(texture);
    }

    file_texture_paths.close();

    return loaded_textures;
}


sf::Music* Spaceship::load_musics(const char* filepath) {
    
    // Vector with the paths where the musics will be located
    std::vector<std::string> filenames;

    // Buffer for the use of the std::getline function. The buffer will be pushed back into the std::vector of the filenames
    std::string filename;

    // Loading the in the filename located paths of the musics into the std::vector filepaths
    std::ifstream musics_file(filepath);
    while (std::getline(musics_file, filename)) filenames.push_back(filename);
    musics_file.close();

    // Allocate pointer to the musics, ...
    sf::Music* musics = new sf::Music[filenames.size()];

    // ... and load them from the files containing the musics located at the filepaths
    for (register unsigned int i = 0; i < filenames.size(); i++) {
        if (!musics[i].openFromFile(filenames[i])) {
            std::cerr << "Couldn't load music at filepath: " << filenames[i] << std::endl;
        }

        musics[i].setLoop(true);
    }

    return musics;
}


void Spaceship::set_window_icon(sf::RenderWindow& window, const char* icon_path) {
    sf::Image icon;
    icon.loadFromFile(icon_path);

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
