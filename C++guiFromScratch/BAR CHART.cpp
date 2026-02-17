#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){

    //data
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1, 2, 3, 5, 7, 7};
    int data_n = sizeof(data) / sizeof(data[0]);
    int data_max = *std::max_element(data, data + data_n);

    //create window 
    sf::RenderWindow window(sf::VideoMode({800,600}),"Title");

    //bar
    sf::RectangleShape bar;
    bar.setFillColor(sf::Color(0, 170, 255));



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
                // fix position
                sf::View view(sf::FloatRect({0.f,0.f}, sf::Vector2f(window.getSize())));
                //not fix
                //sf::View view({400.f,300.f}, sf::Vector2f(window.getSize()));
                window.setView(view);
            }
        }

        // size of window
        float window_w = static_cast<float>(window.getSize().x);
        float window_h = static_cast<float>(window.getSize().y);

        //parameter
        float space = window_w / data_n;
        float size = 0.6f * space;
        float scale = 0.9f * window_h / data_max;
        

        // fill window with color
        window.clear(sf::Color(127,127,127));

        // draw
        bar.setOrigin({size/2, 0.f});
        bar.setScale({1.f, -1.f}); // flip around Origin
        for (int i = 0; i < data_n; i++)
        {
            bar.setSize({size, data[i]*scale});
            bar.setPosition({(i + 0.5f) * space, window_h});
            window.draw(bar);
        }
        

        //display
        window.display();
    }

    return 0;
}