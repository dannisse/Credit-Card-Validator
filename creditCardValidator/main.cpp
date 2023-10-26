#include <iostream>
#include <string>
#include <algorithm>

// Function to check if a credit card number is valid using the Luhn algorithm
bool isLuhnValid(const std::string& cardNumber) {
    int sum = 0;
    bool alternate = false; // Used to indicate whether the current digit should be doubled

    // Start from the rightmost digit (the check digit) and move left
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int num = cardNumber[i] - '0'; // Convert the character digit to an integer

        if (alternate) {
            num *= 2; // Double every other digit
            if (num > 9) {
                num -= 9; // If the doubling results in a two-digit number, subtract 9
            }
        }

        sum += num; // Add the digit (or the doubled value) to the sum
        alternate = !alternate; // Toggle the alternate flag
    }

    // If the sum is a multiple of 10, the credit card number is valid
    return (sum % 10 == 0);
}

int main() {
    std::string cardNumber;
    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    if (isLuhnValid(cardNumber)) {
        std::cout << "Valid credit card number.\n";
    } else {
        std::cout << "Invalid credit card number.\n";
    }

    return 0;
}

