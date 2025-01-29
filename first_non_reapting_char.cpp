#include <iostream>
#include <vector>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    vector<int> freq(26, 0); // Frequency array for lowercase letters

    // First pass: Count frequency of each character in the string
    for (char c : s) {
        freq[c - 'a']++; // Increment frequency
    }

    // Second pass: Find the first character with frequency 1
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i; // Return index of first unique character
        }
    }

    return -1; // If no unique character found
}

int main() {
    string s = "leetcode";
    int result = firstUniqChar(s);
    
    if (result != -1) {
        cout << "The first unique character is at index: " << result << endl;
    } else {
        cout << "No unique character found." << endl;
    }

    return 0;
}
