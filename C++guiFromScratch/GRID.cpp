#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main(){

    //create window 
    sf::RenderWindow window(sf::VideoMode({800,600}),"Title");

    // top-left
    sf::RectangleShape topLeft({200.f,100.f});

    // top-right
    sf::RectangleShape topRight({200.f,100.f});
    topRight.setOrigin({200.f,0.f});
    
    // bottom-left
    sf::RectangleShape bottomLeft({200.f,100.f});
    bottomLeft.setOrigin({0.f,100.f});

    // bottom-right
    sf::RectangleShape bottomRight({200.f,100.f});
    bottomRight.setOrigin({200.f,100.f});
   
    // top
    sf::RectangleShape top({200.f,100.f});
    top.setOrigin({100.f,0.f});

    // bottom
    sf::RectangleShape bottom({200.f,100.f});
    bottom.setOrigin({100.f,100.f});
    
    // left
    sf::RectangleShape left({200.f,100.f});
    left.setOrigin({0.f,50.f});

    // right 
    sf::RectangleShape right({200.f,100.f});
    right.setOrigin({200.f, 50.f});

    // middle
    sf::RectangleShape middle({200.f,100.f});
    middle.setOrigin({100.f,50.f});
    
    //inf.loop window while window still open
    while(window.isOpen())
    {
        //handle events
        while(std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        
            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // update view
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
            
        }

        // set position
        float window_w = static_cast<float>(window.getSize().x);
        float window_h = static_cast<float>(window.getSize().y);
        topRight    .setPosition     ({window_w      ,   0.f});
        bottomLeft  .setPosition     ({0.f           ,   window_h});
        bottomRight .setPosition     ({window_w      ,   window_h});
        top         .setPosition     ({window_w/2    ,   0.f});
        bottom      .setPosition     ({window_w/2    ,   window_h});
        left        .setPosition     ({0.f           ,   window_h/2});
        right       .setPosition     ({window_w      ,   window_h/2});
        middle      .setPosition     ({window_w/2    ,   window_h/2});

        // fill window with color
        window.clear(sf::Color(127,127,127));

        // draw
        window.draw(bottomLeft);
        window.draw(bottomRight);
        window.draw(topLeft);
        window.draw(topRight);
        window.draw(top);
        window.draw(bottom);
        window.draw(left);
        window.draw(right);
        window.draw(middle);


        //display
        window.display();
    }

    return 0;
}