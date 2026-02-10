#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        std::string name;
        bool b;
        const int gradeSign;
        const int gradeExe;
    public:
        Form();
        Form(const Form &b);
        Form& operator=(const Form& Form);
        ~Form();
        beSigned(Bureaucrat b, );
};

#endif
