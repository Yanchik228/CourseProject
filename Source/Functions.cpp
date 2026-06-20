#include "Functions.h"
#include <random>
#include <iostream>
#include <limits>

bool checkTruth(double probability) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    return dis(gen) < probability;
}

int inputChoice(std::function<void()> func) {
    int value;
    while (true) {
        func();
        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n[Введіть число!]";
        }
        else return value;
    }
}

int inputChoiceText(const std::string& text) {
    int value;
    while (true) {
        std::cout << text;
        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n[Введіть число!]";
        }
        else return value;
    }
}

bool checkChoice(int choice, size_t max, int min) {
    if (choice > max || choice < min) {
        std::cout << "\n[Виберіть можливий варіант!]";
        return false;
    }
    else return true;
}