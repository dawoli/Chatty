#include<bits/stdc++.h>
using namespace std;
string a;
int n;
int x[29];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    n=a.length();
    for(int i=0;i<n;i++){
        if(a[i]>='0'&&a[i]<='9')x[a[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(x[i]--){
            cout<<i;
        }
    }
    return 0;
}