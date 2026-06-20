#include "gui.h"
#include "Memory.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <cmath>
#include <thread>
#include <chrono>

int main() {
	int cashRegister = 0;
	int totalSold = 0;
	int totalQuantity = 0;
	int totalMade = 0;

	//default
	Memory::addVisitor(std::make_shared<Visitor>("Коваленко Максим Андрійович", 550));
	Memory::addVisitor(std::make_shared<Visitor>("Шевченко Софія Олегівна", 400));
	Memory::addVisitor(std::make_shared<Visitor>("Богатій Дмитро Вікторович", 90000));
	Memory::addSeller(std::make_shared<Seller>("Ковальчук Софія Романівна", 0.05));
	Memory::addSeller(std::make_shared<Seller>("Шахрай Андрій Вікторович ", 0.90));
	Memory::addDish(std::make_shared<HotDish>("Борщ", 150, 15));
	Memory::addDish(std::make_shared<ColdDish>("Цезар", 270, 10));
	Memory::addDish(std::make_shared<Beverage>("Кава", 30, 25));
	Inspector inspector1("Козак Максим Сергійович", "Благородне товариство");
	for (auto dish : Memory::returnDishes()) {
		totalMade += dish->getQuantity();
		totalQuantity += dish->getQuantity();
	}

	//progamm
	int choice;

	while (true) {
		choice = inputChoice(showGui);

		if (choice == 1) {
			int visChoice;

			while (true) {
				visChoice = inputChoice(showPickVisitor);
				if (checkChoice(visChoice, Memory::getVisitorCount(), 0)) break;
			}
			if (visChoice == 0) continue;

			Memory::selectVisitor(visChoice - 1);
		}

		else if (choice == 2) {
			int selChoice;

			while (true) {
				selChoice = inputChoice(showPickSeller);
				if (Memory::getSeller(selChoice - 1)->isArrested()) {
					std::cout << "\n[У злодіїв нічого покупати не можна!]";
				}
				if (checkChoice(selChoice, Memory::getSellerCount(), 0)) break;
			}
			if (selChoice == 0) continue;

			

			Memory::selectSeller(selChoice - 1);
		}

		else if (choice == 3) {
			int dishChoice;
			bool cycle = false;
			bool cancelled = false;

			if (Memory::getSelectedVisitor() == nullptr) {
				std::cout << "\n[Спочатку виберіть покупця!]";
				continue;
			}
			if (Memory::getSelectedSeller() == nullptr) {
				std::cout << "\n[Спочатку виберіть продавця!]";
				continue;
			}

			std::vector<int> foodSelected;
			int tempMoney = 0;

			while (true) {
				int amount;
				while (true) {
					dishChoice = inputChoice([&] { showMenu(cycle, tempMoney); });
					if (!cycle) {
						if (checkChoice(dishChoice, Memory::getDishCount(), 0)) break;
					}
					else if (checkChoice(dishChoice, Memory::getDishCount() + 1, 0)) break;
				}
				if (dishChoice == 0) break;

				if (dishChoice == Memory::getDishCount() + 1) {
					if (tempMoney > Memory::getSelectedVisitor()->getMoney()) {
						int bChoice;
						while (true) {
							bChoice = inputChoice(showBadBuyChoice);
							if (checkChoice(bChoice, 2, 1)) break;
						}
						tempMoney = 0;
						for (auto dish : Memory::returnDishes()) {
							dish->resetBackTempSold();
						}
						if (bChoice == 1) continue;
						else if (bChoice == 2) break;
					}
					else {
						showBought();
						Memory::getSelectedVisitor()->changeMoney(-tempMoney);
						Memory::getSelectedSeller()->changeMoney(tempMoney);
						if (checkTruth(Memory::getSelectedSeller()->getProb())) {
							Memory::getSelectedSeller()->cheat();
							Memory::getSelectedSeller()->steal(tempMoney * 0.1);
							cashRegister += std::round(tempMoney * 0.9);
							
						}
						else cashRegister += tempMoney;
						for (auto dish : Memory::returnDishes()) {
							totalSold += dish->getTempSold();
							totalQuantity -= dish->getTempSold();
							dish->resetTempSold();
						}
						break;
					}
				}

				auto selectedDish = Memory::getDish(dishChoice - 1);

				std::cout << "Скільки порцій ви хочете купити? ";
				while (true) {
					std::cin >> amount;
					if (amount == 0) break;
					else if (amount < 0) {
						std::cout << "\n[Кількість не може бути негативной!]";
						break;
					}
					else if (amount > selectedDish->getQuantity()) {
						std::cout << "\n[Недостатньо порцій!]";
						break;
					}
					else {
						tempMoney += selectedDish->getPrice() * amount;
						selectedDish->increaseTempSold(amount);
						cycle = true;
						break;
					}
				}
			}
		}

		else if (choice == 4) {
			int tempTotalCash = 0;
			std::cout << "\n[День завершився]";
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			std::cout << "\nІнспектор ";
			inspector1.printInfo();
			std::cout << " перевіряє...";
			std::this_thread::sleep_for(std::chrono::milliseconds(1200));
			std::cout << "\nВсього продано: " << totalSold;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			std::cout << "\nВсього зроблено: " << totalMade;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			std::cout << "\nВсього залишилось: " << totalQuantity;
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			if ((totalMade - totalSold) == totalQuantity) {
				std::cout << "\nІнспектор не побачив зникнення товару ";
			}
			else std::cout << "\nІнспектор побачив зникнення товару ";
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			std::cout << "\nІнспектор перевіряє касу...";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "\n...";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			for (auto seller : Memory::returnSellers()) {
				tempTotalCash += seller->getMoney();
			}
			std::cout << "\nПовинно бути: " << tempTotalCash << " грн\nЄ в касі: " << cashRegister << " грн";
			if (tempTotalCash == cashRegister) {
				std::cout << "\nВсі продавці були чесними. Інспектор задоволен. ";
			}
			else {
				std::cout << "\nІнспектор не задоволен. В касі не хватает грошей\nІнспектор шукає злодія...\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(2500));
				int count = 1;
				for (auto seller : Memory::returnSellers()) {
					if(seller->testCheat()) {
						std::cout << "\nЗлочинець " << count << ": ";
						seller->printName();
						std::cout << ", вкрав: " << seller->stole() << " --- [АРЕШТОВАН]";
						seller->getArrested();
					}
				}
				if (Memory::getSelectedSeller()->isArrested()) {
					Memory::nullSeller();
				}
				std::cout << "\n[Всі злодії спіймані]"; 
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			std::cout << "\n\n[Новий день]";
			std::cout << "\nКількість їжі поповнино\n";
			for (auto dish : Memory::returnDishes()) {
				dish->increaseQuantity(10);
			}
		}

		else if (choice == 7) {
			int dishTypeChoice;
			std::string name;
			int price;
			int quantity;

			while (true) {
				dishTypeChoice = inputChoice(showPickDish);
				if (checkChoice(dishTypeChoice, 3, 0)) break;
			}
			if (dishTypeChoice == 0) continue;

			while (true) {
				std::cout << "\nВведіть назву: ";
				std::cin >> name;
				if (name.empty()) {
					std::cout << "\n[Назва не може бути порожньою!]";
				}
				else break;
			}
			while (true) {
				price = inputChoiceText("\nВведіть вартість: ");
				if (price < 0) {
					std::cout << "\n[Вартість не може бути негативною!]";
				}
				else break;
			}
			while (true) {
				quantity = inputChoiceText("\nВведіть кількість: ");
				if (quantity <= 0) {
					std::cout << "\n[Кількість не може бути негативною/нульовою!]";
				}
				else break;
			}
			if (dishTypeChoice == 1) {
				Memory::addDish(std::make_shared<HotDish>(name, price, quantity));
			}
			if (dishTypeChoice == 2) {
				Memory::addDish(std::make_shared<ColdDish>(name, price, quantity));
			}
			if (dishTypeChoice == 3) {
				Memory::addDish(std::make_shared<Beverage>(name, price, quantity));
			}
			std::cout << "\nСтворено: ";
			totalMade += Memory::getDish(Memory::getDishCount() - 1)->getQuantity();
			totalQuantity += Memory::getDish(Memory::getDishCount() - 1)->getQuantity();
			Memory::getDish(Memory::getDishCount() - 1)->printInfo();
		}

		else if (choice == 8) {
			int addChoice;

			while (true) {
				addChoice = inputChoice(showAddChoice);
				if (checkChoice(addChoice, 2, 0)) break;
			}
			if (addChoice == 0) continue;

			if (addChoice == 1) {
				std::string name;
				int money;
				while (true) {
					std::cout << "\nВведіть ПІБ: ";
					std::cin >> name;
					if (name.empty()) {
						std::cout << "\n[ПІБ не може бути порожнім!]";
					}
					else break;
				}
				while (true) {
					money = inputChoiceText("\nВведіть кількість грошей: ");
					if (money < 0) {
						std::cout << "\n[Кількість грошей не може бути негативною!]";
					}
					else break;
				}
				Memory::addVisitor(std::make_shared<Visitor>(name, money));
				std::cout << "\nДодано: ";
				Memory::getVisitor(Memory::getVisitorCount() - 1)->printInfo();
			}

			if (addChoice == 2) {
				std::string name;
				int chance;
				while (true) {
					std::cout << "\nВведіть ПІБ: ";
					std::cin >> name;
					if (name.empty()) {
						std::cout << "\n[ПІБ не може бути порожнім!]";
					}
					else break;
				}
				while (true) {
					chance = inputChoiceText("\nВведіть шанс порушення(0-100%): ");
					if (chance > 100 || chance < 0) {
						std::cout << "\n[Неможливий шанс!]";
					}
					else {
						chance /= 100;
						break;
					}
				}
				Memory::addSeller(std::make_shared<Seller>(name, chance));
				std::cout << "\nДодано: ";
				Memory::getSeller(Memory::getSellerCount() - 1)->printInfo();
			}
		}

		else if (choice == 9) {
			int delChoice;

			while (true) {
				delChoice = inputChoice(showDeleteChoice);
				if (checkChoice(delChoice, 2, 0)) break;
			}
			if (delChoice == 0) continue;

			if (delChoice == 1) {
				int visIndex;
				while (true) {
					visIndex = inputChoice(showPickVisitor);
					if (checkChoice(visIndex, Memory::getVisitorCount(), 0)) break;
				}
				if (visIndex == 0) continue;
				
				if (Memory::deleteVisitor(visIndex - 1)) {
					std::cout << "\nВидалено успішно!";
				}
				else std::cout << "[Помилка!]";
			}

			if (delChoice == 2) {
				int selIndex;
				while (true) {
					selIndex = inputChoice(showPickSeller);
					if (checkChoice(selIndex, Memory::getVisitorCount(), 0)) break;
				}
				if (selIndex == 0) continue;

				if (Memory::deleteSeller(selIndex - 1)) {
					std::cout << "\nВидалено успішно!";
				}
				else std::cout << "[Помилка!]";
			}			
		}

		else if (choice == 0) break;

		else {
			std::cout << "\n[Виберіть коректний варіант!]";
		}
	}
}