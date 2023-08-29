#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 256;

void preprocessShiftTable(const string& pattern, vector<int>& shiftTable) {
    int m = pattern.size();

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        shiftTable[i] = m;
    }

    for (int i = 0; i < m - 1; ++i) {
        shiftTable[pattern[i]] = m - 1 - i;
    }
}

int horspoolSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> shiftTable(ALPHABET_SIZE);
    preprocessShiftTable(pattern, shiftTable);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            ++k;
        }

        if (k == m) {
            return i - m + 1; // Pattern found at index i - m + 1
        } else {
            i += shiftTable[text[i]];
        }
    }

    return -1; // Pattern not found
}

int main() {
    string text = "This is a sample text for testing the Horspool algorithm.";
    string pattern = "Horspool";

    int position = horspoolSearch(text, pattern);

    if (position != -1) {
        cout << "Pattern found at position: " << position << endl;
    } else {
        cout << "Pattern not found." << endl;
    }

    return 0;
}
