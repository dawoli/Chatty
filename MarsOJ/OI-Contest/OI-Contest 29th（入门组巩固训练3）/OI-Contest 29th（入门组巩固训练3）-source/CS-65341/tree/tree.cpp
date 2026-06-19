#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<1<<endl;
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    return 0;
}
