#pragma once
#include <string>

class Person {
protected:
	std::string fullName;
	std::string position; // В завданні було вказано додати посаду як поле, проте ціль цього мені не зрозуміла тому в конструкторі це поле не використовується
	int money;

public:
	Person();
	Person(const std::string& name, int money);

	int getMoney() const;
	
	void changeMoney(int n);
	void setName(const std::string& name);

	virtual void printInfo() const = 0;

	virtual ~Person() = default;
};