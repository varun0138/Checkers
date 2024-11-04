#pragma once

#include <SFML/Graphics/Color.hpp>

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = WINDOW_WIDTH;

const unsigned int ROWS = 8;
const unsigned int COLS = 8;

const float SQUARE_SIZE = WINDOW_WIDTH / COLS;

const float PADDING = SQUARE_SIZE * 0.15f;
const float OUTLINE_THICKNESS = SQUARE_SIZE * 0.05f;
const float PIECE_RADIUS = SQUARE_SIZE / 2.0f - PADDING;

const sf::Color WHITE = sf::Color::White;
const sf::Color BLACK = sf::Color::Black;
const sf::Color RED = sf::Color::Red;
const sf::Color BLUE = sf::Color::Blue;
const sf::Color GREY = sf::Color(128, 128, 128, 255);

const std::string CROWN_IMAGE_PATH = "./resources/images/crown.png";