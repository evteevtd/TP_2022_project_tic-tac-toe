#include "console_functions.hpp"

void print(const std::vector<std::string>& strings) {
    for (auto str : strings) std::cout << str << std::endl;
}

int myStoi(const std::string& from) {
    int res = 0;
    try {
        res = std::stoi(from);
    } catch (std::invalid_argument&) {
        throw std::invalid_argument("some value is not an integer");
    } catch (std::out_of_range&) {
        throw std::invalid_argument("some value is out of range");
    }

    for (int i = 1; i < from.size(); ++i)
        if (from[i] < '0' || '9' < from[i])
            throw std::invalid_argument("some value is not an integer");
    
    return res;
}

std::vector<int> inputIntegers(int count, int from, int to, const std::string& on_error) {
    std::vector<int> result(count);

    while (true) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream input;
        input.str(line);

        try {
            std::string responce;
            for (int i = 0; i < count; ++i) { 
                if (!(input >> responce)) throw std::invalid_argument("too few arguments");
                result[i] = myStoi(responce);
                if (from <= result[i] && result[i] <= to) continue;
                throw std::invalid_argument("some value is out of range");
            }
            if (input >> responce) throw std::invalid_argument("too many arguments");
        } catch (std::invalid_argument& error) {
            print({error.what()});
            if (on_error != "") print({on_error});
            continue;
        }
        break;
    }

    return result;
}

int inputInteger(int from, int to, const std::string& on_error) {
    return inputIntegers(1, from, to, on_error)[0];
}
