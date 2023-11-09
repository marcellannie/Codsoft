#include <iostream>

int main() {
    double num1, num2, result;
    char operation;

    // Get user input
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "Choose operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the calculation
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return 1;  // Exit the program with an error code
            }
            break;
        default:
            std::cout << "Invalid operation. Please choose +, -, *, or /." << std::endl;
            return 1;  // Exit the program with an error code
    }

    // Display the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}

