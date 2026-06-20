#include "Dish.h"
#include <stdexcept>
#include <iostream>
#include <cmath>

Dish::Dish()
	: name("Невідомо"), price(0), quantity(0), tempSold(0) {}
Dish::Dish(const std::string& name, int price, int quantity)
	: name(name), price(price), quantity(quantity), tempSold(0)
{
	if (name.empty()) {
		throw std::invalid_argument("Назва не може бути порожнім!");
	}
	if (price < 0) {
		throw std::invalid_argument("Вартість не може бути негативною!");
	}
	if (quantity <= 0) {
		throw std::invalid_argument("Кількість не може бути негативною/нульовою!");
	}
}

HotDish::HotDish(const std::string& name, int price, int quantity)
	: Dish(name, price, quantity) {}

ColdDish::ColdDish(const std::string& name, int price, int quantity) 
	: Dish(name, price, quantity) {}

Beverage::Beverage(const std::string& name, int price, int quantity)
	: Dish(name, price, quantity) {}

std::string Dish::getName() const {
	return name;
}
int Dish::getPrice() const {
	return price;
}
int Dish::getQuantity() const {
	return quantity;
}
int Dish::getTempSold() const {
	return tempSold;
}

void Dish::increaseQuantity(int increase) {
	if (increase <= 0) return;
	else {
		quantity += increase;
	}
}
void Dish::increaseTempSold(int increase) {
	if (increase <= 0) return;
	else {
		tempSold += increase;
		quantity -= increase;
	}
}
void Dish::resetBackTempSold() {
	quantity += tempSold;
	tempSold = 0;
}
void Dish::resetTempSold() {
	tempSold = 0;
}

void Dish::printInfo() const {
	std::cout << "[" << getType() << "] " << name << ", ціна: " << price << " грн, кількість: " << quantity << " порцій";
}

std::string HotDish::getType() const {
	return "Гаряча страва";
}
std::string ColdDish::getType() const {
	return "Холодна страва";
}
std::string Beverage::getType() const {
	return "Напій";
}