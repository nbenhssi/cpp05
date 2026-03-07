#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"),  is_signed(false), gradeSign(10), gradeExecute(10) 
{}

Form::Form(const std::string name, const int gradeSign, const int gradeExecute) : name(name), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw   GradeTooLowException();  
}
Form &Form::operator=(const Form &f)
{
    if (this != &f)
        is_signed = f.is_signed;//whhy just is_signed
    return *this;
}

Form::Form(const Form&b): name(b.name), is_signed(b.is_signed), gradeSign(b.gradeSign), gradeExecute(b.gradeExecute)
{}
Form::~Form(){}


const char * Form::GradeTooHighException::what() const throw()
{
    return "Grade Too High Exception";
}


const char * Form::GradeTooLowException::what() const throw()
{
    return "Grade Too Low Exception";
}

const std::string Form::getName() const
{
    return name;
}
bool Form::getIsSigned() const
{
    return is_signed;
}
int Form::getGradeSign() const
{
    return gradeSign;
}
int Form::getGradeExecute() const
{
    return gradeExecute;
}

bool Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= gradeSign)
        is_signed = true;
    else 
        throw GradeTooLowException();  
    return true;      
}


std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: "              << f.getName()
       << " | signed: "         << (f.getIsSigned() ? "yes" : "no")
       << " | grade to sign: "  << f.getGradeSign()
       << " | grade to execute: "<< f.getGradeExecute();
    return os;
}
