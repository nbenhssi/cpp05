#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                is_Signed;
        const int           gradeSign;
        const int           gradeExecute;

    public:
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExecute);
        AForm(const AForm& b);
        AForm& operator=(const AForm& form);
        virtual  ~AForm();

         std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeSign() const;
        int         getGradeExecute() const;

        bool beSigned(const Bureaucrat* b);

        void execute(Bureaucrat const& executor) const;

        virtual void performAction() const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NotSignedException : public std::exception
        {
            public: 
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif