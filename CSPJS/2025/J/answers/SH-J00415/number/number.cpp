#include <bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int n = 0;
    for(int i = 0;i < s.size();i++){
        if((s[i]>='1' && s[i]<='9') || s[i] == '0'){
            a[n] = s[i]-'0';
            n++;
        }
    }
    sort(a,a+n);
    for(int i = n-1;i >= 0;i--){
        cout << a[i];
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
