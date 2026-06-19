#include <bits/stdc++.h>

using namespace std;

bool cmp(int x, int y){
    return x > y;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    vector<int> v;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            v.push_back(s[i] - '0');
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it;
    }
    cout << endl;

    fclose(stdin);
    fclose(stdout);
    return 0; 
}
