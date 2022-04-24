#pragma once

#include <limits.h>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

void print(const std::vector<std::string>& strings);

int my_stoi(const std::string& from);

std::vector<int> inputIntegers(int count, int from, int to, const std::string& on_error = "try again");

int inputInteger(int from, int to, const std::string& on_error = "try again");
