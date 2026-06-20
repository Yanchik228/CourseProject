#include "Memory.h"

std::vector<std::shared_ptr<Visitor>> Memory::visitors;
std::vector<std::shared_ptr<Seller>> Memory::sellers;
std::vector<std::shared_ptr<Dish>> Memory::dishes;

std::shared_ptr<Visitor> Memory::selectedVisitor = nullptr;
std::shared_ptr<Seller> Memory::selectedSeller = nullptr;

void Memory::addVisitor(const std::shared_ptr<Visitor>& visitor) {
	if (visitor != nullptr) {
		visitors.push_back(visitor);
	}
}
void Memory::addSeller(const std::shared_ptr<Seller>& seller) {
	if (seller != nullptr) {
		sellers.push_back(seller);
	}
}
void Memory::addDish(const std::shared_ptr<Dish>& dish) {
	if (dish != nullptr) {
		dishes.push_back(dish);
	}
}

bool Memory::deleteVisitor(size_t index) {
	if (index < visitors.size()) {
		visitors.erase(visitors.begin() + index);
		return true;
	}
	return false;
}
bool Memory::deleteSeller(size_t index) {
	if (index < sellers.size()) {
		sellers.erase(sellers.begin() + index);
		return true;
	}
	return false;
}
bool Memory::deleteDish(size_t index) {
	if (index < dishes.size()) {
		dishes.erase(dishes.begin() + index);
		return true;
	}
	return false;
}

std::shared_ptr<Visitor> Memory::getVisitor(size_t index) {
	if (index < visitors.size()) {
		return visitors[index];
	}
	return nullptr;
}
std::shared_ptr<Seller> Memory::getSeller(size_t index) {
	if (index < sellers.size()) {
		return sellers[index];
	}
	return nullptr;
}
std::shared_ptr<Dish> Memory::getDish(size_t index) {
	if (index < dishes.size()) {
		return dishes[index];
	}
	return nullptr;
}

size_t Memory::getVisitorCount() {
	return visitors.size();
}
size_t Memory::getSellerCount() {
	return sellers.size();
}
size_t Memory::getDishCount() {
	return dishes.size();
}

void Memory::selectVisitor(size_t index) {
	if (index < visitors.size()) {
		selectedVisitor = visitors[index];
	}
}
void Memory::selectSeller(size_t index) {
	if (index < sellers.size()) {
		selectedSeller = sellers[index];
	}
}
void Memory::nullSeller() {
	selectedSeller = nullptr;
}

std::shared_ptr<Visitor> Memory::getSelectedVisitor() {
	return selectedVisitor;
}
std::shared_ptr<Seller> Memory::getSelectedSeller() {
	return selectedSeller;
}

std::vector<std::shared_ptr<Dish>> Memory::returnDishes() {
	return dishes;
}
std::vector<std::shared_ptr<Seller>> Memory::returnSellers() {
	return sellers;
}