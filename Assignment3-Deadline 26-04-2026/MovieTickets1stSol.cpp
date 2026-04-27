#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    unordered_map<int, unordered_set<int>> booked;
    unordered_map<int, int> used;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "BOOK") {
            int x, y;
            cin >> x >> y;

            if (booked[y].count(x) || used[y] == 100) {
                cout << "false\n";
            } else {
                booked[y].insert(x);
                used[y]++;
                cout << "true\n";
            }
        }
        else if (op == "CANCEL") {
            int x, y;
            cin >> x >> y;

            if (!booked[y].count(x)) {
                cout << "false\n";
            } else {
                booked[y].erase(x);
                used[y]--;
                cout << "true\n";
            }
        }
        else if (op == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;

            if (booked[y].count(x)) cout << "true\n";
            else cout << "false\n";
        }
        else if (op == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;

            cout << (100 - used[y]) << '\n';
        }
    }
}