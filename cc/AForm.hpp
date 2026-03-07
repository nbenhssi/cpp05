#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
class Bureaucrat;
class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int gradeSign;
        const int gradeExecute;
    public:
        AForm();
        AForm(const std::string name, const int gradeSign, const int gradeExecute);
        AForm &operator=(const AForm &f);
        AForm(const AForm&f);
        virtual ~AForm();

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
        void execute(Bureaucrat const & executor) const;
        class FormNotSignedException : public std::exception
        {
            virtual const char * what() const throw();
        };
        virtual void doExecute() const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif