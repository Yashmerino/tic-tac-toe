#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1024, 768), "Tic-Tac-Toe", Style::Close | Style::Titlebar);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed: {
                window.close();
            }

            }

        }
    }

    window.clear();
    //window.draw();
    window.display();
    return 0;
}