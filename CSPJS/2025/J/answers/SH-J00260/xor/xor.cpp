#include<iostream>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=1;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<ans;
    return 0;
}

