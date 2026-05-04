#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

// Trim spaces from both ends
string trim(const string& str) {
    string s = str;

    s.erase(s.begin(), find_if(s.begin(), s.end(),
        [](unsigned char ch) { return !isspace(ch); }));

    s.erase(find_if(s.rbegin(), s.rend(),
        [](unsigned char ch) { return !isspace(ch); }).base(), s.end());

    return s;
}

// Replace ALL occurrences of {name}
string personalize(string text, const string& name) {
    size_t pos = 0;
    while ((pos = text.find("{name}", pos)) != string::npos) {
        text.replace(pos, 6, name);
        pos += name.length();
    }
    return text;
}

// Get random roast
string getRandom(const vector<string>& roasts) {
    return roasts[rand() % roasts.size()];
}

int main() {
    srand((unsigned)time(0));

    vector<string> roasts = {
        "{name}, tera code compile hone se pehle hi give up kar deta hai.",
        "{name}, tu bug fix nahi karta, naye bugs introduce karta hai.",
        "{name}, tera logic dekh ke compiler bhi confused hai.",
        "{name}, tu debugging nahi karta, bas guesswork karta hai.",
        "{name}, tera code emotions se bhi zyada unstable hai.",
        "{name}, tu syntax errors ko feature bolta hai kya?",
        "{name}, tera program run nahi hota, struggle karta hai.",
        "{name}, tu Stack Overflow ka permanent member lagta hai.",
        "{name}, tera code crash nahi karta, dramatic exit leta hai.",
        "{name}, tu variables declare karta hai ya lottery numbers?",
        "{name}, attendance kam hai, excuses unlimited hain.",
        "{name}, tu assignment last night ka legend hai.",
        "{name}, tera study plan sirf plan hi reh jata hai.",
        "{name}, tu class me aata hai ya bas rumours hain?",
        "{name}, exam ke time hi tujhe padhai yaad aati hai.",
        "{name}, tu notes nahi banata, bas borrow karta hai.",
        "{name}, tera focus WiFi signal se bhi weak hai.",
        "{name}, tu padhai se zyada breaks leta hai.",
        "{name}, tera motivation Monday morning jaisa hai.",
        "{name}, tu syllabus dekh ke hi thak jata hai.",
        "{name}, tu serious kab hota hai, ya ye bhi bug hai?",
        "{name}, tera confidence reality ko confuse karta hai.",
        "{name}, tu try karta hai, system mana kar deta hai.",
        "{name}, tu plan banata hai, execution missing rehta hai.",
        "{name}, tu itna chill hai ki progress freeze ho gayi.",
        "{name}, tera timing hamesha galat hi hota hai.",
        "{name}, tu effort deta hai ya sirf intention?",
        "{name}, tu strong start karta hai, finish missing hoti hai.",
        "{name}, tera luck bhi tujhe ignore karta hai.",
        "{name}, tu simple kaam ko bhi side quest bana deta hai."
    };

    string name;
    cout << "Desi Roast Bot activated!\n";
    cout << "Enter your name: ";
    getline(cin, name);

    name = trim(name);

    if (name.empty()) {
        cout << "Name cannot be empty. Exiting.\n";
        return 0;
    }

    cout << "\nAlright " << name << ", ready for some roasting?\n";

    string input;

    while (true) {
        cout << "\nType 'roast' for a roast, or 'exit' to quit: ";
        getline(cin, input);

        input = trim(input);

        if (input == "exit") {
            cout << "\nOkay " << name << ", exiting now. Practice coding.\n";
            break;
        }
        else if (input == "roast") {
            string r = getRandom(roasts);
            cout << "\n" << personalize(r, name) << "\n";
        }
        else if (input.empty()) {
            cout << "Please enter something.\n";
        }
        else {
            cout << "Invalid input. Type 'roast' or 'exit'.\n";
        }
    }

    return 0;
}