#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

float TittleGameSize = 100;
string Fontloc = "C:/Windows/Fonts/arial.ttf";
float windowSize_x = 1600;
float WindowSize_y = 900;
sf::Font font(Fontloc); //import font_style variable (pull form location)  

class buttonBuild{
    public:
        float posBox_x;
        float posBox_y;
        float FontSize;
        float buttonSize_x;
        float buttonSize_y;
        float shiftX;
        float shiftY;
        string name;
        sf::RectangleShape builtButton(); 
        sf::Text txtBox();
};

class Title{
    string Title_string = "Game24";
    public:
        sf::Text TitleName();
};


sf::Text Title::TitleName(){
    sf::Text Title_24(font,Title_string,TittleGameSize);
    Title_24.setPosition({windowSize_x/2-TittleGameSize-50,50});
    return Title_24;
};



sf::RectangleShape buttonBuild::builtButton(){
    sf::RectangleShape button({buttonSize_x,buttonSize_y}); //Create button variable with size
    button.setPosition({posBox_x,posBox_y}); 
    button.setFillColor(sf::Color::Blue);
    return button;
};

sf:: Text buttonBuild::txtBox(){
    sf::Text Text(font,name,FontSize);
    Text.setPosition({posBox_x+(buttonSize_x/2)+shiftX,posBox_y+(buttonSize_y/2)+shiftY});
    return Text;
}


