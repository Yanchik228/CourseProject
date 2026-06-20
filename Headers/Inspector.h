#pragma once
#include "Person.h"
#include <string>

class Inspector : public Person {
	std::string organization; //Зробив для нащадка, а не классу Person
public:
	Inspector();
	Inspector(const std::string& name, const std::string& org);

	void printInfo() const override;
};