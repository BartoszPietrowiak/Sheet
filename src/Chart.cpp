#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Chart.h"
#include <algorithm>
#include <SFML/Graphics.hpp>
//construct the chart object with x and y axis values
Chart::Chart(vector<float> rangex, vector<float> rangey)
{
    this->rangex = rangex;
    this->rangey = rangey;
    axis_x="";
    axis_y="";
    title="";
}
//return chart title
string Chart::printtitle()
{
    return title;
}
//add title to chart
void Chart::addtitle()
{
    cout<<"Podaj tytul wykresu"<<endl;
    cin.ignore();
    getline(cin,title);
}
//add name of axis x
void Chart::name_axisx()
{
    cout<<"Podaj tytul osi x"<<endl;
    cin.ignore();
    getline(cin,axis_x);
}
//add name of axis y
void Chart::name_axisy()
{
    cout<<"Podaj tytul osi y"<<endl;
    cin.ignore();
    getline(cin,axis_y);
}
void Chart::addtitle(string name)
{
    title=name;
}
//add name of axis x
void Chart::name_axisx(string name)
{
    axis_x=name;
}
//add name of axis y
void Chart::name_axisy(string name)
{
    axis_y=name;
}
string Chart::print_axis_x()
{
    return axis_x;
}
string Chart::print_axis_y()
{
    return axis_y;
}
vector<float> Chart::print_rangex()
{
    return rangex;
}
vector<float> Chart::print_rangey()
{
    return rangey;
}

//draw a Chart
void Chart::draw()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), title); //making chart window
    sf::Font font;
    font.loadFromFile("src/Fonts/font.ttf"); //load font from file
    sf::Font font2;
    font2.loadFromFile("src/Fonts/font2.ttf");//load font from file
    sf::Text text1(axis_y, font); //make axis_y title drawing
    text1.setCharacterSize(20);
    text1.setStyle(sf::Text::Bold);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(sf::Vector2f(15,300+(axis_y.size()*5)));
    text1.setRotation(text1.getRotation()+ 270.0);
    sf::Text text2(axis_x, font);//make axis_x title drawing
    text2.setCharacterSize(20);
    text2.setStyle(sf::Text::Bold);
    text2.setFillColor(sf::Color::Red);
    text2.setPosition(sf::Vector2f(400-(axis_x.size()*6),560));
    sf::Text text3(title, font);//make  title drawing
    text3.setCharacterSize(30);
    text3.setStyle(sf::Text::Bold);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(sf::Vector2f(400-title.size()*7,10));
    sf::VertexArray lines(sf::LineStrip, 3);//make axis x and y drawing
    lines[0].position = sf::Vector2f(50,50);
    lines[1].position = sf::Vector2f(50, 550);
    lines[2].position = sf::Vector2f(750, 550);
    sf::VertexArray lines2(sf::LineStrip, 3); //make axis x arrow draw
    lines2[0].position = sf::Vector2f(47,65);
    lines2[1].position = sf::Vector2f(50, 50);
    lines2[2].position = sf::Vector2f(53, 65);
    sf::VertexArray lines3(sf::LineStrip, 3);//make axis y arrow draw
    lines3[0].position = sf::Vector2f(735,547);
    lines3[1].position = sf::Vector2f(750, 550);
    lines3[2].position = sf::Vector2f(735, 553);
    float max_x,max_y;
    max_x = *max_element(rangex.begin(),rangex.end()); //find max of axis x numbers
    max_y = *max_element(rangey.begin(),rangey.end());//find max of axis y numbers
    float podzialkax=685/ max_x;
    float podzialkay=485/ max_y;
    sf::VertexArray lines4(sf::LineStrip, rangex.size());
    int bufor;
    for(int i=0;i<rangex.size()-1;i++)
    {
        for(int j=0;j<rangex.size()-1;j++)
        {
            if(rangex[j]>rangex[j+1])
            {
                swap(rangex[j],rangex[j+1]);
                swap(rangey[j],rangey[j+1]);
            }
        }
    }
    for(int i=0;i<rangex.size();i++)
    {
       lines4[i].position = sf::Vector2f(50+rangex[i]*podzialkax,550-rangey[i]*podzialkay); //draw a line chart
       lines4[i].color =  sf::Color::Blue;
    }
    int y,x;
    if (podzialkay<10)
    {
        y=2;
    }
    else
    {
        y=1;
    }
    if (podzialkax<10)
    {
        x=2;
    }
    else
    {
        x=1;
    }
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        sf::VertexArray lines5(sf::LineStrip, max_x/x);
        for(int i=0;i<max_y/y;i++)
        { //draw axis y points 
            sf::VertexArray lines5(sf::LineStrip, 2);
            lines5[0].position = sf::Vector2f(48,65+i*y*podzialkay);
            lines5[1].position = sf::Vector2f(52,65+i*y*podzialkay);
            sf::Text text(to_string(int(max_y)-i), font2);
            text.setCharacterSize(7);
            text.setStyle(sf::Text::Regular);
            text.setFillColor(sf::Color::White);
            text.setPosition(sf::Vector2f(40,62+i*y*podzialkay));
            window.draw(text);
            window.draw(lines5);
        }
        sf::VertexArray lines6(sf::LineStrip, max_y/y);
        for(int i=0;i<=max_x/x;i++)
        {//draw axis x points 
            sf::VertexArray lines6(sf::LineStrip, 2);
            lines6[0].position = sf::Vector2f(50+i*x*podzialkax,548);
            lines6[1].position = sf::Vector2f(50+i*x*podzialkax,552);
            sf::Text text(to_string(i), font2);
            text.setCharacterSize(7);
            text.setStyle(sf::Text::Regular);
            text.setFillColor(sf::Color::White);
            text.setPosition(sf::Vector2f(48+i*x*podzialkax,552));
            window.draw(text);
            window.draw(lines6);
        }
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(lines);
        window.draw(lines2);
        window.draw(lines3);
        window.draw(lines4);
        window.display();
    }
}