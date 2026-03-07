
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("default"), is_Signed(false), gradeSign(30), gradeExecute(30)
{}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute)
    : name(name), is_Signed(false), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& b)
    : name(b.name), is_Signed(b.is_Signed), gradeSign(b.gradeSign), gradeExecute(b.gradeExecute)
{}

AForm& AForm::operator=(const AForm& form)
{
    if (this != &form)
        is_Signed = form.is_Signed;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const    { return name; }
bool        AForm::getIsSigned() const { return is_Signed; }
int         AForm::getGradeSign() const    { return gradeSign; }
int         AForm::getGradeExecute() const { return gradeExecute; }

bool AForm::beSigned(const Bureaucrat* b)
{
    if (b->getGrade() > gradeSign)
        throw GradeTooLowException();
    is_Signed = true;
    return true;
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!is_Signed)
        throw NotSignedException();
    if (executor.getGrade() > gradeExecute)
        throw GradeTooLowException();
    performAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "AForm is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form: "                      << f.getName()
       << " | Signed: "                 << (f.getIsSigned() ? "yes" : "no")
       << " | Sign grade required: "    << f.getGradeSign()
       << " | Execute grade required: " << f.getGradeExecute();
    return os;
}