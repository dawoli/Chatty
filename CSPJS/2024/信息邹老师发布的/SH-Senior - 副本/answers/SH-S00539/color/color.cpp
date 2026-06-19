#include<bits/stdc++.h>
using namespace std;
int n,a[200005],T,ans=0;
// 0 nb 1 nr
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<((1<<n));i++){
            int sum=0;
            int las1=-1,las0=-1;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) {
                    if(las1!=-1)sum+=a[j]*(a[j]==a[las1]);
                    las1=j;
                }
                else {
                    if(las0!=-1)sum+=a[j]*(a[j]==a[las0]);
                    las0=j;
                }
            }
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}
