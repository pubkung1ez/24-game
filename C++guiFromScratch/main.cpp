#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main(){

    //create window 
    sf::RenderWindow window(sf::VideoMode({800,600}),"Title");

    //create rectangle
    sf::RectangleShape rectangle({400.f,200.f});

    //color & outline 
    rectangle.setFillColor(sf::Color(255,213,186));
    rectangle.setOutlineThickness(20.f);
    rectangle.setOutlineColor(sf::Color(200, 100, 100));
    
    //set origin
    rectangle.setOrigin({200.f, 100.f});

    // transformation
    rectangle.setRotation(sf::degrees(30.f));
    rectangle.setScale({1.5f, 1.f});
    rectangle.setPosition({400.f,300.f});

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
        window.draw(rectangle);

        //display
        window.display();
    }

    return 0;
}