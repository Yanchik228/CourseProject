#include "Person.h"
#include <stdexcept>
#include <iostream>

Person::Person()
	: fullName("Невідомо"), money(0) {}
Person::Person(const std::string& name, int money)
	: fullName(name), money(money)
{
	if (fullName.empty()) {
		throw std::invalid_argument("ПІБ не може бути порожнім!");
	}
	if (money < 0) {
		throw std::invalid_argument("Грошей не може бути від'ємна кількість!");
	}
}

int Person::getMoney() const {
	return money;
}

void Person::changeMoney(int n) {
	money += n;
}
