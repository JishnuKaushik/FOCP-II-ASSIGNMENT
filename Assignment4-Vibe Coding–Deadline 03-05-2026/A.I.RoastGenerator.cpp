#include <iostream>   // For input and output
#include <vector>     // For using vector (dynamic array)
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time() function
#include <string>     // For string handling

using namespace std;

// Function to replace "{name}" in the roast with actual user name
string personalizeRoast(string roast, string name) {
    size_t pos = roast.find("{name}"); // Find position of placeholder

    // If placeholder exists, replace it
    if (pos != string::npos) {
        roast.replace(pos, 6, name); // 6 = length of "{name}"
    }

    return roast;
}

int main() {
    string name;

    // Ask user for input
    cout << "Enter your name: ";
    getline(cin, name); // getline handles full names with spaces

    // Edge case: empty input
    if (name.empty()) {
        cout << "Name cannot be empty. Please run the program again.\n";
        return 0; // Exit program
    }

    // Seed random number generator using current time
    srand(time(0));

    // Vector storing roast templates
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

    // Generate random index
    int randomIndex = rand() % roasts.size();

    // Get selected roast
    string selectedRoast = roasts[randomIndex];

    // Replace placeholder with actual name
    string finalRoast = personalizeRoast(selectedRoast, name);

    // Output result
    cout << "\n🔥 Roast for you:\n";
    cout << finalRoast << endl;

    return 0;
}