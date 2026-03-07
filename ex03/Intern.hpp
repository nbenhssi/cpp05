#ifndef Intern_HPP
#define Intern_HPP
#include "AForm.hpp"
class Intern
{
    public:
        Intern();
        Intern(const Intern& i);
        Intern& operator=(const Intern& i);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target) const;
};
#endif