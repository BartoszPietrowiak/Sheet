#include <exception>
using namespace std;
//Range exception inherits from exception class
class RangeException:public exception
{
public:
RangeException(){};
//function returning the infromation about exception
virtual const char* what() const noexcept override
{
    return "Nie poprawny zakres osi!";
}
};
