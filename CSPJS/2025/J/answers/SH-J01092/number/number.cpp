#include <bits/stdc++.h>
using namespace std;
int a[1000005],cnt;
bool cmp(int b,int c){
    return b > c;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cnt++;
            a[cnt] = s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i = 1; i <= cnt; i++){
        cout << a[i];
    }
    return 0;
}
