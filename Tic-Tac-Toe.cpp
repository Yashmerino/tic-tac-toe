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
public:
    TicTacToe() { //Constructor
        gridTex.loadFromFile("Textures/Grid.png");
        gameGrid.setTexture(gridTex);
        gameGrid.setOrigin(Vector2f(gameGrid.getLocalBounds().width / 2, gameGrid.getLocalBounds().height / 2));
        gameGrid.setPosition(315, 415);

        for (int i = 0; i < 9; i++) 
            grid[i].setOrigin(grid[i].getLocalBounds().width / 2, grid[i].getLocalBounds().height / 2);

        grid[0].setPosition(5, 105); grid[5].setPosition(425, 315);
        grid[1].setPosition(215, 105); grid[6].setPosition(5, 525);
        grid[2].setPosition(425, 105); grid[7].setPosition(215, 525); 
        grid[3].setPosition(5, 315); grid[8].setPosition(425, 525);
        grid[4].setPosition(215, 315);
    }

    void Run() {
        bool active = true;

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                case Event::Closed: {
                    window.close();
                }
                    //
                }
            }

            if (active) {
                
            }

            window.clear(Color::Cyan); //Displaying everything
            window.draw(gameGrid);
            for (int i = 0; i < 9; i++)
                window.draw(grid[i]);
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