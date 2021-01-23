#include <iostream>
#include <cstdlib>
//cell header file with definition of methods on variable content
using namespace std;
class Cell
{
    string content;
    public:
    Cell();
    void addContent(string content);
    void deleteContent();
    string print();
};