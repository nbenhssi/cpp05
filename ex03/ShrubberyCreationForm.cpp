#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
{
            *this = s;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
    if (this != &s)
    {
        AForm::operator=(s);
        target = s.target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
void ShrubberyCreationForm::doExecute() const
{
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("could not open file for writing");

    file << "       _-_        \n";
    file << "    /~~   ~~\\     \n";
    file << " /~~         ~~\\  \n";
    file << "{               } \n";
    file << " \\  _-     -_  /  \n";
    file << "   ~  \\\\ //  ~   \n";
    file << "_- -   | | _- _   \n";
    file << "  _ -  | |   -_   \n";
    file << "      // \\\\       \n";
    file << "\n";


    file.close();
}
