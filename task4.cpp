#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int count_words_in_file(const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cout << "Error: File not found." << endl;
        return 0;
    }

    int word_count = 0;
    string word;
    while (file >> word) {
        word_count++;
    }

    file.close();
    return word_count;
}

int main() {
    cout << "Word Count Program" << endl;
    string file_name;

    cout << "Enter the name of the text file: ";
    getline(cin, file_name);

    int total_words = count_words_in_file(file_name);
    cout << "Total word count in the file: " << total_words << endl;

    return 0;
}
