// Input.cpp
#include <iostream>
#include <limits>
#include "input.hpp"

bool getValidInput(double& x, double& y, double& z) {
    std::cout << "Enter coordinates (x y z): ";
    std::cin >> x >> y >> z;

    // Check if the input failed (non-numeric input)
    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter numeric values." << std::endl;
        // Clear the error flag
        std::cin.clear();
        // Ignore the rest of the input line to allow re-entry
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}
