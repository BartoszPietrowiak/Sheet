#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
//Chart header file with definitions of methods and variables used in Chart object
class Chart
{
    vector<float> rangex;
    vector<float> rangey;
    string axis_y;
    string axis_x;
    string title;
    public:
    Chart(vector<float> rangex, vector<float> rangey);
    void addtitle();
    void name_axisy();
    void name_axisx();
    void addtitle(string name);
    void name_axisy(string name);
    void name_axisx(string name);
    void draw();
    vector<float> print_rangex();
    vector<float> print_rangey();
    string print_axis_x();
    string print_axis_y();
    string printtitle();
};