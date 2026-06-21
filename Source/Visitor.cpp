#include "Visitor.h"
#include <iostream>

Visitor::Visitor()
	: Person("Невідомо"), money(0) {}
Visitor::Visitor(const std::string& name, int money)
	: Person(name), money(money) 
{
	if (money < 0) {
		throw std::invalid_argument("Грошей не може бути від'ємна кількість!");
	}
}

int Visitor::getMoney() const {
	return money;
}

void Visitor::changeMoney(int n) {
	money += n;
}

void Visitor::printInfo() const {
	std::cout << fullName << ", " << "грошей: " << money << " грн";
}