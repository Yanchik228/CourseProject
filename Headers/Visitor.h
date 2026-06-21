#pragma once
#include "Person.h"
#include <string>

class Visitor : public Person {
	int money;
public:
	Visitor();
	Visitor(const std::string& name, int money);

	int getMoney() const;

	void changeMoney(int n);

	void printInfo() const override;
};