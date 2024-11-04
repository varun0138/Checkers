#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "Piece.hpp"

class Board {
private:
    sf::RectangleShape m_tile;

    std::vector<std::vector<std::shared_ptr<Piece>>> m_board;
    int selectedPiece= -1;
    unsigned int redLeft = 12;
    unsigned int whiteLeft = 12;
    unsigned int redKings = 0;
    unsigned int whiteKings = 0;

public:
    Board();

    void move(std::shared_ptr<Piece> piece, unsigned int row, unsigned col);
    
    std::shared_ptr<Piece> getPiece(unsigned int row, unsigned int col) const;

    void createBoard();
    void draw(sf::RenderTarget& target);
};