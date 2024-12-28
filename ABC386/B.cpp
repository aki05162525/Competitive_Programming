#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    int count = 0;//ボタンを押した回数
    int n = S.size(); //Sの長さをnに格納

    for (int i = 0; i < n; i++){
        //今の文字が０で次に文字も０のとき
        if (S[i] == '0' && i + 1 < n && S[i + 1] == '0'){
            count++;//00 を一回としてカウント
            i++;//文字をスキップ
        }else{
            count++;
        }
    }
    
    cout << count << endl;
    return 0;


}