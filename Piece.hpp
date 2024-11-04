#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class Piece {
private:
    sf::CircleShape m_piece;

    sf::Texture m_crownTexture;
    sf::Sprite m_crown;

    unsigned int m_row;
    unsigned int m_col;
    sf::Color m_color;
    int m_direction;
    sf::Vector2f m_pos;

    bool m_king = false;

public:
    Piece(unsigned int row, unsigned int col, const sf::Color& color);

    void calulatePosititon();
    void makeKing();

    void draw(sf::RenderTarget& target);
};