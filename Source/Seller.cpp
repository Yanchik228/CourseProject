#include "Seller.h"
#include <stdexcept>
#include <iostream>

Seller::Seller()
	: Person("Невідомо"), badProbability(0.0), arrested(false), cheated(false), stolen(0) {}
Seller::Seller(const std::string& name, double prob)
	: Person(name), badProbability(prob), arrested(false), cheated(false), stolen(0)
{
	if (badProbability > 1.0 || badProbability < 0.0) {
		throw std::invalid_argument("Неможливий шанс!");
	}
}

double Seller::getProb() const {
	return badProbability;
}

int Seller::getStolen() const {
	return stolen;
}

bool Seller::isArrested() const {
	return arrested;
}

bool Seller::testCheat() const {
	return cheated;
}

void Seller::cheat() {
	cheated = true;
}

void Seller::steal(int n) {
	stolen += n;
}

void Seller::getArrested() {
	arrested = true;
}

void Seller::printName() const {
	std::cout << fullName;
}

void Seller::printInfo() const {
	std::cout << fullName << ", " << "шанс порушення: " << badProbability * 100 << "%";
	if (arrested) {
		std::cout << " [Арештован]";
	}
}