#include <iostream>
#include <vector>
#include <string>

void generateCombinations(const std::string& input, std::vector<std::string>& combinations, int minLength = 2, std::string current = "", int index = 0) {
    if (current.length() >= minLength) {
        combinations.push_back(current);
    }

    for (int i = index; i < input.length(); ++i) {
        current.push_back(input[i]);
        generateCombinations(input, combinations, minLength, current, i + 1);
        current.pop_back();
    }
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::vector<std::string> combinations;
    generateCombinations(input, combinations);

    std::cout << "All possible combinations with a minimum length of 2:\n";
    for (const std::string& combination : combinations) {
        std::cout << combination << std::endl;
    }

    return 0;
}
