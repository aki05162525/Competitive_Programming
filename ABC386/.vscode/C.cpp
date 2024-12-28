#include <bits/stdc++.h>
using namespace std;

bool itimozihenkou(const string & S, const string& T){
    if(S.size() != T.size()) return false; //長さが違うときはできない

    int diff_count = 0;//異なる文字の数を数える
    for(int i = 0; i < S.size(); i++){
        if(S[i] != T[i]) diff_count++;
    }

    return diff_count == 1;//1個だけならできるよ！
}


bool itimozituika(const string &S, const string &T) {
    if (S.size() + 1 != T.size()) return false; // TはSより1文字だけ長いはず

    int i = 0, j = 0;
    bool skipped = false;

    while (i < S.size() && j < T.size()) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else if (!skipped) {
            // 1文字追加として処理
            skipped = true;
            j++;
        } else {
            return false; // 2回以上違いがあればNG
        }
    }

    // 追加された文字が最後の場合
    return true;
}

bool itimozisakujo(const string &S, const string &T) {
    if (S.size() - 1 != T.size()) return false; // SはTより1文字だけ長いはず

    int i = 0, j = 0;
    bool skipped = false;

    while (i < S.size() && j < T.size()) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else if (!skipped) {
            // 1文字削除として処理
            skipped = true;
            i++;
        } else {
            return false; // 2回以上違いがあればNG
        }
    }

    // 削除された文字が最後の場合
    return true;
}

int main() {
    int K;
    string S, T;
    cin >> K >> S >> T;

    // 1回の操作で一致可能か確認
    if (S == T || itimozihenkou(S, T) || itimozituika(S, T) || itimozisakujo(S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
