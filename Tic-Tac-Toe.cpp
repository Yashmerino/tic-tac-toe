#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(630, 830), "Tic-Tac-Toe", Style::Close | Style::Titlebar); //Creatting the window

class TicTacToe {
private:
    Sprite grid[9]; //Creatting the grid
    Sprite gameGrid;
    Texture gridTex;
    Texture X;
    Texture O;
    Texture Nothing;
    char turn = 'X';
public:
    TicTacToe() { //Constructor
        Nothing.loadFromFile("Textures/Nothing.png");
        X.loadFromFile("Textures/X.png");
        O.loadFromFile("Textures/O.png");
        gridTex.loadFromFile("Textures/Grid.png");
        gameGrid.setTexture(gridTex);
        gameGrid.setOrigin(Vector2f(gameGrid.getLocalBounds().width / 2, gameGrid.getLocalBounds().height / 2));
        gameGrid.setPosition(315, 415);

        for (int i = 0; i < 9; i++) {
            grid[i].setOrigin(grid[i].getLocalBounds().width / 2, grid[i].getLocalBounds().height / 2);
            grid[i].setTexture(Nothing);
            grid[i].setScale(1, 1);
        }

        grid[0].setPosition(5, 105); grid[5].setPosition(425, 315);
        grid[1].setPosition(215, 105); grid[6].setPosition(5, 525);
        grid[2].setPosition(425, 105); grid[7].setPosition(215, 525); 
        grid[3].setPosition(5, 315); grid[8].setPosition(425, 525);
        grid[4].setPosition(215, 315);
    }

    bool CheckClick(Sprite& sprite, RenderWindow& window) { //Checks if the sprite is clicked
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::FloatRect bounds = sprite.getGlobalBounds();

        if (bounds.contains(mousePos)) {
            return true;
        }
        else {
            return false;
        }
    }

    void SetCellTexture(Sprite& sprite, char& turn) { //Sets the texture for the chosen sprite
        if (sprite.getTexture() == &Nothing) {
            if (turn == 'X') {
                turn = 'O';
                sprite.setTexture(X);
            }
            else {
                turn = 'X';
                sprite.setTexture(O);
            }
        }
    }

    void SelectCell() {
        if (CheckClick(grid[0], window)) {
            SetCellTexture(grid[0], turn);
        }
        else if (CheckClick(grid[1], window)) {
            SetCellTexture(grid[1], turn);
        }
        else if (CheckClick(grid[2], window)) {
            SetCellTexture(grid[2], turn);
        }
        else if (CheckClick(grid[3], window)) {
            SetCellTexture(grid[3], turn);
        }
        else if (CheckClick(grid[4], window)) {
            SetCellTexture(grid[4], turn);
        }
        else if (CheckClick(grid[5], window)) {
            SetCellTexture(grid[5], turn);
        }
        else if (CheckClick(grid[6], window)) {
            SetCellTexture(grid[6], turn);
        }
        else if (CheckClick(grid[7], window)) {
            SetCellTexture(grid[7], turn);
        }
        else if (CheckClick(grid[8], window)) {
            SetCellTexture(grid[8], turn);
        }
    }

    void Run() { //Runs the game
        bool active = true;

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == Mouse::Left) {
                        SelectCell();
                    } 
                    break;
                }
            }

            window.clear(Color::Cyan); //Displaying everything
            for (int i = 0; i < 9; i++)
                window.draw(grid[i]);
            window.draw(gameGrid);
            window.display();
        }
    }
};

int main()
{
    TicTacToe Game;
    Game.Run();

    return 0;
}
