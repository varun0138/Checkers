#include "Piece.hpp"
#include "Constants.hpp"

Piece::Piece(unsigned int row, unsigned int col, const sf::Color& color)
    :m_row(row), m_col(col), m_color(color) {

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

void Piece::draw(sf::RenderTarget& target) {
    m_piece.setPosition(m_pos);
    m_piece.setOrigin(sf::Vector2f(PIECE_RADIUS, PIECE_RADIUS));
    m_piece.setRadius(PIECE_RADIUS);
    m_piece.setOutlineThickness(OUTLINE_THICKNESS);
    m_piece.setFillColor(m_color);
    m_piece.setOutlineColor(GREY);

    target.draw(m_piece);

    if(m_king) { target.draw(m_crown); }
}