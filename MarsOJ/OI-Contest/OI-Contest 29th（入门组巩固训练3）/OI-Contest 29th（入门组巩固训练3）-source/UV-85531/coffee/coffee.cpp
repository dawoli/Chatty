#include<bits/stdc++.h>
using namespace std;
int t,n,m,cnt;string s;
long long ans;
int ton[11];
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>t;
    while(t--){
        cnt=0,ans=0;
        for(int i=1;i<=5;i++){
            ton[i]=0;
            for(int j=1;j<=8;j++){
                cin>>s;
                if(s=="math"){
                    ton[i]++;
                }
            }
            cnt+=ton[i];
        }
        cin>>n>>m;
        ans+=cnt*(n/7);
        for(int i=1,j=m;i<=n%7;i++){
            ans+=ton[j];
            j=(j+1)%7;
        }
        cout<<ans<<endl;
    }
    return 0;
}
