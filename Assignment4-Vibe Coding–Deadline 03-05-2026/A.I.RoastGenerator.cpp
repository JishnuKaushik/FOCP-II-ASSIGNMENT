#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

// Trim spaces from input
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

// Get random roast
string getRandomRoast(const vector<string>& roasts) {
    return roasts[rand() % roasts.size()];
}

int main() {
    srand(time(0));

    vector<string> roasts = {
        "{name} ka code dekh ke compiler bhi bolta hai: bhai mujhe maaf kar de.",
        "{name}, tu code likhta kam hai, Stack Overflow zyada scroll karta hai.",
        "{name} ka logic itna confusing hai ki debugger bhi resign kar gaya.",
        "{name} ke bugs itne zyada hain ki unpe National Geographic documentary ban sakti hai.",
        "{name}, tera code run hone se pehle hi crash ho jata hai... respect.",
        "{name} likhta kuch aur hai, output aata kuch aur hai. Magic chal raha hai kya?",
        "{name} ka coding speed dekh ke turtle ne bhi upgrade le liya.",
        "{name}, tu semicolon ko optional maanta hai kya?",
        "{name} ka code samajhne ke liye NASA se training leni padegi.",
        "{name}, tu programmer kam, bug generator zyada lagta hai.",
        "Sach bata {name}, tu code likhta hai ya random keys daba deta hai?",
        "{name}, tera code dekh ke lagta hai Ctrl+C aur Ctrl+V hi tera asli skill hai.",
        "{name}, agar coding ek sport hota, tu bench pe bhi select nahi hota.",
        "{name}, tera code itna slow hai ki loading screen bhi bore ho jaati hai.",
        "{name}, tu coding karta hai ya system ko torture karta hai?"
    };

    string name;

    cout << "🤖 Desi Roast Bot activated!\n";
    cout << "Apna naam bata bhai: ";
    getline(cin, name);

    name = trim(name);

    if (name.empty()) {
        cout << "Naam toh daal deta bhai... system thodi mind reader hai 😑\n";
        return 0;
    }

    cout << "\nAcha " << name << ", ready ho thoda roast ke liye? 😏\n";

    string input;

    while (true) {
        cout << "\nType 'roast' for burn 🔥, 'exit' to leave: ";
        getline(cin, input);

        input = trim(input);

        if (input == "exit") {
            cout << "\nTheek hai " << name << ", aaj ke liye itna hi. Practice kar coding 😄\n";
            break;
        }
        else if (input == "roast") {
            string roast = getRandomRoast(roasts);
            cout << "\n🔥 " << personalizeRoast(roast, name) << "\n";
        }
        else if (input.empty()) {
            cout << "Kuch toh type kar bhai... hawa nahi padh sakta main 😒\n";
        }
        else {
            cout << "Samajh nahi aaya 😵‍💫. Sirf 'roast' ya 'exit' likh.\n";
        }
    }

    return 0;
}