#pragma once
#include <string>
#include <functional>

bool checkTruth(double probability);

int inputChoice(std::function<void()> func);

int inputChoiceText(const std::string& text);

bool checkChoice(int choice, size_t max, int min);

void wait(int ms);