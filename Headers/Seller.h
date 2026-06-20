#pragma once
#include "Person.h"
#include <string>

class Seller : public Person {
	double badProbability;
	bool arrested;
	bool cheated;
	int stolen;

public:
	Seller();
	Seller(const std::string& name, double prob);

	double getProb() const;

	int stole() const;

	bool isArrested() const;

	bool testCheat() const;
	
	void cheat();

	void getArrested();

	void steal(int n);

	void printName() const;

	void printInfo() const override;
};