#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include "Sheet.h"
#include "RangeException.cpp"
using namespace std;
int Sheet::line(string point) //function that from row name extract it number from cells array
{   int line;
    point.erase(0,1);
    line =stoi(point);
    return line;
}
int Sheet::col(string point)//function that from column name extract it number from cells array
{
    char column;
    column=point[0];
    int col;
    col=column%65;
    return col;
}
//implement the Sheet constructor
Sheet::Sheet(string n, int wid , int len):cells(len,vector<Cell>(wid)){
    name=n;
    width=wid;
    length=len;

}
//print sheet funcition with cells that extend with the length of content
void Sheet::printsheet()
{
    string cell;
    int first = to_string(length).length(); //we find a number of characters in max rows number
    int *wide = new int[width+1]; //we declare the wide array to keep every column width
    wide[0]=first; //first column have max width from first variable
    for (int i=0;i<width;i++) //fill the wide array with max width of column looking in every cell in each column 
    {
        wide[i+1]=0;
        for(int j=0;j<length;j++)
        {
            cell=cells[j][i].print();
            if(cell.length()>wide[i+1])
            {
                wide[i+1]=cell.length();
            }       
        }
    }
    for (int i=0;i<7;i++)//print 7 spaces 
    {
        cout<<" ";
    }
    for(char i='A';i<'A'+width;i++) //print the column signs with special spacing taking from the wide array plus 5 space characters to make it more transparent
    {
        for(int j = 0;j<wide[i%65+1]+5;j++)
        {
            if(j<((wide[i%65+1]+5)/2) || j>((wide[i%65+1]+5)/2) )
            {
                cout<<" ";
            }
            else
            {
                cout<<i;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<=this->length*2;i++) //print the row signs
    {
        string str=to_string(i/2); //convert the row number to string to see how much characters it have
        if(i%2==1){
           float l= 8-str.length(); //calculate how much spaces we have to print 
            for(int y=0;y<l;y++)
            {
                if(y<floor(l/2) || y>floor(l/2) ) 
            {
                cout<<" "; //print spaces
            }
            else if (y==floor(l/2))
            {
                cout<<i/2; //print row sign
            }
            }
        }
        else //if the row is even print 7 spaces because in this row we print the "-" characters
        {
            for(int y=0;y<7;y++) 
            {
                cout<<" ";
            }
        }
        for(int j=0;j<width;j++)  //make a looop for all columns
        {   
            if(i%2==1)
            {
                cell=cells[i/2][j].print(); //take the cell content
            }
            for(int a=0;a<wide[j+1]+5;a++) //make a loop to print "-" characters
            {            
                if(i%2!=1)
                {
                    cout<<"-"; 
                }
            }
            float len = wide[j+1]+6-cell.length(); //define the length of column included the "|" character
            for(int a=0;a<len;a++)
            {            
                if(i%2==1)
                {
                    if(a==0) //print next column character at start of column
                    {
                        cout<<"|";
                    }
                    else if( a==wide[j+1]+6-cell.length()-1 &&  j==width-1)//print next column character at end of sheet
                    {
                        cout<<"|";
                    }
                    else if (a<floor(len/2) || a>floor(len/2))//print speces in column
                    {
                        cout<<" ";
                    }
                    else if(a==floor(len/2))
                    {
                        cout<<cell;//print cell content
                    } 
                }
            }             
        }  
        cout<<endl;    //go to next row      
    }
    cout<<endl;
}
//add content to cell
void Sheet::addcontent()
{
    string position,content;
    int lin,column;
    cout<<"Podaj miejsce w ktorym wartosc ma zostac dodana"<<endl; //ask user of position of a cell to add content in this place
    cin>>position;
    cout<<"Podaj zawartosc komorki"<<endl;
    cin>>content;
    column=col(position);
    lin=line(position);
    if((lin<this->length) && (column<this->width)) //check if a sheet have cell about this coordinates
    {
       cells[lin][column].addContent(content); //addcontent
    }
    else
    {
        cout<<"Podana komorka nie znajduje sie w arkuszu!"<<endl;
    }
    
}
//delete content to cell
void Sheet::deletecontent()
{
    string position;
    int lin,column;
    cout<<"Podaj miejsce z ktorego wartosc ma byc usunieta"<<endl;//ask user of position of a cell to add content in this place
    cin>>position;
    lin=line(position);
    column=col(position);
    if((lin<this->length) && (column<this->width))//check if a sheet have cell about this coordinates
    {
       cells[lin][column].deleteContent(); //deletecontent
    }
    else
    {
        cout<<"Podana komorka nie znajduje sie w arkuszu!"<<endl;
    }
}
//add column or row to the sheet
void Sheet::addcolumn_line()
{
    string option;
    char position;
    cout<<"Podaj co ma byc dodane i po ktorym wierszu/kolumnie np.W10"<<endl; //ask user what he want to add to the sheet
    cin>>option;
    position=option[0];
    option.erase(0,1);
    switch(position)
    {
        case 'W': //add row
        {
            int line=stoi(option);
            if(line<this->length) //checking if the line after which the next one should be added exists
            {
                cells.insert(cells.begin()+line+1,vector<Cell>(width)); //add line 
                length++;
            }
            else
            {
                cout<<"Podany wiersz nie istnieje w tym arkuszu!"<<endl;
            }
            
            break;
        }
        case 'K'://add column
        {   
            char column = option[0];
            if(column%65<width)//checking if the column after which the next one should be added exists
            {
                for(int i=0;i<length;i++)//add column
                {   
                    Cell c1;
                    cells[i].insert(cells[i].begin()+(column%65)+1,c1);
                }
                width++;
            }
            else
            {
                cout<<"Podana kolumna nie istnieje w tym arkuszu!"<<endl;
            }
            break;
        }
        default:
        {
            cout<<"Bledna skladnia!"<<endl;
            break;
        }
    }
}
//delete column or row of the sheet
void Sheet::deletecolumn_line()
{
    string option;
    char position;
    cout<<"Podaj co ma byc usuniete np.W10"<<endl;//ask user what he want to delete from the sheet
    cin>>option;
    position=option[0];
    option.erase(0,1);
    switch(position)
    {
        case 'W'://delete row
        {
            int line=stoi(option);
            if(line<length)//checking if the line which we deleting exists
            {
            cells.erase(cells.begin()+line); //delete the line
            length--;
            }
            else
            {
                cout<<"Podany wiersz nie istnieje!"<<endl;
            }
            
            break;
        }
        case 'K'://delete column
        {   
            char column = option[0];
            if(column%65<width)//checking if the column which we deleting exists
            {
            for(int i=0;i<length;i++)//delete the column
            {   
                cells[i].erase(cells[i].begin()+(column%65));
            }
            width--;
            }
            else
            {
                cout<<"Podana kolumna nie istnieje!"<<endl;
            }
            break;
        }
        default:
        {
            cout<<"Bledne argumenty!"<<endl;
        }
    }

}
//look for cell which have a entered values
void Sheet::coordinates()
{
    string value;
    cout<<"Podaj wartosc ktorej szukasz w arkuszu"<<endl; //ask user to enter a value which will be looking for in sheet
    cin>>value;
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<width;j++)
        {
            if( cells[i][j].print()==value) //loooking for cell which have this content 
            {
                char start='A';
                char column=start+j;
                string column1;
                column1.insert(0,1,column);
                string line = to_string(i);
                string coords=column1+line;
                cout<<"Szukana wartosc znajduje sie w komorce "<<coords<<endl; //print the cell coordinates
            }
        }
    }
}
//loking for minimum or maximum in entered range in sheet
void Sheet::min_max()
{
    int option;
    string opt;
    cout<<"Podaj rodzaj wykonanej operacji"<<endl; //ask user what he want to look for
    cout<<"1.MAX"<<endl;
    cout<<"2.MIN"<<endl;
    cin>>opt;
    option=stoi(opt);
    string range;
    cout<<"Podaj zakres przeszukiwan Poczatek:Koniec np: A0:A5"<<endl; //ask user for range of search
    cin>>range;
    replace(range.begin(),range.end(), ':',' ');
    vector<string> array;
    stringstream ss(range);
    string temp;
    while(ss >>temp)
        array.push_back(temp);
    int cord1x=col(array[0]);
    int cord2x=col(array[1]);
    int cord1y=line(array[0]);
    int cord2y=line(array[1]);
    switch(option)
    {
        case 1:
        {   
            int max=0;
            string buf;
            int buf2;
            if(cord1x<width && cord2x<width && cord1y<length && cord2y<length) //check if the range is enteretd properly
            {
                for(int i=cord1x;i<=cord2x;i++) //look for maximum
                {
                    for(int j=cord1y;j<=cord2y;j++)
                    {
                        buf=cells[j][i].print();
                        if(buf!=" ")
                        {
                            buf2=stoi(buf);
                            if(buf2>max)
                        {
                            max=buf2;
                        }
                        }
                    }
                }
                cout<<"Maksimum wynosi "<<max<<endl<<endl; //print maximum
            }
            else
            {
                cout<<"Podany zakres jest spoza arkusza!"<<endl;
            }
            break;
        }
        case 2:
        {
            int min=0;
            string buf;
            int buf2;
            if(cord1x<width && cord2x<width && cord1y<length && cord2y<length)//check if the range is enteretd properly
            {
                for(int i=cord1x;i<=cord2x;i++) //look for minimum
                {
                    for(int j=cord1y;j<=cord2y;j++)
                    {
                        buf=cells[j][i].print();
                        if(buf!=" ")
                        {
                            buf2=stoi(buf);
                            if(buf2<min)
                        {
                            min=buf2;
                        }
                        }
                    }
                }
                cout<<"Minimum wynosi "<<min<<endl<<endl; //print minimum
            }
            else
            {
                cout<<"Podany zakres jest spoza arkusza!"<<endl;
            }
            break;
        }
        default:
        {
            cout<<"Bledny argument!"<<endl;
            break;
        }
    }
}
//make one of four arthmetic operations for entered range of sheet
void Sheet::arithmetic()
{
    int option;
    string opt;
    cout<<"Podaj rodzaj wykonanej operacji"<<endl; //ask user what type of operations he want to do
    cout<<"1.Dodawanie"<<endl;
    cout<<"2.Odejmowanie"<<endl;
    cout<<"3.Mnozenie"<<endl;
    cout<<"4.Dzielenie"<<endl;
    cin>>opt;
    string range;
    string result;
    option=stoi(opt);
    cout<<"Podaj zakres dzialania Poczatek:Koniec np: A0:A5( w dzieleniu i odejmowaniu brane sa dokladnie te dwie wartosci)"<<endl; //ask user about range of operation
    cin>>range;
    cout<<"Podaj komorke w ktorej ma pojawic sie wynik"<<endl;
    cin>>result;  
    replace(range.begin(),range.end(), ':',' ');
    vector<string> array;
    stringstream ss(range);
    string temp;
    while(ss >>temp)
        array.push_back(temp);
    int cord1x=col(array[0]);
    int cord2x=col(array[1]);
    int cord1y=line(array[0]);
    int cord2y=line(array[1]);
    int coordx=col(result);
    int coordy=line(result);
    switch(option)
    {
        case 1: //make addition
        {
            float score=0;
            string buf;
            for(int i=cord1x;i<=cord2x;i++)
            {
                for(int j=cord1y;j<=cord2y;j++)
                {
                    buf=cells[j][i].print();
                    try
                    {
                        float a = stof(buf); //check if all the content in the range is a number
                        score+=a;
                    }
                    catch(invalid_argument const & e)
                    {
                        cout<<"W podanym zakresie komorek znajduja sie nie liczby!"<<endl;
                    }
                }
            }
            cells[coordy][coordx].addContent(to_string(score));
            break;
        }
        case 2: //make substraction
        {
            float score=0;
            string buf1,buf2;
                    buf1=cells[cord1y][cord1x].print();
                    buf2=cells[cord2y][cord2x].print();
                    try
                    {
                        float a = stof(buf1);//check if the content is a number
                        float b = stof(buf2);//check if the content is a number
                        score=a-b;
                    }
                    catch(invalid_argument const & e)
                    {
                        cout<<"W podanym zakresie komorek znajduja sie nie liczby!"<<endl;
                    }
            cells[coordy][coordx].addContent(to_string(score));
            break;
        }
         case 3: //make multiplication
        {
            float score=1;
            string buf;
            for(int i=cord1x;i<=cord2x;i++)
            {
                for(int j=cord1y;j<=cord2y;j++)
                {
                    buf=cells[j][i].print();
                    try
                    {
                        float a = stof(buf);//check if all the content in the range is a number
                        score*=a;
                    }
                    catch(invalid_argument const & e)
                    {
                        cout<<"W podanym zakresie komorek znajduja sie nie liczby!"<<endl;
                    }
                }
            }
            cells[coordy][coordx].addContent(to_string(score));
            break;
        }
         case 4: //make division
        {
            float score=0;
            string buf1,buf2;
                    buf1=cells[cord1y][cord1x].print();
                    buf2=cells[cord2y][cord2x].print();
                    try
                    {
                        float a = stof(buf1);//check if the content is a number
                        float b = stof(buf2);//check if the content is a number
                        score=a/b;
                    }
                    catch(invalid_argument const & e)
                    {
                        cout<<"W podanym zakresie komorek znajduja sie nie liczby!"<<endl;
                    }
            cells[coordy][coordx].addContent(to_string(score));
            break;
        }
    }
}
//save sheet to the file
void Sheet::savetoFile()
{
    string name;
    cout<<"Podaj nazwe pliku do ktorego arkusz ma zostac zapisany"<<endl;
    cin>>name;
    string buffor;
    ifstream file(name+".txt");
    if(file.good())
    {
        char option;
        cout<<"Czy chcesz zmienic zawartosc pliku? T/N"<<endl;
        cin>>option;
        if(option=='T')
        {
            file.close();
            ofstream outfile(name+".txt");
            outfile<<this->name<<endl;
            outfile<<length<<" "<<width<<endl;
            for(int i=0;i<length;i++)
            {
                for(int j=0;j<width;j++)
                {
                    buffor=cells[i][j].print();
                    if (buffor!=" ")
                    {
                        outfile<< buffor<<" ";
                    }
                    else
                    {
                        outfile<<"- ";
                    }          
                }
                outfile<<endl;
            }
            outfile<<charts.size()<<endl;
            for(int i=0;i<charts.size();i++)
            {
                if(charts[i].printtitle()!="")
                {
                   outfile<<charts[i].printtitle()<<endl; 
                }
                else
                {
                    outfile<<"-"<<endl;
                }
                if(charts[i].print_axis_x()!="")
                {
                   outfile<<charts[i].print_axis_x()<<endl; 
                }
                else
                {
                    outfile<<"-"<<endl;
                }
                if(charts[i].print_axis_y()!="")
                {
                   outfile<<charts[i].print_axis_y()<<endl; 
                }
                else
                {
                    outfile<<"-"<<endl;
                }
                vector<float> x = charts[i].print_rangex();
                for(int j=0;j<x.size();j++)
                {
                    outfile<<x[j]<<" ";
                }
                outfile<<endl;
                vector<float> y = charts[i].print_rangey();
                for(int j=0;j<y.size();j++)
                {
                    outfile<<y[j]<<" ";
                }
                outfile<<endl;
            }

            outfile.close();

        }
        else if(option=='N')
        {
            file.close();
            this->savetoFile();
        }
        else
        {
            cout<<"Wybierz poprawna opcje!"<<endl;
        }
               
    }
    else
    {
        file.close();
        ofstream outfile(name+".txt");
        outfile<<this->name<<endl;
        outfile<<length<<" "<<width<<endl;
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<width;j++)
            {
                buffor=cells[i][j].print();
                if (buffor!=" ")
                {
                    outfile<< buffor<<" ";
                }
                else
                {
                    outfile<<"- ";
                }
                
            }
            outfile<<endl;
        }
        outfile<<charts.size()<<endl;
            for(int i=0;i<charts.size();i++)
            {
                if(charts[i].printtitle()!="")
                {
                   outfile<<charts[i].printtitle()<<endl; 
                }
                else
                {
                    outfile<<"- "<<endl;
                }
                if(charts[i].print_axis_x()!="")
                {
                   outfile<<charts[i].print_axis_x()<<endl; 
                }
                else
                {
                    outfile<<"- "<<endl;
                }
                if(charts[i].print_axis_y()!="")
                {
                   outfile<<charts[i].print_axis_y()<<endl; 
                }
                else
                {
                    outfile<<"- "<<endl;
                }
                vector<float> x = charts[i].print_rangex();
                for(int j=0;j<x.size();j++)
                {
                    outfile<<x[j]<<" ";
                }
                outfile<<endl;
                vector<float> y = charts[i].print_rangey();
                for(int j=0;j<y.size();j++)
                {
                    outfile<<y[j]<<" ";
                }
                outfile<<endl;
            }
        outfile.close();
    }
}
//load sheet from file
void Sheet::loadfromFile(string name1)
{
    int wid,len;
    ifstream read(name1+".txt");
    string name2;
    read>>name2;
    read>>len>>wid;
    if(read.is_open())
    {
        string znak;
        for(int i=0;i<length;i++)
        {
            for (int j=0;j<width;j++)
            {
                read>>znak;
                if(znak!="-")
                {
                    cells[i][j].addContent(znak);
                }
            }
        }
        int size;
        read>>size;
        read.ignore();
        string title,axis_x,axis_y,rangex,rangey;
        for(int i=0;i<size;i++)
        {
            getline(read,title);
            getline(read,axis_x);
            getline(read,axis_y);
            getline(read,rangex);
            vector<float> range_x;
            stringstream s1(rangex);
            string temp;
            while(s1 >>temp)
                range_x.push_back(stof(temp));
            getline(read,rangey);
            vector<float> range_y;
            stringstream s2(rangey);
            while(s2 >>temp)
                range_y.push_back(stof(temp));
            Chart *c = new Chart(range_x,range_y); //create new chart with axis x and y values
            charts.push_back(*c);
        }
    }
    read.close();
}
//create chart
void Sheet::createChart()
{
    string axis_y,axis_x;
    vector<float> rangex,rangey;
    cout<<"Podaj zakres osi X(tylko wartosci liczbowe)"<<endl;//ask user for axis x values
    cin>>axis_x;
    cout<<"Podaj zakres osi Y(tylko wartosci liczbowe)"<<endl;//ask user for axis y values
    cin>>axis_y;
    replace(axis_x.begin(),axis_x.end(), ':',' ');
    vector<string> array;
    stringstream ss(axis_x);
    string temp;
    while(ss >>temp)
        array.push_back(temp);
    int cord1x=col(array[0]);
    int cord2x=col(array[1]);
    int cord1y=line(array[0]);
    int cord2y=line(array[1]);
    string buf;
    if(cord1x>cord2x || cord1y>cord2y)
    {
         throw RangeException();
    }
    for(int i=cord1y;i<=cord2y;i++)
    {
        for(int j=cord1x;j<=cord2x;j++)
        {
            buf=cells[i][j].print();
            int b=stof(buf);
            rangex.push_back(b);
        }
    }
    array.clear();
    replace(axis_y.begin(),axis_y.end(), ':',' ');
    stringstream s1(axis_y);
    while(s1 >>temp)
        array.push_back(temp);
    cord1x=col(array[0]);
    cord2x=col(array[1]);
    cord1y=line(array[0]);
    cord2y=line(array[1]);
    if(cord1x>cord2x || cord1y>cord2y)
    {
        throw RangeException();
    }
    for(int i=cord1y;i<=cord2y;i++)
    {
        for(int j=cord1x;j<=cord2x;j++)
        {
            buf=cells[i][j].print();
            int b=stof(buf);
            rangey.push_back(b);
        }
    }
    if (rangex.size()==rangey.size())
    {
        Chart *c = new Chart(rangex,rangey); //create new chart with axis x and y values
        charts.push_back(*c);
    }
    else
    {
        cout<<"Osie nie posiadaja takich samych liczby elementow";
    }
    
}
//print chart
void Sheet::printChart()
{
    string opt;
    int option;
    cout<<"Wskaz wykres ktory chcesz wyswietlic"<<endl; //print the list of all charts and ask user which one he want to print
    for(int i=0;i<charts.size();i++)
    {
        cout<<i<<". "<<charts[i].printtitle()<<endl;
    }
    cin>>opt;
    option=stoi(opt);
    charts[option].draw();
}
//delete chart
void Sheet::deleteChart()
{
    string opt;
    int option;
    cout<<"Wskaz wykres ktory chcesz usunac"<<endl;//print the list of all charts and ask user which one he want to delete
    for(int i=0;i<charts.size();i++)
    {
        cout<<i<<". "<<charts[i].printtitle()<<endl;
    }
    cin>>opt;
    option=stoi(opt);
    charts.erase(charts.begin()+option);
}
//edit chart
void Sheet::editChart(int mode)
{
    if(mode==0)
    {
        bool work =true;
        string opt;
        int option;
        while(work)
        {
            cout<<"Wybierz dzialanie z listy:"<<endl;
            cout<<"1.Nadaj tytul wykresowi"<<endl;
            cout<<"2.Dodaj tytul osi X"<<endl;
            cout<<"3.Dodaj tytul osi Y"<<endl;
            cout<<"4.Narysuj wykres"<<endl;
            cout<<"5.Powroc do poprzednich opcji"<<endl;
            cout<<"Podaj dzialanie:"<<endl;
            cin>>opt;
            option=stoi(opt);
            switch(option)
            {
                case 1:
                {
                    charts[charts.size()-1].addtitle();
                    break;
                }
                case 2:
                {
                    charts[charts.size()-1].name_axisx();
                    break;
                }
                case 3:
                {
                    charts[charts.size()-1].name_axisy();
                    break;
                }
                case 4:
                {
                    charts[charts.size()-1].draw();
                    break;
                }
                case 5:
                {
                    work=false;
                    break;
                }
            }
        }
    }
    else
    {
        string opt;
        int option1;
        cout<<"Wskaz wykres ktory chcesz wyswietlic"<<endl;
        for(int i=0;i<charts.size();i++)
        {
            cout<<i<<". "<<charts[i].printtitle()<<endl;
        }
        cin>>opt;
        option1=stoi(opt);
        bool work =true;
        int option;
        while(work)
        {
            cout<<"Wybierz dzialanie z listy:"<<endl;
            cout<<"1.Nadaj tytul wykresowi"<<endl;
            cout<<"2.Dodaj tytul osi X"<<endl;
            cout<<"3.Dodaj tytul osi Y"<<endl;
            cout<<"4.Narysuj wykres"<<endl;
            cout<<"5.Powroc do poprzednich opcji"<<endl;
            cout<<"Podaj dzialanie:"<<endl;
            cin>>opt;
            option=stoi(opt);
            switch(option)
            {
                case 1:
                {
                    charts[option1].addtitle();
                    break;
                }
                case 2:
                {
                    charts[option1].name_axisx();
                    break;
                }
                case 3:
                {
                    charts[option1].name_axisy();
                    break;
                }
                case 4:
                {
                    charts[option1].draw();
                    break;
                }
                case 5:
                {
                    work=false;
                    break;
                }
            }
        }
    }
}