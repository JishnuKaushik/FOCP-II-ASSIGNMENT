#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<long long, long long> acc;

public:
    string create(long long x, long long y) {
        if (acc.count(x)) {
            acc[x] += y;
            return "false";
        }
        acc[x] = y;
        return "true";
    }

    string debit(long long x, long long y) {
        if (!acc.count(x) || acc[x] < y) return "false";
        acc[x] -= y;
        return "true";
    }

    string credit(long long x, long long y) {
        if (!acc.count(x)) return "false";
        acc[x] += y;
        return "true";
    }

    long long balance(long long x) {
        if (!acc.count(x)) return -1;
        return acc[x];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string op;
        cin >> op;

        if (op == "CREATE") {
            long long x, y;
            cin >> x >> y;
            cout << bank.create(x, y) << '\n';
        }
        else if (op == "DEBIT") {
            long long x, y;
            cin >> x >> y;
            cout << bank.debit(x, y) << '\n';
        }
        else if (op == "CREDIT") {
            long long x, y;
            cin >> x >> y;
            cout << bank.credit(x, y) << '\n';
        }
        else if (op == "BALANCE") {
            long long x;
            cin >> x;
            cout << bank.balance(x) << '\n';
        }
    }
}