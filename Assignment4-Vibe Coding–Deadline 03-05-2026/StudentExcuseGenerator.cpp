#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to replace ALL occurrences of {name} with actual name
string personalizeExcuse(string excuse, const string& name) {
    size_t pos = 0;

    while ((pos = excuse.find("{name}", pos)) != string::npos) {
        excuse.replace(pos, 6, name); // 6 = length of "{name}"
        pos += name.length(); // move forward
    }

    return excuse;
}

// Function to get a random excuse from vector
string getRandomExcuse(const vector<string>& excuses) {
    int index = rand() % excuses.size();
    return excuses[index];
}

int main() {
    // Seed random number generator
    srand(time(0));

    string name;

    // Take input using getline
    cout << "Enter your name: ";
    getline(cin, name);

    // Check for empty input
    if (name.empty()) {
        cout << "Name cannot be empty. Please run the program again.\n";
        return 0;
    }

    // Store excuse templates
    vector<string> excuses = {
        "{name} couldn't finish the assignment because the laptop started updating for hours.",
        "{name} was about to submit the homework when the Wi-Fi suddenly stopped working.",
        "{name} tried completing the assignment, but the file mysteriously got deleted.",
        "{name} couldn't finish because the system froze right before saving the work.",
        "{name} was working on the assignment when the power cut happened unexpectedly.",
        "{name} tried finishing the homework, but the keyboard stopped responding.",
        "{name} completed everything, but the file got corrupted at the last moment.",
        "{name} couldn't complete the assignment because the internet speed dropped to zero.",
        "{name} was about to finish when the software crashed without warning.",
        "{name} tried to complete the homework, but accidentally closed everything without saving.",
        "{name} was ready to submit, but the upload failed again and again.",
        "{name} couldn't complete the task because the laptop battery died suddenly."
    };

    // Get random excuse
    string selectedExcuse = getRandomExcuse(excuses);

    // Replace placeholder with actual name
    string finalExcuse = personalizeExcuse(selectedExcuse, name);

    // Display result
    cout << "\nGenerated Excuse:\n";
    cout << finalExcuse << endl;

    return 0;
}