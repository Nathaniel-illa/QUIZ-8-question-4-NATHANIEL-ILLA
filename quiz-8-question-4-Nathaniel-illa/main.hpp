#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXNUM = 10;   // Maximum number of words
const int MAXLEN = 100;  // Maximum length of each word

int splitline(string txt, char delimiter, char target[][MAXLEN]) {
    int cnt = 0; // Count of split words
    size_t start = 0; // Start index for substring extraction
    size_t end = txt.find(delimiter);

    while (end != string::npos) {
        if (cnt < MAXNUM) {
            string word = txt.substr(start, end - start);
            strncpy(target[cnt], word.c_str(), MAXLEN);
            target[cnt][MAXLEN - 1] = '\0'; // Ensure null-termination
            cnt++;
        }
        start = end + 1; // Move past the delimiter
        end = txt.find(delimiter, start); // Find next delimiter
    }

    // Handle the last word after the final delimiter
    if (cnt < MAXNUM) {
        string word = txt.substr(start);
        strncpy(target[cnt], word.c_str(), MAXLEN);
        target[cnt][MAXLEN - 1] = '\0'; // Ensure null-termination
        cnt++;
    }

    return cnt; // Return the count of split words
}