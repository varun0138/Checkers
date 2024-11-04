#include <iostream>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "Board.hpp"


int main() {

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "", sf::Style::Close | sf::Style::Titlebar);

    Board board;

    while(window.isOpen()) {
        sf::Event event;
        if(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        window.clear();

        board.draw(window);

        window.display();
    }

    return 0;
}