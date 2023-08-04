#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const int PRICE_PER_TICKET = 10;

vector<vector<bool>> seatAvailability(NUM_ROWS, vector<bool>(NUM_COLS, true));

void displaySeats() {
    cout << "----------------------------------------" << endl;
    cout << "          Screen" << endl;
    cout << "----------------------------------------" << endl;
    cout << "   ";
    for (int col = 0; col < NUM_COLS; col++) {
        cout << setw(3) << col + 1;
    }
    cout << endl;
    for (int row = 0; row < NUM_ROWS; row++) {
        cout << setw(2) << row + 1 << " ";
        for (int col = 0; col < NUM_COLS; col++) {
            if (seatAvailability[row][col]) {
                cout << "  o";
            } else {
                cout << "  x";
            }
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
}

bool isValidSeat(int row, int col) {
    return row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS;
}

bool isSeatAvailable(int row, int col) {
    return seatAvailability[row][col];
}

void bookSeat(int row, int col) {
    seatAvailability[row][col] = false;
}

int main() {
    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. View Movie Listings" << endl;
        cout << "2. Book a Ticket" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nMovie Listings:" << endl;
                // Display available movie listings here
                break;
            case 2:
                int row, col;
                displaySeats();
                cout << "Enter row number (1-5) and column number (1-10) for seat selection: ";
                cin >> row >> col;
                row--; // Adjust to 0-indexing
                col--;

                if (isValidSeat(row, col)) {
                    if (isSeatAvailable(row, col)) {
                        bookSeat(row, col);
                        cout << "Seat booked successfully!" << endl;
                        cout << "Total cost: $" << PRICE_PER_TICKET << endl;
                    } else {
                        cout << "Seat is already booked. Please choose another seat." << endl;
                    }
                } else {
                    cout << "Invalid seat selection. Please choose a valid seat." << endl;
                }
                break;
            case 3:
                cout << "Thank you for using the Movie Ticket Booking System. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
