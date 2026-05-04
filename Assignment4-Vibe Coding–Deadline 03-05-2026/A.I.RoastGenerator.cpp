#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm> // for remove_if

using namespace std;

// Function to trim spaces from input
string trim(const string& str) {
    string result = str;

    // Remove leading spaces
    result.erase(result.begin(), find_if(result.begin(), result.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));

    // Remove trailing spaces
    result.erase(find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), result.end());

    return result;
}

// Function to replace ALL occurrences of {name}
string personalizeRoast(string roast, const string& name) {
    size_t pos = 0;

    while ((pos = roast.find("{name}", pos)) != string::npos) {
        roast.replace(pos, 6, name);
        pos += name.length(); // move forward
    }

    return roast;
}

// Function to get random roast
string getRandomRoast(const vector<string>& roasts) {
    int index = rand() % roasts.size();
    return roasts[index];
}

int main() {
    srand(time(0)); // seed once

    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "{name}'s code has more bugs than a jungle.",
        "{name} debugs by deleting the whole project.",
        "{name} writes comments like they are writing a mystery novel.",
        "{name}'s code works... but nobody knows why.",
        "{name} uses Google more than their own brain.",
        "{name}'s logic is so confusing even the compiler gets scared.",
        "{name} writes code that even Stack Overflow refuses to answer.",
        "{name}'s programs crash faster than they run.",
        "{name} thinks semicolons are optional."
    };

    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // Trim spaces
    name = trim(name);

    // Edge case check
    if (name.empty()) {
        cout << "Name cannot be empty. Exiting...\n";
        return 0;
    }

    char choice;

    do {
        // Get random roast
        string roast = getRandomRoast(roasts);

        // Personalize
        string finalRoast = personalizeRoast(roast, name);

        cout << "\n🔥 Roast:\n" << finalRoast << endl;

        // Ask if user wants another roast
        cout << "\nWant another roast? (y/n): ";
        cin >> choice;

        cin.ignore(); // clear buffer

    } while (choice == 'y' || choice == 'Y');

    cout << "\nAlright, exiting. Stay roasted 😄\n";

    return 0;
}