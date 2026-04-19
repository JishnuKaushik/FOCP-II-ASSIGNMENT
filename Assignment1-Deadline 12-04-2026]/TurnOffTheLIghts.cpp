#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

bool can(int len) {
    int ops = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == '1') {
            ops++;
            if (ops > k) return false;
            i += len;
        } else {
            i++;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> s;

    int low = 1, high = n, ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (can(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
}