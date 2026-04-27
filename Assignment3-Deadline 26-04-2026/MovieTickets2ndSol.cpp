#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
    unordered_map<int, unordered_set<int>> booked;
    unordered_map<int, int> used;

public:
    string book(int x, int y) {
        if (booked[y].count(x) || used[y] == 100) return "false";
        booked[y].insert(x);
        used[y]++;
        return "true";
    }

    string cancel(int x, int y) {
        if (!booked[y].count(x)) return "false";
        booked[y].erase(x);
        used[y]--;
        return "true";
    }

    string isBooked(int x, int y) {
        if (booked[y].count(x)) return "true";
        return "false";
    }

    int availableTickets(int y) {
        return 100 - used[y];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << mt.book(x, y) << '\n';
        }
        else if (op == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << mt.cancel(x, y) << '\n';
        }
        else if (op == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << mt.isBooked(x, y) << '\n';
        }
        else if (op == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.availableTickets(y) << '\n';
        }
    }
}