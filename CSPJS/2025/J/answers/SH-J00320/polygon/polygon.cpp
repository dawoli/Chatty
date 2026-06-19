#include <bits/stdc++.h>

using namespace std;

const int MOD=998244353;

int n;
int a[5005];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int sum=0;
    int m=INT_MIN;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=i[a];
        m=max(m,i[a]);
    }
    if(n==3){
        if(sum>m*2){
            cout<<1;
        }else
            cout<<0;
    }
    cout<<endl;
    return 0;
}
