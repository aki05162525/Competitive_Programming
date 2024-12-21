#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

struct HouseX {
    ll x;
    ll y;
    int id;
};

struct HouseY {
    ll y;
    ll x;
    int id;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 入力読み取り
    int N, M;
    ll Sx, Sy;
    cin >> N >> M >> Sx >> Sy;
    
    // 家の座標を読み取り
    vector<pair<ll, ll>> houses(N);
    for(int i = 0; i < N; i++) cin >> houses[i].first >> houses[i].second;
    
    // ソート用リストの準備
    vector<HouseX> sorted_by_x(N);
    vector<HouseY> sorted_by_y(N);
    for(int i = 0; i < N; i++){
        sorted_by_x[i] = HouseX{houses[i].first, houses[i].second, i};
        sorted_by_y[i] = HouseY{houses[i].second, houses[i].first, i};
    }
    
    // x座標順、y座標順にソート
    sort(sorted_by_x.begin(), sorted_by_x.end(), [&](const HouseX &a, const HouseX &b) -> bool{
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    
    sort(sorted_by_y.begin(), sorted_by_y.end(), [&](const HouseY &a, const HouseY &b) -> bool{
        if(a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });
    
    // 通過した家を記録する配列
    vector<char> passed(N, 0);
    ll C = 0;
    
    // 現在位置
    ll cur_x = Sx, cur_y = Sy;
    
    // 各移動を処理
    for(int i = 0; i < M; i++){
        char D;
        ll C_i;
        cin >> D >> C_i;
        
        ll new_x = cur_x, new_y = cur_y;
        if(D == 'U') new_y += C_i;
        else if(D == 'D') new_y -= C_i;
        else if(D == 'L') new_x -= C_i;
        else if(D == 'R') new_x += C_i;
        
        // 移動が垂直か水平かを判定
        if(D == 'U' || D == 'D'){

            ll fixed_x = cur_x;
            ll min_y = min(cur_y, new_y);
            ll max_y = max(cur_y, new_y);
            
            HouseX key_low = HouseX{fixed_x, min_y, -1};
            auto it_low = lower_bound(sorted_by_x.begin(), sorted_by_x.end(), key_low, [&](const HouseX &a, const HouseX &b) -> bool{
                if(a.x != b.x) return a.x < b.x;
                return a.y < b.y;
            });
            
            HouseX key_up = HouseX{fixed_x, max_y, INT32_MAX};
            auto it_up = upper_bound(sorted_by_x.begin(), sorted_by_x.end(), key_up, [&](const HouseX &a, const HouseX &b) -> bool{
                if(a.x != b.x) return a.x < b.x;
                return a.y < b.y;
            });
            
            for(auto it = it_low; it != it_up; it++){
                int house_id = it->id;
                if(!passed[house_id]){
                    passed[house_id] = 1;
                    C++;
                }
            }
        }
        else{

            ll fixed_y = cur_y;
            ll min_x = min(cur_x, new_x);
            ll max_x = max(cur_x, new_x);
            
            HouseY key_low = HouseY{fixed_y, min_x, -1};
            auto it_low = lower_bound(sorted_by_y.begin(), sorted_by_y.end(), key_low, [&](const HouseY &a, const HouseY &b) -> bool{
                if(a.y != b.y) return a.y < b.y;
                return a.x < b.x;
            });
            HouseY key_up = HouseY{fixed_y, max_x, INT32_MAX};
            auto it_up = upper_bound(sorted_by_y.begin(), sorted_by_y.end(), key_up, [&](const HouseY &a, const HouseY &b) -> bool{
                if(a.y != b.y) return a.y < b.y;
                return a.x < b.x;
            });
            for(auto it = it_low; it != it_up; it++){
                int house_id = it->id;
                if(!passed[house_id]){
                    passed[house_id] = 1;
                    C++;
                }
            }
        }
        cur_x = new_x;
        cur_y = new_y;
    }
    
    cout << cur_x << " " << cur_y << " " << C << "\n";
}
