#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    cin >> L >> R;

    long long x = f(R) ^ f(L - 1);

    if (x % 2 == 0) cout << "even";
    else cout << "odd";
}