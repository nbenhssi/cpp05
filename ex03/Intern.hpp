#ifndef Intern_HPP
#define Intern_HPP
#include "AForm.hpp"
class Intern
{
    public:
        AForm *createPresidential(const std::string& target);
        AForm *createRobotomy(const std::string& target);
        AForm *createShrubbery(const std::string& target);
        Intern();
        Intern(const Intern& i);
        Intern& operator=(const Intern& i);
        ~Intern();
        AForm* makeForm(const std::string& formName, const std::string& target) ;
};
#endif