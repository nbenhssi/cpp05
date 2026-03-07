#include <iostream>
#include <cstdlib>

// class dive{
//     std::string ms;
//     public:
//         dive(const std::string& m) : ms(m){}
//         std::string wat()const {return ms;}
// };

// class ValeurNegativeException
// {
//     std::string ms;
//     public:
//         ValeurNegativeException(const std::string &m) : ms(m){}
//         std::string wat() const {return ms;}
// };

// int division(int a, int b) 
// {
//     int *t;
//     t = (int *)malloc(2* sizeof(int));
//     if (b == 0)
//     {
//         dive e("Division by zero is not allowed!");
//         throw e;
//     }
//     if (a< 0)
//     {
//         ValeurNegativeException p("a < 0");
//         throw p;
//     }
//     t[0] = a/b;
//     t[1] = '\0';
//     return (t[0]);
// }


// int main()
// {
//     try
//     {
//         division(-11,10);
//     }
//     catch(const dive& m)
//     {
//         std::cout<< m.wat() <<std::endl;
//     }
//     catch(ValeurNegativeException &p)
//     {
//         std::cout << p.wat() <<std::endl;
//     }

// }

#include <iostream>
#include <exception>

class MyException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "exception";
    }
};


int main()
{
    try
    {
        throw MyException();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}