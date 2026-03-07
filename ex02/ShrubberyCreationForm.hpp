#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();    
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& s);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
        ~ShrubberyCreationForm();
        void doExecute() const;
};

#endif