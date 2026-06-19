#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+1+n);
    int j=1;
    for(int i=1;i<=n;i++){
        if(a[i]>a[j]){
            ++j;
        }
    }

    cout << n-j+1 << '\n';

    return 0;
}
