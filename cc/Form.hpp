#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;
class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int gradeSign;
        const int gradeExecute;
    public:
        Form();
        Form(const std::string name, const int gradeSign, const int gradeExecute);
        Form &operator=(const Form &f);
        Form(const Form&f);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;
        bool beSigned(const Bureaucrat& b);


};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif