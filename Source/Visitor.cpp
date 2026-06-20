#include "Visitor.h"
#include <iostream>

Visitor::Visitor()
	: Person("Невідомо", 0) {}
Visitor::Visitor(const std::string& name, int money)
	: Person(name, money) {}

void Visitor::printInfo() const {
	std::cout << fullName << ", " << "грошей: " << money << " грн";
}