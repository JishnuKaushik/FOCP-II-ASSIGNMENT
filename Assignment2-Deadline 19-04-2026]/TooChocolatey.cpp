#include <bits/stdc++.h>
using namespace std;
const int MAXX = 1e3 + 5;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(MAXX, 0);  
        int toida = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > toida) toida = a[i];  
        }
 
        int alex = 0, bob = 0;
        bool alexTurn = true;
        for (int i = 0; i < n; i++) {
            b[a[i]]++;
        }
        for (int i = toida; i >= 0; i--) {
            if (b[i] == 1) {  
                if (alexTurn) {
                    alex += i;
                } else {
                    bob += i;
                }
                alexTurn = !alexTurn; 
            } else if (b[i] >= 2) { 
                alex += i;
                bob += i;
            }
        }
        if (alex > bob) {
            cout << "Alex" << endl;
        } 
        else {
            cout << "Bob" << endl;
        } 
    }
}