#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(630, 830), "Tic-Tac-Toe", Style::Close | Style::Titlebar); //Creates the window

class TicTacToe {
private:
    Sprite grid[9]; //Creates the grid
    Sprite gameGrid;
    Texture gridTex;
    Texture X;
    Texture O;
    Texture nothing;
    Texture button;
    Text win;
    Text play;
    Text quit;
    Font font;
    Sprite playSprite;
    Sprite quitSprite;
    char turn = 'X';
    bool active = false;
public:
    TicTacToe() { //Constructor
        button.loadFromFile("Textures/button.png");
        playSprite.setTexture(button);
        playSprite.setOrigin(Vector2f(playSprite.getLocalBounds().width / 2, playSprite.getLocalBounds().height / 2));
        playSprite.setPosition(166, 780);
        quitSprite.setTexture(button);
        quitSprite.setOrigin(Vector2f(quitSprite.getLocalBounds().width / 2, quitSprite.getLocalBounds().height / 2));
        quitSprite.setPosition(466, 780);
        font.loadFromFile("Fonts/myriad.OTF");
        win.setFont(font);
        win.setCharacterSize(55);
        win.setFillColor(Color::Black);  
        play.setFont(font);
        play.setCharacterSize(40);
        play.setFillColor(Color::Black);
        play.setString("Play");
        play.setOrigin(Vector2f(play.getLocalBounds().width / 2, play.getLocalBounds().height / 2));
        play.setPosition(165, 770);
        quit.setFont(font);
        quit.setCharacterSize(40);
        quit.setFillColor(Color::Black);
        quit.setString("Quit");
        quit.setOrigin(Vector2f(quit.getLocalBounds().width / 2, quit.getLocalBounds().height / 2));
        quit.setPosition(465, 768);
        nothing.loadFromFile("Textures/Nothing.png");
        X.loadFromFile("Textures/X.png");
        O.loadFromFile("Textures/O.png");
        gridTex.loadFromFile("Textures/Grid.png");
        gameGrid.setTexture(gridTex);
        gameGrid.setOrigin(Vector2f(gameGrid.getLocalBounds().width / 2, gameGrid.getLocalBounds().height / 2));
        gameGrid.setPosition(315, 415);
        TicTacToeText();

        for (int i = 0; i < 9; i++) {
            grid[i].setOrigin(grid[i].getLocalBounds().width / 2, grid[i].getLocalBounds().height / 2);
            grid[i].setTexture(nothing);
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

    void TicTacToeText() {
        win.setString("Tic Tac Toe");
        win.setPosition(315, 35);
        win.setOrigin(Vector2f(win.getLocalBounds().width / 2, win.getLocalBounds().height / 2));
    }

    void SetCellTexture(Sprite& sprite, char& turn) { //Sets the texture for the chosen sprite
        if (sprite.getTexture() == &nothing) {
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

    void ClearGrid() { //Clears sprites' textures
        for (int i = 0; i < 9; i++) {
            grid[i].setTexture(nothing);
        }
    };

    void XWin() { //Text for X won
        win.setString("X player won");
        win.setPosition(315, 35);
        win.setOrigin(Vector2f(win.getLocalBounds().width / 2, win.getLocalBounds().height / 2));
    }

    void OWin() { //Text for O win
        win.setString("O player won");
        win.setPosition(315, 35);
        win.setOrigin(Vector2f(win.getLocalBounds().width / 2, win.getLocalBounds().height / 2));
    }

    void CheckWin(char player) { //Checks if someone won
        Texture* t;
        if (player == 'X')
            t = &X;
        else
            t = &O;

        if ((grid[0].getTexture() == t) && (grid[1].getTexture() == t) && (grid[2].getTexture() == t)) {
            active = false;
            if (player == 'X')
                XWin();
            else
                OWin();
        }
        if ((grid[3].getTexture() == t) && (grid[4].getTexture() == t) && (grid[5].getTexture() == t)) {
            active = false;
            if (player == 'X')
                XWin();
            else
                OWin();
        }
        if ((grid[6].getTexture() == t) && (grid[7].getTexture() == t) && (grid[8].getTexture() == t)) {
            active = false;
            if (player == 'X')
                XWin();
            else
                OWin();
        }
        if ((grid[0].getTexture() == t) && (grid[3].getTexture() == t) && (grid[6].getTexture() == t)) {
            active = false;
            if (player == 'X')
                XWin();
            else
                OWin();
        }
        if ((grid[1].getTexture() == t) && (grid[4].getTexture() == t) && (grid[7].getTexture() == t)) {
            active = false;
            if (player == 'X')
                XWin();
            else
                OWin();
        }
        if ((grid[2].getTexture() == t) && (grid[5].getTexture() == t) && (grid[8].getTexture() == t)) {
            active = false;
            if (player == 'X')
                XWin();
            else
                OWin();
        }
        if ((grid[0].getTexture() == t) && (grid[4].getTexture() == t) && (grid[8].getTexture() == t)) {
            active = false;
            if (player == 'X')
                XWin();
            else
                OWin();
        }
        if ((grid[2].getTexture() == t) && (grid[4].getTexture() == t) && (grid[6].getTexture() == t)) {
            active = false;
            if (player == 'X')
                XWin();
            else
                OWin();
        }
    }

    void SelectCell() { //Selects the cell
        if (CheckClick(grid[0], window)) {
            SetCellTexture(grid[0], turn);
            CheckWin('X'); CheckWin('O');
        }
        else if (CheckClick(grid[1], window)) {
            SetCellTexture(grid[1], turn);
            CheckWin('X'); CheckWin('O');
        }
        else if (CheckClick(grid[2], window)) {
            SetCellTexture(grid[2], turn);
            CheckWin('X'); CheckWin('O');
        }
        else if (CheckClick(grid[3], window)) {
            SetCellTexture(grid[3], turn);
            CheckWin('X'); CheckWin('O');
        }
        else if (CheckClick(grid[4], window)) {
            SetCellTexture(grid[4], turn);
            CheckWin('X'); CheckWin('O');
        }
        else if (CheckClick(grid[5], window)) {
            SetCellTexture(grid[5], turn);
            CheckWin('X'); CheckWin('O');
        }
        else if (CheckClick(grid[6], window)) {
            SetCellTexture(grid[6], turn);
            CheckWin('X'); CheckWin('O');
        }
        else if (CheckClick(grid[7], window)) {
            SetCellTexture(grid[7], turn);
            CheckWin('X'); CheckWin('O');
        }
        else if (CheckClick(grid[8], window)) {
            SetCellTexture(grid[8], turn);
            CheckWin('X'); CheckWin('O');
        }
    }

    void Run() { //Runs the game
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::MouseButtonPressed:
                    if (CheckClick(playSprite, window)) {
                        TicTacToeText();
                        ClearGrid();
                        active = true;
                    }
                    else if (CheckClick(quitSprite, window)) {
                        TicTacToeText();
                        ClearGrid();
                        active = false;
                        exit(0);
                    }
                    if (active) {
                        if (event.mouseButton.button == Mouse::Left) {
                            SelectCell();
                        }
                        break;
                    }
                }
            }

            window.clear(Color::Cyan); //Displays everything
            for (int i = 0; i < 9; i++)
                window.draw(grid[i]);
            window.draw(gameGrid);
            window.draw(win); 
            window.draw(playSprite);
            window.draw(quitSprite);
            window.draw(play);
            window.draw(quit);
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
