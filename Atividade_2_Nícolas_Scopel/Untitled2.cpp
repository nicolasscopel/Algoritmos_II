#include <iostream>
#include <stack>
#include <cctype>

bool isPalindrome(const std::string &str) {
    std::stack<char> charStack;

    for (char c : str) {
        if (std::isalpha(c)) {
            charStack.push(std::tolower(c));
        }
    }

    for (char c : str) {
        if (std::isalpha(c)) {
            if (charStack.empty() || charStack.top() != std::tolower(c)) {
                return false;
            }
            charStack.pop();
        }
    }

    return true;
}

int main() {
    std::string input;
    std::cout << "Digite uma string: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "A string é um palíndromo." << std::endl;
    } else {
        std::cout << "A string não é um palíndromo." << std::endl;
    }

    return 0;
}
