
#include "Game.h"
#include "Menu.h"
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Space Pepe Invaders M.Pawelec", Style::Default);

    
    sf::Texture texture;
    if (!texture.loadFromFile("Textures/background.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("Scatmans-World.wav"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
    Game game(&window);
   
        while (window.isOpen()) {
            Event event;
            
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                    window.close();
               
            }
            game.Update();
            game.Draw();
        }
        return 0;
}


