#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    map<int, int> cnt;
    cnt[A]++;
    cnt[B]++;
    cnt[C]++;
    cnt[D]++;

    for (int i = 1; i <= 13; i++) {
        map<int, int> tmp = cnt;  
        tmp[i]++;                 
        int two = 0, three = 0;
        for (auto p : tmp) {
            if (p.second == 2) two++;
            if (p.second == 3) three++;
        }

        if (two == 1 && three == 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}