#pragma once
#include <memory>
#include <vector>
#include "Visitor.h"
#include "Seller.h"
#include "Inspector.h"
#include "Dish.h"

class Memory {
	static std::vector<std::shared_ptr<Visitor>> visitors;
	static std::vector<std::shared_ptr<Seller>> sellers;
	static std::vector<std::shared_ptr<Dish>> dishes;

	static std::shared_ptr<Visitor> selectedVisitor;
	static std::shared_ptr<Seller> selectedSeller;

public:
	Memory() = delete;

	static void addVisitor(const std::shared_ptr<Visitor>& visitor);
	static bool deleteVisitor(size_t index);
	static std::shared_ptr<Visitor> getVisitor(size_t index);

	static void addSeller(const std::shared_ptr<Seller>& seller);
	static bool deleteSeller(size_t index);
	static std::shared_ptr<Seller> getSeller(size_t index);

	static void addDish(const std::shared_ptr<Dish>& dish);
	static bool deleteDish(size_t index);
	static std::shared_ptr<Dish> getDish(size_t index);

	static size_t getVisitorCount();
	static size_t getSellerCount();
	static size_t getDishCount();

	static void selectVisitor(size_t index);
	static std::shared_ptr<Visitor> getSelectedVisitor();

	static void selectSeller(size_t index);
	static void nullSeller();
	static std::shared_ptr<Seller> getSelectedSeller();

	static std::vector<std::shared_ptr<Dish>> returnDishes();
	static std::vector<std::shared_ptr<Seller>> returnSellers();
};