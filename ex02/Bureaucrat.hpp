#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include<exception>

class AForm;
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(Bureaucrat &b);
        Bureaucrat operator=(Bureaucrat &b);
        ~Bureaucrat();
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &f) const;
        void executeForm(AForm const& form) const;

};


std::ostream &operator<<(std::ostream& os, Bureaucrat &b);

#endif
