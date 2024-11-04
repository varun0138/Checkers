#include "Board.hpp"
#include "Constants.hpp"

Board::Board() {
    createBoard();
}

void Board::move(std::shared_ptr<Piece> piece, unsigned int row, unsigned col) {
    m_board[row][col] = std::make_shared<Piece>(row, col, piece->getColor());

    if(row == 0 || row == ROWS - 1) {
        if(piece->getColor() == WHITE) {
            whiteKings++;
        }
        else { // piece->getColor() == RED
            redKings++;
        }
        m_board[row][col]->makeKing();
    }

    m_board[piece->getRow()][piece->getCol()] = nullptr;
}

std::shared_ptr<Piece> Board::getPiece(unsigned int row, unsigned int col) const {
    return m_board[row][col];
}

void Board::createBoard() {
    m_board = std::vector<std::vector<std::shared_ptr<Piece>>>(ROWS, std::vector<std::shared_ptr<Piece>>(COLS, nullptr));

    for(unsigned int row = 0; row < ROWS; row++) {
        for(unsigned int col = 0; col < COLS; col++) {
            if(col % 2 == (row + 1) % 2) {
                if(row < 3) {
                    m_board[row][col] = std::make_shared<Piece>(row, col, WHITE);
                }
                else if(row > 4) {
                    m_board[row][col] = std::make_shared<Piece>(row, col, RED);
                }
            }
        }
    }
}

void Board::draw(sf::RenderTarget& target) {
    for(unsigned int y = 0; y < ROWS; y++) {
        for(unsigned int x = y % 2; x < COLS; x += 2) {
            m_tile.setSize(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            m_tile.setPosition(sf::Vector2f(x * SQUARE_SIZE, y * SQUARE_SIZE));
            m_tile.setFillColor(sf::Color::Red);

            target.draw(m_tile);
        }
    }

    for(unsigned int row = 0; row < ROWS; row++) {
        for(unsigned int col = 0; col < COLS; col++) {
            if(m_board[row][col]) {
                m_board[row][col]->draw(target);
            }
        }
    }
}