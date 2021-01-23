#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cctype>
#include "Cell.h"
#include"Chart.h"
using namespace std;
//define the Sheet header file with definitions of methods, variables and friendy functions used in class
class Sheet
{
    int width,length;
    string name;
    vector<vector<Cell>> cells;
    vector<Chart> charts;
    int line(string point);
    int col(string point);
    public:
    Sheet(string n, int wid , int len);
    ~Sheet();
    void addcontent();
    void deletecontent();
    void arithmetic();
    void min_max();
    void coordinates();
    void printsheet();
    void addcolumn_line();
    void deletecolumn_line();
    void savetoFile();
    void loadfromFile(string name1);
    void createChart();
    void printChart();
    void deleteChart();
    void editChart(int mode);
    friend string Cell::print();
    friend void Cell::addContent(string content);
    friend void Cell::deleteContent();
    friend void Chart::draw();
    friend void Chart::addtitle(); 
    friend void Chart::name_axisy(); 
    friend void Chart::name_axisx(); 
    friend void Chart::addtitle();
    friend string Chart::printtitle();   
};