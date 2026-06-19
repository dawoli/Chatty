#include <iostream>
using namespace std;
int n,k,a[500005];ain(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(k==1){
            if(a[i]==1)ans++;
            else if(a[i]!=a[i+1]){
                ans++;
                i++;
            }
        }
        if(k==0){
            if(a[i]==0)ans++;
            else if(a[i]==a[i+1]){
                ans++;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
