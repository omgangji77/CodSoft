#include <iostream>
using namespace std;

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

float divide(int x, int y) {
    if (y == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0.0;
    }
    return static_cast<float>(x) / y;
}

int main() {
    int num1, num2;
    char choice;

    cout << "Welcome to the Basic Calculator!" << endl;
    while (true) {
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Select operation:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1/2/3/4/5): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case '2':
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case '3':
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case '4':
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            case '5':
                cout << "Exiting the calculator. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
