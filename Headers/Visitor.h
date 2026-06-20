#pragma once
#include "Person.h"
#include <string>

class Visitor : public Person {
public:
	Visitor();
	Visitor(const std::string& name, int money);

	void printInfo() const override;
};