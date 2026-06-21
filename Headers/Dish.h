#pragma once
#include <string>

class Dish {
	std::string name;
	int price;
	int quantity;
	int tempSold;

public:
	Dish();
	Dish(const std::string& name, int price, int quantity);

	std::string getName() const;
	int getPrice() const;
	int getQuantity() const;
	int getTempSold() const;

	void increaseQuantity(int increase);
	void increaseTempSold(int increase);
	void resetTempSold();

	virtual std::string getType() const = 0;

	void printInfo() const;

	virtual ~Dish() = default;
};

class HotDish : public Dish {
public:
	HotDish(const std::string& name, int price, int quantity);

	std::string getType() const override;
};

class ColdDish : public Dish {
public:
	ColdDish(const std::string& name, int price, int quantity);
	
	std::string getType() const override;
};

class Beverage : public Dish {
public:
	Beverage(const std::string& name, int price, int quantity);

	std::string getType() const override;
};