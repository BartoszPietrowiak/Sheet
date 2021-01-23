#include <iostream>
#include <cstdlib>

#include "Cell.h"

using namespace std;
//construct the cell object with empty content
Cell::Cell()
{
    content = " ";
}
//return cell content
string Cell::print()
{
    return content;
}
//check if cell content is empty, if it is add content but when it isn't ask user to want change the content of cell
void Cell::addContent(string content)
{
    if(this->content==" ")
    {
        this->content=content;
    }
    else
    {
        char op;
        bool work=true;
        cout<<"Ta komorka zawiera juz zawartosc. Czy na pewno chcesz ja zmienic? T/N"<<endl;
        while(work)
        {
            cin>>op;
            switch(op)
            {
                case 'T':
                {
                    this->content=content;
                    work=false;
                    break;
                }
                case 'N':
                {
                    work=false;
                    break;
                }
                default:
                {
                    cout<<"Wpisz T lub N odpowiadajac na pytanie"<<endl;
                    break;
                }
            }
        }
    }   
}
//delete the cell content
void Cell::deleteContent()
{
    content=" ";
}