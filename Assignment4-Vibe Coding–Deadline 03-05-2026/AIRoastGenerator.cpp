#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

// Trim spaces from both ends
string trim(const string& str) {
    string result = str;

    result.erase(result.begin(), find_if(result.begin(), result.end(),
        [](unsigned char ch) { return !isspace(ch); }));

    result.erase(find_if(result.rbegin(), result.rend(),
        [](unsigned char ch) { return !isspace(ch); }).base(), result.end());

    return result;
}

// Replace ALL occurrences of {name}
string personalizeRoast(string roast, const string& name) {
    size_t pos = 0;
    while ((pos = roast.find("{name}", pos)) != string::npos) {
        roast.replace(pos, 6, name);
        pos += name.length();
    }
    return roast;
}

// Random roast selector
string getRandomRoast(const vector<string>& roasts) {
    return roasts[rand() % roasts.size()];
}

int main() {
    srand(time(0)); // seed randomness

    vector<string> roasts = {
        // Coding (10)
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

        // Student Life (10)
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

        // General (10)
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

    cout << "🤖 Desi Roast Bot activated!\n";
    cout << "Apna naam bata bhai: ";
    getline(cin, name);

    name = trim(name);

    // Empty input check
    if (name.empty()) {
        cout << "Naam toh daal deta bhai... system mind reader nahi hai 😑\n";
        return 0;
    }

    cout << "\nAcha " << name << ", ready ho roast ke liye? 😏\n";

    string input;

    while (true) {
        cout << "\nType 'roast' for burn 🔥, 'exit' to leave: ";
        getline(cin, input);

        input = trim(input);

        if (input == "exit") {
            cout << "\nTheek hai " << name << ", ja ab coding practice kar 😄\n";
            break;
        }
        else if (input == "roast") {
            string roast = getRandomRoast(roasts);
            cout << "\n🔥 " << personalizeRoast(roast, name) << "\n";
        }
        else if (input.empty()) {
            cout << "Kuch toh likh bhai... hawa nahi padh sakta main 😒\n";
        }
        else {
            cout << "Samajh nahi aaya 😵‍💫. Sirf 'roast' ya 'exit' likh.\n";
        }
    }

    return 0;
}