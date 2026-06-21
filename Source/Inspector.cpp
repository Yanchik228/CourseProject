#include "Inspector.h"
#include <stdexcept>
#include <iostream>

Inspector::Inspector()
	: Person("Невідомо"), organization("Немає") {}
Inspector::Inspector(const std::string& name, const std::string& org)
	: Person(name), organization(org) 
{
	if (organization.empty()) {
		throw std::invalid_argument("Поле організації не може бути порожнім!");
	}
}

void Inspector::printInfo() const {
	std::cout << fullName << " (" << organization << ")";
}
