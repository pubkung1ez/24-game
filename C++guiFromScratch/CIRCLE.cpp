#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main(){

    //create window 
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800,600}),"Title", sf::State::Windowed, settings);

    //create circle 
    sf::CircleShape circle(200.f, 60);
    circle.setFillColor(sf::Color(128, 213, 255));
    circle.setOutlineColor(sf::Color(0, 170, 255));
    circle.setOutlineThickness(20.f);
    circle.setOrigin({200.f, 200.f});
    circle.setPosition({400.f, 300.f});
    //circle.setScale({1.5f, 1.f});
    //circle.setRotation(sf::degrees(30.f));

    //inf.loop window while window still open
    while(window.isOpen())
    {
        //handle events
        while(std::optional event = window.pollEvent())
        {
            // when close button is clicked
            if(event -> is <sf::Event::Closed>())
            {
                // close window 
                window.close();
            }
            // when window is resized
            else if (event-> is <sf::Event::Resized>())
            {
                cout << "Window " << window.getSize().x << ", " << window.getSize().y << endl;
                cout << "View " << window.getView().getSize().x << ", " << window.getView().getSize().y << endl;

                // update view
                //sf::View view(sf::FloatRect({0.f,0.f}, sf::Vector2f(window.getSize())));
                //sf::View view({400.f,300.f}, sf::Vector2f(window.getSize()));
                //window.setView(view);
            }
        }

        // fill window with color
        window.clear(sf::Color(127,127,127));

        // draw
        window.draw(circle);

        //display
        window.display();
    }

    return 0;
}