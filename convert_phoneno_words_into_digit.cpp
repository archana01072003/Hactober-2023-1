#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> wordToDigit = {
    {"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"},
    {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
};

string convertPhoneNumberToDigits(const string& phoneNumberInWords) {
    istringstream iss(phoneNumberInWords);
    string word, previousWord;
    string result = "";

    while (iss >> word) {
        if (word == "double" || word == "triple") {
            previousWord = word;
        } else {
            if (previousWord == "double") {
                for (int i = 0; i < 2; i++) {
                    result += wordToDigit[word];
                }
                previousWord = "";
            } else if (previousWord == "triple") {
                for (int i = 0; i < 3; i++) {
                    result += wordToDigit[word];
                }
                previousWord = "";
            } else {
                result += wordToDigit[word];
            }
        }
    }

    return result;
}

int main() {
    string input= "five one zero two four eight zero double three two";
    // cout << "Enter the phone number in words: ";
    // getline(cin, input);

    string result = convertPhoneNumberToDigits(input);
    cout << "Phone number in digits: " << result << endl;

    return 0;
}
