#include<bits/stdc++.h>
using namespace std;

string s;
int number[10];
string maxnumber = "";

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i=0; i<s.size(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            number[s[i]-'0']++;
            // cout <<s[i] << " " << int(s[i]-'0') << endl;
        }
    }

    for(int i=9; i>=0; i--){
        while(number[i] >= 1){
            maxnumber += char(i+'0');
            number[i]--;
        }
    }

    cout << maxnumber << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
