#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"),  is_signed(false), gradeSign(10), gradeExecute(10) 
{}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExecute) : name(name), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw   GradeTooLowException();  
}
AForm &AForm::operator=(const AForm &f)
{
    if (this != &f)
        is_signed = f.is_signed;//whhy just is_signed
    return *this;
}

AForm::AForm(const AForm&b): name(b.name), is_signed(b.is_signed), gradeSign(b.gradeSign), gradeExecute(b.gradeExecute)
{}
virtual AForm::~AForm(){}


const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High Exception";
}


const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low Exception";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm is not signed!";
}

const std::string AForm::getName() const
{
    return name;
}
bool AForm::getIsSigned() const
{
    return is_signed;
}
int AForm::getGradeSign() const
{
    return gradeSign;
}
int AForm::getGradeExecute() const
{
    return gradeExecute;
}

bool AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= gradeSign)
        is_signed = true;
    else 
        throw GradeTooLowException();  
    return true;      
}


std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form: "              << f.getName()
       << " | signed: "         << (f.getIsSigned() ? "yes" : "no")
       << " | grade to sign: "  << f.getGradeSign()
       << " | grade to execute: "<< f.getGradeExecute();
    return os;
}
void AForm::execute(Bureaucrat const & executor) const
{
    if (!is_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeExecute)
        throw GradeTooLowException();
    doExecute();
}
