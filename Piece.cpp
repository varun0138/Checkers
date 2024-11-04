#include "Piece.hpp"
#include "Constants.hpp"

Piece::Piece(unsigned int row, unsigned int col, const sf::Color& color)
    :m_row(row), m_col(col), m_color(color) {

    m_crownTexture.loadFromFile(CROWN_IMAGE_PATH);
    m_crown.setTexture(m_crownTexture);
    m_crown.setScale(sf::Vector2f(0.09f, 0.09f));
    m_crown.setOrigin(m_crownTexture.getSize().x / 2.0f, m_crownTexture.getSize().y / 2.0f);
    
    m_direction = (color == WHITE) ? 1: -1;

    calulatePosititon();
}

void Piece::calulatePosititon() {
    m_pos.x = SQUARE_SIZE * m_col + SQUARE_SIZE / 2;
    m_pos.y = SQUARE_SIZE * m_row + SQUARE_SIZE / 2;
}

void Piece::makeKing() {
    m_king = true;
}

unsigned int Piece::getRow() const {
    return m_row;
}

unsigned int Piece::getCol() const {
    return m_col;
}

const sf::Color& Piece::getColor() const {
    return m_color;
}

void Piece::draw(sf::RenderTarget& target) {
    m_piece.setPosition(m_pos);
    m_piece.setOrigin(sf::Vector2f(PIECE_RADIUS, PIECE_RADIUS));
    m_piece.setRadius(PIECE_RADIUS);
    m_piece.setOutlineThickness(OUTLINE_THICKNESS);
    m_piece.setFillColor(m_color);
    m_piece.setOutlineColor(GREY);

    target.draw(m_piece);

    if(m_king) { 
        m_crown.setPosition(m_pos);
        target.draw(m_crown); 
    }
}