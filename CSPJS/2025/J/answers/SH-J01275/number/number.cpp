#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int cnt=0;
    for(char x:s){
        if(isdigit(x)){
            a[++cnt]=x;
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--){
        cout << a[i];
    }
}
