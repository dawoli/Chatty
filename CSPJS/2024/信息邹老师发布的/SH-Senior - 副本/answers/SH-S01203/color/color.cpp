#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200009];
int cor(int num,int k){
    return (num>>(k-1))&1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int kk=1;kk<=t;kk++){
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(long long i=0;i<=(1<<(n-1));i++){
            int sum=0;
            for(int j=1;j<=n;j++){
                for(int k=j-1;k>=1;k--){
                    if(cor(i<<1,k)==cor(i<<1,j)){
                        if(a[j]==a[k]){
                            sum+=a[j];
                            break;
                        }
                        else break;
                    }
                }
            }
            ans=max(ans,sum);
            // if(ans==30){
            //     while(i){
            //         cout<<(i&1)<<" ";
            //         i>>=1;
            //     }
            // }
        }
        cout<<ans<<endl;
    }
    return 0;
}