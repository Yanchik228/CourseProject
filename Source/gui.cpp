#include "gui.h"
#include "Memory.h"
#include <iostream>

void showGui() {
	std::cout << "\n--------Інтерфейс--------";
	std::cout << "\n1. Вибрати покупця";
	if (Memory::getSelectedVisitor() != nullptr) {
		std::cout << " (Вибраний: ";
		Memory::getSelectedVisitor()->printInfo();
		std::cout << ")";
	}
	std::cout << "\n2. Вибрати продавця";
	if (Memory::getSelectedSeller() != nullptr) {
		std::cout << " (Вибраний: ";
		Memory::getSelectedSeller()->printInfo();
		std::cout << ")";
	}
	std::cout << "\n3. Показати меню";
	std::cout << "\n4. Закінчити день";
	std::cout << "\n7. Додати блюдо";
	std::cout << "\n8. Додати людину";
	std::cout << "\n9. Видалити людину";
	std::cout << "\n0. Вихід";

	std::cout << "\n\nВаш вибір: ";
}

void showMenu(bool cycle, int tempMoney) {
	for (int i = 0; i < Memory::getDishCount(); i++) {
		std::cout << '\n' << i + 1 << ". ";
		Memory::getDish(i)->printInfo();
	}
	if (cycle) {
		std::cout << "\n" << Memory::getDishCount() + 1 << ". Зробити замовлення";
	}

	std::cout << "\n0. Вихід";
	std::cout << "\nУ покупця грошей: " << Memory::getSelectedVisitor()->getMoney() << " грн, замовлення: " << tempMoney << " грн";

	std::cout << "\n\nЩо купуєте: ";
}

void showPickVisitor() {
	for (int i = 0; i < Memory::getVisitorCount(); i++) {
		std::cout << '\n' << i + 1 << ". ";
		Memory::getVisitor(i)->printInfo();
	}
	std::cout << "\n0. Вихід";

	std::cout << "\n\nВаш вибір: ";
}
void showPickSeller() {
	for (int i = 0; i < Memory::getSellerCount(); i++) {
		std::cout << '\n' << i + 1 << ". ";
		Memory::getSeller(i)->printInfo();
	}
	std::cout << "\n0. Вихід";

	std::cout << "\n\nВаш вибір: ";
}

void showPickDish() {
	std::cout << "\n1. Гаряча страва";
	std::cout << "\n2. Холодна страва";
	std::cout << "\n3. Напій";
	std::cout << "\n0. Вихід";

	std::cout << "\n\nВаш вибір: ";
}

void showAddChoice() {
	std::cout << "\n1. Додати покупця";
	std::cout << "\n2. Додати продавця";
	std::cout << "\n0. Вихід";

	std::cout << "\n\nВаш вибір: ";
} 

void showBadBuyChoice() {
	std::cout << "\n[Недостатньо коштів!]";
	std::cout << "\n1. Зробити замовлення ще раз";
	std::cout << "\n2. Вихід";

	std::cout << "\n\nВаш вибір: ";
}

void showDeleteChoice() {
	std::cout << "\n1. Видалити покупця";
	std::cout << "\n2. Видалити продавця";
	std::cout << "\n0. Вихід";

	std::cout << "\n\nВаш вибір: ";
}

void showBought() {
	std::cout << "\n[Куплено]\n";
	bool count = false;
	for (auto dish : Memory::returnDishes()) {
		if (dish->getTempSold() > 0) {
			if (count) std::cout << "\n";
			std::cout << dish->getName() << ": " << dish->getTempSold() << " порцій";
			count = true;
		}
	}
}