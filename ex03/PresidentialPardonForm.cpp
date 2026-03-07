#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p) : AForm(p), target(p.target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p)
{
    if (this != &p)
    {
        AForm::operator=(p);
        target = p.target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::doExecute() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
