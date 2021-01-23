#include <iostream>
#include "Sheet.h"
#include <string>
#include <cctype>
#include <fstream>
#include "RangeException.cpp"
using namespace std;
void start_view();
void edit_view(Sheet &object)
{
    int option;
    string opt;
    bool work = true;
    bool write = true;
    while (work)
    {
        //print edit sheet option and ask user to choose one
        cout << "1.Dodaj zawartosc komorki" << endl;
        cout << "2.Usun zawartosc komorki" << endl;
        cout << "3.Wyswietl aktualny arkusz" << endl;
        cout << "4.Wykonaj operacje arytmetyczna" << endl
            << "(dodawanie,odejmowanie,mnozenie,dzielenie)" << endl;
        cout << "5.Wyszukaj minimum/maksimum" << endl;
        cout << "6.Wyszukaj komorke o danej wartosci" << endl;
        cout << "7.Dodaj wiersz/kolumne" << endl;
        cout << "8.Usun wiersz/kolumne" << endl;
        cout << "9.Zapisz arkusz do pliku" << endl;
        cout << "10.Utworz wykres" << endl;
        cout << "11.Wyswietl wykres" << endl;
        cout << "12.Edytuj wykres" << endl;
        cout << "13.Usun wykres wykres" << endl;
        cout << "14.Powrot do porzednich opcji" << endl;
        cout << "15.Koniec programu" << endl;
        cout << "Podaj dzialanie:" << endl;
        cin >> opt;
        try
        {
            option = stoi(opt);
            switch (option)
            {
            case 1:
            {
                object.addcontent(); //add content to one of sheet cells
                write = false;
                break;
            }
            case 2:
            {
                object.deletecontent();//delete content from one of sheet cells
                write = false;
                break;
            }
            case 3:
            {
                object.printsheet(); //print sheet 
                break;
            }
            case 4:
            {
                object.arithmetic(); //do one of four arithmetic operations
                write = false;
                break;
            }
            case 5:
            {
                object.min_max(); //look for min/max from sheet cells
                write = false;
                break;
            }
            case 6:
            {
                object.coordinates(); //look for cell that have specify content
                break;
            }
            case 7:
            {
                object.addcolumn_line(); //add column or line to sheet
                write = false;
                break;
            }
            case 8:
            {
                object.deletecolumn_line(); // delete column or line from sheet
                write = false;
                break;
            }
            case 9:
            {
                object.savetoFile(); //save sheet to file
                write = true;
                break;
            }
            case 10:
            {
                write=false;
                object.createChart(); //create chart
                object.editChart(0); //edit created chart
                break;
            }
            case 11:
            {
                object.printChart(); //print chart list
                break;
            }
            case 12:
            {
                write=false;
                object.editChart(1); //edit chart from list
                break;
            }
            case 13:
            {
                write=false;
                object.deleteChart(); //delete chart
                break;
            }
            case 14:
            {
                if (write == false) //check if user want to save sheet before came back to the start options
                {
                    char op;
                    cout << "Chcesz zapisac arkusz przed wyjsciem? T/N" << endl;
                    cin >> op;
                    if (op == 'T')
                    {
                        object.savetoFile();
                        start_view();
                    }
                    else
                    {
                        start_view();
                    }
                }
                else
                {
                    start_view();
                }
                break;
            }
            case 15:
            {
                if (write == false) //check if user want to save sheet before close the program
                {
                    char op;
                    cout << "Chcesz zapisac arkusz przed wyjsciem? T/N" << endl;
                    cin >> op;
                    if (op == 'T')
                    {
                        object.savetoFile();
                        exit(EXIT_SUCCESS);
                    }
                    else
                    {
                        exit(EXIT_SUCCESS);
                    }
                }
                else
                {
                    exit(EXIT_SUCCESS);
                }
                break;
            }
            default:
            {
                cout << "Podana opcja nie istnieje wybierz jedna z listy!" << endl;
                break;
            }
            }
        }
        catch (invalid_argument const &e)
        {
            cout << "Bledny argument! Podaj odpowiednia wartosc!" << endl;
        }
        catch(RangeException &e)
        {
            cout<<e.what()<<endl;
        }
    }
}
void start_view()
{
    int option;
    string op;
    bool work = true;
    while (true)
    {
        //print the started options and ask user to choose one
        cout << "Witamy w Arkuszu Kalkulacyjnym. Oto lista dzialan: " << endl;
        cout << "1.Utworz Arkusz" << endl;
        cout << "2.Wczytaj Arkusz z pliku" << endl;
        cout << "3.Zamknij program" << endl;
        cout<<"Podaj dzialanie: "<<endl;
        cin >> op;
        try
        {
            option = stoi(op);
            switch (option)
            {
            case 1:
            {
                //ask user for sheet name and size
                int width, length;
                string name;
                cout << "Podaj nazwe arkusza" << endl;
                cin >> name;
                cout << "Podaj ilosc kolumn" << endl;
                cin >> width;
                if(width<26)
                {
                cout << "Podaj ilosc wierszy" << endl;
                cin >> length;
                Sheet *object = new Sheet(name, width, length); //create sheet
                edit_view(*object); //call out the edit sheet view
                }
                else
                {
                    cout<<"Za duza liczba kolumn!"<<endl;
                    break;
                }
                
            }
            break;
            case 2:
            {
                //ask user for file name
                string name, name1;
                int wid, len;
                cout << "Podaj nazwe pliku z ktorego wczytany ma zostac arkusz" << endl;
                cin >> name;
                ifstream read(name + ".txt");
                if(read.good()) //check if the file exist
                {
                read >> name1;
                read >> len >> wid;
                read.close();
                Sheet *object = new Sheet(name1, wid, len); //create sheet
                object->loadfromFile(name); //load sheet from file
                edit_view(*object); //call out the sheet edit view
                }
                else
                {
                    cout<<"Podany plik nie istnieje!"<<endl;
                }
                
                break;
            }
            case 3:
            {
                exit(EXIT_SUCCESS);
            }
            default:
            {
                cout << "Nie ma takiej opcji wybierz jedna z listy!";
                break;
            }
            }
        }
        catch (invalid_argument const &e)
        {
            cout << "Nie ma takiej opcji! Wybierz jedna z listy!" << endl;
        }
    }
}
int main()
{
    start_view(); //call out start view function
    return 0;
}