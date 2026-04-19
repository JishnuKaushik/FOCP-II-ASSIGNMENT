#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> spf(MAXN + 1);
    for (int i = 1; i <= MAXN; i++) spf[i] = i;
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int distinct = 0;
        while (n > 1) {
            int p = spf[n];
            distinct++;
            while (n % p == 0) n /= p;
        }

        cout << (1LL << distinct) << '\n';
    }
}