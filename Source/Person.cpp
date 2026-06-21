#include "Person.h"
#include <stdexcept>
#include <iostream>

Person::Person()
	: fullName("Невідомо") {}
Person::Person(const std::string& name)
	: fullName(name)
{
	if (fullName.empty()) {
		throw std::invalid_argument("ПІБ не може бути порожнім!");
	}
}
